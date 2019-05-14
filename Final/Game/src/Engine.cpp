//Engine.cpp
#include "Engine.h"
#include "MainMenu.h"
#include <cstdlib>
#include <ctime>


Engine::Engine(int width, int height, const std::string& title)
{
    srand(time(nullptr));

    this->data->assets.loadFont("Score Font", SCORE_FONT_FILEPATH);
    this->data->assets.loadTexture("Play Button", PLAY_BUTTON_FILEPATH);
    this->data->assets.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
    this->data->assets.loadTexture("Space Ship", SPACESHIP_FILEPATH);
    this->data->assets.loadTexture("Asteroid 1", ASTEROID_1_FILEPATH);
    this->data->assets.loadTexture("Coin", COIN_FILEPATH);

    data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    data->gameManager.addState(State(new MainMenu(data)));
}

void Engine::run()
{
    float newTime;
    float frameTime;

    float currentTime = this->clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    while (this->data->window.isOpen())
    {
        this->data->gameManager.processStateChanges();

        newTime = this->clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;

        if (frameTime > 0.25f)
        {
            frameTime = 0.25f;
        }

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= frameRate)
        {
            this->data->gameManager.getActiveState()->handleInput();
            this->data->gameManager.getActiveState()->update(frameRate);

            accumulator -= frameRate;
        }

        this->data->gameManager.getActiveState()->draw();
    }
}
