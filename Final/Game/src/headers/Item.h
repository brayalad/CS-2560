//Items.h
#pragma once

#include <SFML/Graphics.hpp>
#include "Engine.h"
#include <vector>

class Item
{
private:
    GameData gameData;
    std::vector<sf::Sprite> asteroids;
    std::vector<sf::Sprite> coins;

public:
    explicit Item(GameData _gameData);

    void spawnAsteroid();
    void spawnCoin();
    void moveItems(float frameRate);
    void drawItems();

    const std::vector<sf::Sprite>& getAsteroids() const;
    std::vector<sf::Sprite>& getCoins();
};
