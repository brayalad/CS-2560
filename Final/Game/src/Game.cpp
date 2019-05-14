//Game.cpp
#include "GlobalVariables.h"
#include "Game.h"
#include "GameOver.h"

Game::Game(GameData _gameData)
{
    this->gameData = std::move(_gameData);
    this->item = nullptr;
    this->spaceShip = nullptr;
    this->scoreDisplay = nullptr;
    this->score = 0;
    this->gameState = "Ready";
    this->asteroidFrequency = ITEM_SPAWN_FREQUENCY;
    this->coinFrequency = ITEM_SPAWN_FREQUENCY;
}


void Game::initialize()
{
    item = new Item(gameData);
    spaceShip = new SpaceShip(gameData);
    scoreDisplay = new ScoreKeeper(gameData);

    background.setTexture(this->gameData->assets.getTexture("Game Background"));

    score = 0;
    scoreDisplay->updateScore(score);

    gameState = "Ready";
}

void Game::handleInput()
{
    sf::Event event{};

    while (this->gameData->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            this->gameData->window.close();
        }

        if (event.type == sf::Event::KeyPressed)
        {
            if (gameState != "GameOver")
            {
                gameState = "Playing";
            }
        }

        if (gameState == "Playing")
        {
            if (UserInput::isKeyboardClicked(sf::Keyboard::Up))
            {
                spaceShip->move('U');
            }
            if (UserInput::isKeyboardClicked(sf::Keyboard::Down))
            {
                spaceShip->move('D');
            }
            if(UserInput::isKeyboardClicked(sf::Keyboard::Right))
            {
                spaceShip->move('R');
            }
            if(event.type == sf::Event::KeyReleased)
            {
                spaceShip->move('S');
            }
        }

    }
}

void Game::update(float frameRate)
{
    if (gameState == "Playing")
    {
        item->moveItems(frameRate);

        if (asteroidClock.getElapsedTime().asSeconds() > asteroidFrequency)
        {
            item->spawnAsteroid();

            asteroidFrequency = (rand() % (int)(ITEM_SPAWN_FREQUENCY * 2.5)) + (int)ITEM_SPAWN_FREQUENCY;
            asteroidClock.restart();
        }

        if (coinClock.getElapsedTime().asSeconds() > coinFrequency)
        {
            item->spawnCoin();

            coinFrequency = (rand() % (int)(ITEM_SPAWN_FREQUENCY * 1.5)) + (int)ITEM_SPAWN_FREQUENCY;
            coinClock.restart();
        }


        spaceShip->update(frameRate);

        std::vector<sf::Sprite> asteroids = item->getAsteroids();

        for (const auto& asteroid : asteroids)
        {
            if (Collision::checkSpriteCollision(spaceShip->getSpaceShip(), 0.625f, asteroid, 1.0f))
            {
                gameState = "GameOver";

                gameClock.restart();
            }
        }

        if (gameState == "Playing")
        {
            std::vector<sf::Sprite>& coins = item->getCoins();

            for (int i = 0; i < coins.size(); i++)
            {
                if (Collision::checkSpriteCollision(spaceShip->getSpaceShip(), 0.625f, coins.at(i), 1.0f))
                {
                    score++;

                    scoreDisplay->updateScore(score);

                    coins.erase(coins.begin() + i);
                }
            }
        }
    }

    if (gameState == "GameOver")
    {
        if (gameClock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
        {
            this->gameData->gameManager.addState(State(new GameOver(gameData, score)), true);
        }
    }
}

void Game::draw()
{
    this->gameData->window.clear( sf::Color::Black );

    this->gameData->window.draw(this->background);

    item->drawItems();
    spaceShip->draw();

    scoreDisplay->draw();

    this->gameData->window.display();
}
