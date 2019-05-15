//GameOver.h
#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Engine.h"

/**
 * The GameOver class is responsible for the state if the game once the current game
 * turn has ended. It is dervived from the GameState class making it one if the possible
 * states that the program can be aat any time. It is repsonsible for displaying the score
 * out to the user and allowing them to play another game.
 */
class GameOver : public GameState
{
private:
    /**
     * Shared pointer to the games managing classes
     */
    GameData gameData;

    /**
     * Sprite representing the background
     */
    sf::Sprite background;
    /**
     * Sprite representing the replay button
     */
    sf::Sprite retryButton;

    /**
     * Text representing the title for the state
     */
    sf::Text gameOverTitle;
    /**
     * Text representing the score of the previous turn
     */
    sf::Text scoreText;

    /**
     * The score of the previous game turn
     */
    int score;

public:
    /**
     * Constructor takes in shared pointer to other game classes as
     * well as the score of the previous game turn. Sets the classes
     * score to the score passed to it.
     * @param _gameData shared pointer to other classes
     * @param _score The value to display
     */
    GameOver(GameData _gameData, int _score);

    /**
     * Sets up the window to display the game score and button.
     * Loads all needed textures and fonts from the asset manager
     * withing the gameData shared pointer
     */
    void initialize() override;

    /**
     * Handles user input while in this state.
     * Checks to see if the user clicks on the retry button.
     * If so, a new Game is created.
     */
    void handleInput() override;
    /**
     * Draws the different parts of the game over state and screen to the window.
     */
    void draw() override;
};











