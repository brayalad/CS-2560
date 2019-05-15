//MainMenu.h
#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Engine.h"

/**
 * MainMenu class represents the main menu state of the game. Whenever
 * the program is started, the user is presented with the Main menu. While
 * in this state, the user can choose to begin a new game turn. If so, a new
 * game state will be created and added to the stack
 */
class MainMenu : public GameState
{
private:
    /**
     * shared pointer to outside game classes
     */
    GameData gameData;

    /**
     * Sprite representing the background
     */
    sf::Sprite background;
    /**
     * Sprite representng the play button
     */
    sf::Sprite playButton;

    /**
     * Text representing the title
     */
    sf::Text title;

public:
    /**
     * Constructor that sets up the window for the main menu.
     * @param _gameData shared pointer to the outside game classes
     */
    explicit MainMenu(GameData _gameData);

    /**
     * Prepare the class to be displayed
     */
    void initialize() override;
    /**
     * Handle user input while in this state. For this state,
     * it checks if the user has clicked on the play button
     */
    void handleInput() override;
    /**
     * Draws the different parts of the class to the screen
     */
    void draw() override;
};
