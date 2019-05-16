/**
 * Colission.cpp
 */
#include "Collision.h"

bool Collision::checkSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2)
{
    //Scales both sprites
    sprite1.setScale(scale1, scale1);
    sprite2.setScale(scale2, scale2);

    //Used to get the invisible rectangle box round the sprites
    sf::Rect<float> rect1 = sprite1.getGlobalBounds();
    sf::Rect<float> rect2 = sprite2.getGlobalBounds();

    return rect1.intersects(rect2); //True if the sprites rect (invisible boxes) intersect
}
