//Engine.h
#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "GlobalVariables.h"
#include "GameStateManager.h"
#include "AssetManager.h"
#include "UserInput.h"

/**
 * Structure holding the different components of the game
 * Holds instances of each one of the different classes used
 * throught the game and groups them together so that they
 * can be easilly passed along to different classes of the game
 */
struct GameComponents
{
    /**
     * The GameStateManager is in charge of handling and displaying
     * each of the 3 different states in the game.
     */
    GameStateManager gameManager;
    /**
     * The RenderWindow is the window in which the game will be run and
     * displayed in.
     */
    sf::RenderWindow window;
    /**
     * The AssetManager holds all the different assets that are needed by the game.
     * Stores these assets in a map contained by the class itself
     */
    AssetManager assets;
};

/**
 * Defining a shared_ptr of the GameComponents struct as its
 * own type. This allows the different game components to me
 * encapsulated into one defined type
 */
typedef std::shared_ptr<GameComponents> GameData;

/**
 * The Engine class is in charge of running the game. It contains
 * the continous loop that runs the game and also checks for events
 * and either deals with those events or calls on another class in the
 * game to handle if neeeded;
 */
class Engine
{
private:

    /**
     * The frame rate at which the game will run.
     * Setting this avoids different rendering speeds
     * based on where game is being ran.
     */
    const float frameRate = 1.0f / 60.0f;
    /**
     * Clock keeping track of the time that has passed.
     * Used to control framerate if needed.
     */
    sf::Clock clock;

    /**
     * Instance of the typedef GameData that is a shared pointer that
     * points the a struct containing all needed class instances. This
     * makes a shared pointer and that pointer is passed around the game,
     * allowing those specific encapsulated game components to be accessed.
     */
    GameData data = std::make_shared<GameComponents>();

public:
    /**
     * The Engine class constructor is in charge of setting the enviorment up for
     * the game. It creates the game window and loads the needed assets to the AssetManager
     * instance contained within the GameData typedef.
     * @param width The width value of the window.
     * @param height The height value of the window.
     * @param title The title that will be displayed on the window.
     */
    Engine(int width, int height, const std::string& title);

    /**
     * The run method is the game loop. It begings the game by beggining
     * a loop that will listen for events throught the game. Whenever an event
     * is triggered, it will deal with the event by passing it on to the class
     * responsible to handle it
     */
    void run();

};

