//Engine.h
#pragma once

#include <SFML/Graphics.hpp>
#include "GlobalVariables.h"
#include <memory>
#include <string>
#include "GameStateManager.h"
#include "AssetManager.h"
#include "UserInput.h"


struct GameComponents
{
    GameStateManager gameManager;
    sf::RenderWindow window;
    AssetManager assets;
};

typedef std::shared_ptr<GameComponents> GameData;

class Engine
{
private:
    // This is the frame rate at which the game will run at;
    const float frameRate = 1.0f / 60.0f;
    sf::Clock clock;

    GameData data = std::make_shared<GameComponents>();

public:
    Engine(int width, int height, const std::string& title);
    void run();

};

