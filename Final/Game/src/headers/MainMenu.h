//MainMenu.h
#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Engine.h"

class MainMenu : public GameState
{
private:
    GameData gameData;

    sf::Sprite background;
    sf::Sprite playButton;

    sf::Text title;

public:
    explicit MainMenu(GameData _gameData);

    void initialize() override;
    void handleInput() override;
    void draw() override;
};
