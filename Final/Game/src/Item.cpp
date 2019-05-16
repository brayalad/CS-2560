/**
 * Item.cpp
 */
#include "Item.h"
#include "GlobalVariables.h"

Item::Item(GameData _gameData)
{
    this->gameData = std::move(_gameData);
}

void Item::spawnAsteroid()
{
    sf::Sprite asteroid;
    asteroid.setTexture(this->gameData->assets.getTexture("Asteroid 1")); //set asteroid texture

    //Compute a random Y position for the asteroid
    float randomYPosition = float(rand() % this->gameData->window.getSize().y - asteroid.getTexture()->getSize().y);

    asteroid.setPosition(this->gameData->window.getSize().x, randomYPosition);

    asteroids.push_back(asteroid); // Add the asteroid sprite to vector of asteroids

}

void Item::spawnCoin()
{
    sf::Sprite sprite(this->gameData->assets.getTexture("Coin"));

    //Scale down coing sprite by half
    sprite.setScale(0.5f, 0.5f);

    //Calculate random y position for coin
    float y = float(rand() % this->gameData->window.getSize().y - sprite.getTexture()->getSize().y);

    sprite.setPosition(this->gameData->window.getSize().x,y);

    coins.push_back(sprite); //add coin sprite to vector of coins

}

void Item::moveItems(float frameRate)
{
    //Moved every asteroid in the game from right to left
    for ( int i = 0; i < asteroids.size(); i++)
    {
        /*
         * If the asteroid moves off screen, it is deleted from the vector
         * this is done to free up space since asteroids off the screen are
         * no longer needed
         */
        if (asteroids.at(i).getPosition().x < 0 - asteroids.at(i).getLocalBounds().width)
        {
            asteroids.erase( asteroids.begin( ) + i );
        }
        else //Moves the asteroids to the left
        {
            float movement = ITEM_MOVEMENT_SPEED * frameRate;

            asteroids.at(i).move(-movement, 0);
        }
    }

    //Moves every coin from left to right
    for (int i = 0; i < coins.size(); i++)
    {
        //Erases coin if position is off screen
        if (coins.at(i).getPosition().x < 0 - coins.at(i).getLocalBounds().width)
        {
            coins.erase(coins.begin() + i);
        }
        else
        {
            float movement = ITEM_MOVEMENT_SPEED * frameRate;

            coins.at(i).move(-movement, 0);
        }
    }
}

//Draws every asteroid and coin in their respective vectors
void Item::drawItems()
{
    for (const auto& asteroid : asteroids)
    {
        this->gameData->window.draw(asteroid);
    }
    for (const auto& coin: coins)
    {
        this->gameData->window.draw(coin);
    }
}

//Returns the vector of all asteroids on the screen
const std::vector<sf::Sprite>& Item::getAsteroids() const
{
    return asteroids;
}

//Returns a reference to the vector of all the coins. Can be modified outside of the class
std::vector<sf::Sprite>& Item::getCoins()
{
    return coins;
}
