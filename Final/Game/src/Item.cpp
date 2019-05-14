//Item.cpp
#include "Item.h"
#include "GlobalVariables.h"

Item::Item(GameData _gameData)
{
    this->gameData = std::move(_gameData);
}

void Item::spawnAsteroid()
{
    sf::Sprite asteroid;
    asteroid.setTexture(this->gameData->assets.getTexture("Asteroid 1"));

    float randomYPosition = float(rand() % this->gameData->window.getSize().y - asteroid.getTexture()->getSize().y);

    asteroid.setPosition(this->gameData->window.getSize().x, randomYPosition);

    asteroids.push_back(asteroid);

}

void Item::spawnCoin()
{
    sf::Sprite sprite(this->gameData->assets.getTexture("Coin"));

    sprite.setScale(0.5f, 0.5f);

    float y = float(rand() % this->gameData->window.getSize().y - sprite.getTexture()->getSize().y);

    sprite.setPosition(this->gameData->window.getSize().x,y);

    coins.push_back(sprite);

}

void Item::moveItems(float frameRate)
{
    for ( int i = 0; i < asteroids.size(); i++)
    {
        if (asteroids.at(i).getPosition().x < 0 - asteroids.at(i).getLocalBounds().width)
        {
            asteroids.erase( asteroids.begin( ) + i );
        }
        else
        {
            float movement = ITEM_MOVEMENT_SPEED * frameRate;

            asteroids.at(i).move(-movement, 0);
        }
    }

    for (int i = 0; i < coins.size(); i++)
    {
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

const std::vector<sf::Sprite>& Item::getAsteroids() const
{
    return asteroids;
}

std::vector<sf::Sprite>& Item::getCoins()
{
    return coins;
}
