//GameOver.h
#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Engine.h"

class GameOver : public GameState
{
private:
    GameData gameData;

    sf::Sprite background;
    sf::Sprite retryButton;

    sf::Text gameOverTitle;
    sf::Text scoreText;

    int score;

public:
    GameOver(GameData _gameData, int _score);

    void initialize() override;

    void handleInput() override;
    void draw() override;
};











