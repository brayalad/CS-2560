//Game.h
#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Engine.h"
#include "Item.h"
#include "Collision.h"
#include "SpaceShip.h"
#include "ScoreKeeper.h"

class Game : public GameState
{
private:
    GameData gameData;

    sf::Sprite background;

    Item *item;
    SpaceShip *spaceShip;
    ScoreKeeper *scoreDisplay;

    sf::Clock gameClock;
    sf::Clock asteroidClock;
    sf::Clock coinClock;

    std::string gameState;
    int asteroidFrequency;
    int coinFrequency;
    int score;

public:
    explicit Game(GameData _gameData);

    void initialize() override;
    void handleInput() override;
    void update(float frameRate) override;
    void draw() override;
};
