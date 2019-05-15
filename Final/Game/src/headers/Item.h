//Items.h
#pragma once

#include <SFML/Graphics.hpp>
#include "Engine.h"
#include <vector>

/**
 * The item class represents an item in the game. In this game it is either
 * a an asteroid or a coin. This class is responsible for the items in the game.
 * This means moving them from the right side of the screen to the left and updating
 * the screen accordingling
 */
class Item
{
private:
    /**
     * Shared pointer to other classes of the program
     */
    GameData gameData;
    /**
     * Vector holding the asteroid sprites that are currently
     * displayed on the screen
     */
    std::vector<sf::Sprite> asteroids;
    /**
     * Vector holding the coin sprites that are currently displayed
     * on the screen
     */
    std::vector<sf::Sprite> coins;

public:
    /**
     * Constuctor for the Items class. Sets up the different
     * spirtes with assets from the asset manager class
     * @param _gameData the shared pointer to ouside game classes
     */
    explicit Item(GameData _gameData);

    /**
     * Method creates new asteroid sprites and adds them to the asteroid vector
     */
    void spawnAsteroid();
    /**
     * Creates new coin sprites and adds them to the coin vector
     */
    void spawnCoin();
    /**
     * Moves the items in both vectors from right to left
     * @param frameRate rate at which to move the items
     */
    void moveItems(float frameRate);
    /**
     * Displays the contents and changes to the game window
     */
    void drawItems();

    /**
     * Get method for the asteroids on the screen
     * @return vector of asteroid sprites on the screen
     */
    const std::vector<sf::Sprite>& getAsteroids() const;
    /**
     * Get method for the coins on the screen
     * @return vector of coin sprites on the screen
     */
    std::vector<sf::Sprite>& getCoins();
};
