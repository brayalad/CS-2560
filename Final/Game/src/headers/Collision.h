//Collison.h
#pragma once

#include <SFML/Graphics.hpp>

/**
 * The Collision class is in charge of checking for a collision
 * between two sprites. More specifically checking if the spaceship
 * sprite has intersected with another item in the game, either a
 * coin or an asteroid. Contains only one static method, meaning it
 * does not have to me instantiated and can be used throughout the game.
 */
class Collision
{
public:
    /**
     * Default constructor
     */
    Collision()= default;
    /**
     * Default deconstructor
     */
    ~Collision()= default;

    /**
     * Static method that checks if two sprites have intersected
     * @param sprite1 The first sprite being checked, in the game it is the Spaceship sprite
     * @param scale1 The value at which to scale the first sprite
     * @param sprite2 The second sprite being checked, in the game it is either a coin or asteroid sprite
     * @param scale2 The value at which to scale the second sprite
     * @return If the two sprites intersected based on their global bounds.
     */
    static bool checkSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2);
};
