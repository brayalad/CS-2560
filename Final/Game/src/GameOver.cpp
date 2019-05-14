//GameOver.cpp
#include "GlobalVariables.h"
#include "GameOver.h"
#include "Game.h"


GameOver::GameOver(GameData _gameData, int _score)
{
    this->gameData = std::move(_gameData);
    this->score = _score;
}

void GameOver::initialize()
{
    background.setTexture(this->gameData->assets.getTexture("Game Background"));
    retryButton.setTexture(this->gameData->assets.getTexture("Play Button"));

    retryButton.setOrigin(sf::Vector2f(retryButton.getGlobalBounds().width / 2, retryButton.getGlobalBounds().height / 2));
    retryButton.setPosition(sf::Vector2f(gameData->window.getSize().x / 2, gameData->window.getSize().y / 1.5f));

    gameOverTitle.setFont(this->gameData->assets.getFont("Score Font"));
    gameOverTitle.setString("GAME OVER");
    gameOverTitle.setCharacterSize(128);
    gameOverTitle.setFillColor(sf::Color::White);
    gameOverTitle.setOrigin(sf::Vector2f(gameOverTitle.getGlobalBounds().width / 2, gameOverTitle.getGlobalBounds().height / 2));
    gameOverTitle.setPosition(sf::Vector2f(gameData->window.getSize().x / 2, gameData->window.getSize().y / 10));

    scoreText.setFont(this->gameData->assets.getFont("Score Font"));
    scoreText.setString("Score: " + std::to_string(score));
    scoreText.setCharacterSize(56);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setOrigin(sf::Vector2f(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2));
    scoreText.setPosition(sf::Vector2f(gameData->window.getSize().x / 2, gameData->window.getSize().y / 3));


}

void GameOver::handleInput()
{
    sf::Event event{};

    while (this->gameData->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->gameData->window.close();
        }

        if (UserInput::isSpriteClicked(this->retryButton, sf::Mouse::Left, this->gameData->window))
        {
            this->gameData->gameManager.addState(State(new Game(gameData)), true);
        }
    }
}

void GameOver::draw()
{
    this->gameData->window.clear(sf::Color::Red);

    this->gameData->window.draw(this->background);

    gameData->window.draw(gameOverTitle);
    gameData->window.draw(retryButton);
    gameData->window.draw(scoreText);


    this->gameData->window.display();
}

