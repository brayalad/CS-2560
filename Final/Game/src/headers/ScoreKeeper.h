//ScoreKeeper.h
#pragma once

#include <SFML/Graphics.hpp>
#include "GlobalVariables.h"
#include "Engine.h"

/**
 * Class responsible for keeping score of the current game turn
 */
class ScoreKeeper
{
private:
    /**
     * Shared pointer to other classes in program
     */
    GameData gameData;

    /**
     * Text representing the score of the current game turn
     */
    sf::Text scoreText;

public:
    /**
     * Default constructor
     * @param _gameData shared pointer to other classes in program
     */
    explicit ScoreKeeper(GameData _gameData);
    /**
     * Default deconstructor
     */
    ~ScoreKeeper() = default;

    /**
     * Draws the score onto the screen.
     */
    void draw();
    /**
     * Updates the current score when called
     * @param score The new score of the game
     */
    void updateScore(int score);
};
