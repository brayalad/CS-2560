/**
 * ScoreKeeper.cpp
 */
#include "ScoreKeeper.h"

#include <string>

ScoreKeeper::ScoreKeeper(GameData _gameData)
{
    // Sets up the font, size, and position of the text that displays the score in the game
    this->gameData = std::move(_gameData);

    scoreText.setFont(this->gameData->assets.getFont("Score Font"));

    scoreText.setString("0");

    scoreText.setCharacterSize(128);

    scoreText.setFillColor(sf::Color::White);

    scoreText.setOrigin(sf::Vector2f(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2));

    scoreText.setPosition(sf::Vector2f(gameData->window.getSize().x / 2, gameData->window.getSize().y / 12));
}


void ScoreKeeper::draw()
{
    gameData->window.draw(scoreText); //Draws the score to the screen
}

void ScoreKeeper::updateScore(int score)
{
    scoreText.setString(std::to_string(score));//updates the score being kept
}
