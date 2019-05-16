/**
 * Game.cpp
 */
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
    /*
     * New game objects used during game state are created
     */
    item = new Item(gameData); //Items that will be spawned in the current game turn
    spaceShip = new SpaceShip(gameData); //The user's spaceship for the current game turn
    scoreDisplay = new ScoreKeeper(gameData); //Score keeper for current game turn

    //Sets current game turn background
    background.setTexture(this->gameData->assets.getTexture("Game Background"));

    score = 0;
    scoreDisplay->updateScore(score); //Sets up current game turn's score keeper to current score, which is 0

    gameState = "Ready";
}

void Game::handleInput()
{
    sf::Event event{};

    /*
     * Loop acts as event listener during the game turn
     * Handles user input based on its event type
     */
    while (this->gameData->window.pollEvent(event))
    {
        //Checks if window is closed
        if (event.type == sf::Event::Closed)
        {
            this->gameData->window.close();
        }

        //Checks if a key is pressed
        if (event.type == sf::Event::KeyPressed)
        {
            //If a key is pressed and game is not currently playing, game will start
            if (gameState != "GameOver")
            {
                gameState = "Playing";
            }
        }

        //Runs only if the game turn is actually playing a game at the moment
        if (gameState == "Playing")
        {
            if (UserInput::isKeyboardClicked(sf::Keyboard::Up))
            {
                spaceShip->move('U'); //Moves spaceship up
            }
            if (UserInput::isKeyboardClicked(sf::Keyboard::Down))
            {
                spaceShip->move('D'); //Moves spaceship down
            }
            if(UserInput::isKeyboardClicked(sf::Keyboard::Right))
            {
                spaceShip->move('R'); //Straigtens spaceship
            }
            if(event.type == sf::Event::KeyReleased)
            {
                spaceShip->move('S'); //Straigtens spaceship when key is released. Makes spaceship go straight by default
            }
        }

    }
}

void Game::update(float frameRate)
{
    //Code block responsible for moving the game items on the screen
    if (gameState == "Playing")
    {
        item->moveItems(frameRate); //calls on items to be moved according to framerate

        //Spawns an asteroid acording to the set spawn frequency
        if (asteroidClock.getElapsedTime().asSeconds() > asteroidFrequency)
        {
            item->spawnAsteroid();

            //Randomizes the asteroid spawn frequency
            asteroidFrequency = (rand() % (int)(ITEM_SPAWN_FREQUENCY * 2.5)) + (int)ITEM_SPAWN_FREQUENCY;
            asteroidClock.restart();
        }

        //Spawns a coin according to the set spawn frequency
        if (coinClock.getElapsedTime().asSeconds() > coinFrequency)
        {
            item->spawnCoin();

            //Randomizes the coin spawn frequency
            coinFrequency = (rand() % (int)(ITEM_SPAWN_FREQUENCY * 1.5)) + (int)ITEM_SPAWN_FREQUENCY;
            coinClock.restart();
        }


        spaceShip->update(frameRate); //Updates the spaceship

        //A vector containing all the asteroids currently on the screen
        std::vector<sf::Sprite> asteroids = item->getAsteroids();

        //Checks for every asteroid on the screen
        for (const auto& asteroid : asteroids)
        {
            //If the space ship and an asteroid intersect, game state is set to game over
            if (Collision::checkSpriteCollision(spaceShip->getSpaceShip(), 0.625f, asteroid, 1.0f))
            {
                gameState = "GameOver";

                gameClock.restart();
            }
        }

        if (gameState == "Playing")
        {
            /*
             * Vector reference to the vector that contains all the coins
             * on the screen. This is a reference to allow that specific
             * vector in memory to be changed
             */
            std::vector<sf::Sprite>& coins = item->getCoins();

            //Checks for every coin on the screen
            for (int i = 0; i < coins.size(); i++)
            {
                /*
                 * If spaceship and a coin intersect, the score is inremented and the
                 * score keeper class is updated with the new score. The coin that
                 * the space ship intersects with is removed from the vector, once
                 * Item class updates itself, the coin will be removed from the screen
                 */
                if (Collision::checkSpriteCollision(spaceShip->getSpaceShip(), 0.625f, coins.at(i), 1.0f))
                {
                    score++;

                    scoreDisplay->updateScore(score);

                    coins.erase(coins.begin() + i);
                }
            }
        }
    }

    // Once the game ends, a new game over state is added to the stack after a certain amount of time
    if (gameState == "GameOver")
    {
        if (gameClock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
        {
            this->gameData->gameManager.addState(State(new GameOver(gameData, score)), true);
        }
    }
}

//Draws the current state of the game state and all its parts
void Game::draw()
{
    //Clears and draws background first to make sure it is in the back
    this->gameData->window.clear( sf::Color::Black );
    this->gameData->window.draw(this->background);

    //Game parts are drawed after infront of the background
    item->drawItems();
    spaceShip->draw();
    scoreDisplay->draw();

    this->gameData->window.display();
}
