//SpaceShip.h
#pragma once

#include <SFML/Graphics.hpp>
#include "GlobalVariables.h"
#include "Engine.h"

class SpaceShip{

private:
    GameData gameData;
    sf::Sprite spaceShip;
    std::string spaceShipState;
    float rotation;


public:
    explicit SpaceShip(GameData _gameData);
    ~SpaceShip()= default;

    void draw();
    void update(float frameRate);
    void move(char direction);

    const sf::Sprite& getSpaceShip() const;


};
