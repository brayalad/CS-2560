//GameState.h
#pragma once

/**
 * GameState class is meant to act more as a template or interface.
 * There are three states that the program can be at any time. The user
 * can be in the main menu, playing a game turn, or be in a game over state.
 * This class acts as a blueprint to what states of the game are able to do.
 */
class GameState
{
public:
    /**
     * Initializes what is needed and sets up the enviorment for the state
     * This includes things like loading and setting assets such as textures
     * and fonts
     */
    virtual void initialize(){};
    /**
     * Handle any user input as appropriate based on the state
     */
    virtual void handleInput(){};
    /**
     * Update the components of the current states however needed
     * based on the types of events.
     * @param frameRate The rate at which the components are updated
     */
    virtual void update(float frameRate){};
    /**
     * Display its components to the window
     */
    virtual void draw(){};

};
