//ScoreKeeper.h
#pragma once

#include <SFML/Graphics.hpp>

#include "GlobalVariables.h"
#include "Engine.h"

class ScoreKeeper
{
private:
    GameData gameData;

    sf::Text scoreText;

public:
    explicit ScoreKeeper(GameData _gameData);
    ~ScoreKeeper() = default;

    void draw();
    void updateScore(int score);
};
