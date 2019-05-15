//Game.h
#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Engine.h"
#include "Item.h"
#include "Collision.h"
#include "SpaceShip.h"
#include "ScoreKeeper.h"

/**
 * The Game class is responsible for the current game turn being
 * played. It is dervived from the GameState class, meaning that it
 * is one of the possible states that the video game can be in at any
 * given time. The state that this class represents is that state of the
 * game while the user is playing a turn. It is responsible for drawing
 * and updated the window during the game turn and handling any events
 * that it recieves.
 */
class Game : public GameState
{
private:
    /**
     * The shared GameData pointer that allows the Game class
     * accesses components that are responsible for managing the
     * game.
     */
    GameData gameData;

    /**
     * Sprite that represents that game's background
     */
    sf::Sprite background;

    /**
     * Pointer to an item in the game. In this game,
     * it can either be a coin or an asteroid
     */
    Item *item;
    /**
     * Pointer to the spaceship that the user controls
     * for the current game turn.
     */
    SpaceShip *spaceShip;
    /**
     * Pointer to the Score being kepped for the current
     * game turn.
     */
    ScoreKeeper *scoreDisplay;

    /**
     * Clock keeping track of the game time
     */
    sf::Clock gameClock;
    /**
     * Clock keeping track of the time between asteroid spawns
     */
    sf::Clock asteroidClock;
    /**
     * Clock keeping track of the time between coinSpawns
     */
    sf::Clock coinClock;

    /**
     * The state of the current game instance. NOT the whole programs state
     */
    std::string gameState;
    /**
     * Frequency at which asteroids will spawn.
     */
    int asteroidFrequency;
    /**
     * Frequency at which coins spawn.
     */
    int coinFrequency;
    /**
     * The score of the current game turn
     */
    int score;

public:
    /**
     * The Game constructor responsible for setting up the window
     * enviorment for the game turn.
     * @param _gameData The shared pointer to Manager classes
     */
    explicit Game(GameData _gameData);

    /**
     * Sets up the window for the current game turn to begin
     */
    void initialize() override;
    /**
     * Handles any user input recieved by the UserInput class
     */
    void handleInput() override;
    /**
     * Updates the different parts of the window whenever there are changes.
     * This means updating positions of the spaceship and space items
     * @param frameRate The rate at which to update changes
     */
    void update(float frameRate) override;
    /**
     * Draws changes made to the window and displays them, and any
     * other class needed to the screen.
     */
    void draw() override;
};
