//SpaceShip.h
#pragma once

#include <SFML/Graphics.hpp>
#include "GlobalVariables.h"
#include "Engine.h"

/**
 * SpaceShip class is the class the user controls.
 * The user can move it up or down as well as rotate
 * the sprite.
 */
class SpaceShip{

private:
    /**
     * Shared pointer to other classes
     */
    GameData gameData;
    /**
     * Sprite representing the spaceship
     */
    sf::Sprite spaceShip;
    /**
     * The current state of the spaceship
     */
    std::string spaceShipState;
    /**
     * The spaceships rotation value
     */
    float rotation;


public:
    /**
     * Spaceship constructor
     * @param _gameData shared pointer to other classes
     */
    explicit SpaceShip(GameData _gameData);
    /**
     * Default constructor
     */
    ~SpaceShip()= default;

    /**
     * Draws the spacehip in its current state
     */
    void draw();
    /**
     * Updates the state of the spaceship based on user input
     * @param frameRate
     */
    void update(float frameRate);
    /**
     * Moves the spaceship vertically
     * @param direction The direction in which to move
     */
    void move(char direction);

    /**
     * Get method for the spaceship
     * @return the spaceship sprite
     */
    const sf::Sprite& getSpaceShip() const;


};
