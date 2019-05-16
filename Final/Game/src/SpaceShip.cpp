/**
 * SpaceShip.cpp
 */
#include "SpaceShip.h"


SpaceShip::SpaceShip(GameData _gameData)
{
    //Sets up the spaceship with its texture, initial position, and intial state and rotation
    this->gameData = std::move(_gameData);

    spaceShip.setTexture(this->gameData->assets.getTexture("Space Ship"));

    spaceShip.setPosition((gameData->window.getSize().x / 4) - (spaceShip.getGlobalBounds().width / 2), (gameData->window.getSize().y / 2) - (spaceShip.getGlobalBounds().height / 2));

    spaceShipState = "Flying_Still";

    sf::Vector2f origin = sf::Vector2f(spaceShip.getGlobalBounds().width / 2, spaceShip.getGlobalBounds().height / 2);

    spaceShip.setOrigin(origin);

    rotation = 0;
}


void SpaceShip::draw()
{
    gameData->window.draw(spaceShip); //Draws spaceship to screen
}

void SpaceShip::update(float frameRate)
{
    //Rotates and moves spaceship down
    if (spaceShipState == "Flying_Down")
    {
        spaceShip.move(0, SPACESHIP_FLYING_SPEED * frameRate);

        rotation += SPACESHIP_ROTATION_SPEED * frameRate;

        if (rotation > 25.0f)
        {
            rotation = 25.0f;
        }

        spaceShip.setRotation(rotation);
    }
    //Rotates and moves space ship up
    else if (spaceShipState == "Flying_Up")
    {
        spaceShip.move(0, -SPACESHIP_FLYING_SPEED * frameRate);

        rotation -= SPACESHIP_ROTATION_SPEED * frameRate;

        if (rotation < -25.0f)
        {
            rotation = -25.0f;
        }

        spaceShip.setRotation(rotation);
    }
    //Rotates spaceship straight and makes it still
    else if(spaceShipState == "Flying_Still")
    {
        spaceShip.move(0,0);

        if(rotation < 0.0f)
        {
            rotation += SPACESHIP_ROTATION_SPEED * frameRate;
        }

        if(rotation > 0.0f)
        {
            rotation -= SPACESHIP_ROTATION_SPEED * frameRate;
        }

        spaceShip.setRotation(rotation);
    }

}

//Move the space ship depending on the direction chosen
void SpaceShip::move(char direction)
{
    if(direction == 'U')
    {
        spaceShipState = "Flying_Up";
    }
    else if(direction == 'D')
    {
        spaceShipState = "Flying_Down";
    }
    else
    {
        spaceShipState = "Flying_Still";
    }
}


//returns the spacehship sprite
const sf::Sprite& SpaceShip::getSpaceShip() const
{
    return spaceShip;
}
