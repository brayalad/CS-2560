/**
 * Engine.cpp
 */
#include "Engine.h"
#include "MainMenu.h"
#include <cstdlib>
#include <ctime>


Engine::Engine(int width, int height, const std::string& title)
{
    //Seeding random number generator to generate the game items
    srand(time(nullptr));

    //Loads all textures and fonts need by the game
    this->data->assets.loadFont("Score Font", SCORE_FONT_FILEPATH);
    this->data->assets.loadTexture("Play Button", PLAY_BUTTON_FILEPATH);
    this->data->assets.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
    this->data->assets.loadTexture("Space Ship", SPACESHIP_FILEPATH);
    this->data->assets.loadTexture("Asteroid 1", ASTEROID_1_FILEPATH);
    this->data->assets.loadTexture("Coin", COIN_FILEPATH);

    //Creates the game window sized to the passed parameters
    data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

    //Adds a main menu state to the stack, displaying it to the user
    data->gameManager.addState(State(new MainMenu(data)));
}

void Engine::run()
{
    //Used to calculate and regulate the games frame rate
    float newTime;
    float frameTime;
    float currentTime = this->clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    //Main game loop. Runs while the game window is opened
    while (this->data->window.isOpen())
    {
        //Calls on game state manager  to process any change in game state
        this->data->gameManager.processStateChanges();

        newTime = this->clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;

        //Does not allow game framerate to pass a limit
        if (frameTime > 0.25f)
        {
            frameTime = 0.25f;
        }

        currentTime = newTime;
        accumulator += frameTime;

        /*
         * This loop calls on the game state manager to handle
         * the input and update the current active state.
         * Each state handles its input differently
         */
        while (accumulator >= frameRate)
        {
            this->data->gameManager.getActiveState()->handleInput(); //Games current state handles user input
            this->data->gameManager.getActiveState()->update(frameRate); //Games current state updates itself

            accumulator -= frameRate;
        }

        this->data->gameManager.getActiveState()->draw(); //Current State draws its updated changes to the screen
    }
}
