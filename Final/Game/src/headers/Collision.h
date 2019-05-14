//Collison.h
#pragma once

#include <SFML/Graphics.hpp>


class Collision
{
public:
    Collision()= default;
    ~Collision()= default;

    static bool checkSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2);
};
