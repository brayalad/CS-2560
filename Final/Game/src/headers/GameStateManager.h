//GameStateManager.h
#pragma once

#include <memory>
#include <stack>
#include "GameState.h"

/**
 * Defining a unique pointer to each game state.
 * Each state is different and has its own different data.
 * Each instance of the same type of state will not be the same
 * either, therefore we must treat every instance of a GameState
 * as its own.
 */
typedef std::unique_ptr<GameState> State;

/**
 * The GameStateManager is responsible for managing the different states
 * of the game. It does this by adding and removing the different states on
 * a stack. Once a state is finished, it is removed. In this game, the game
 * begins with the MainMenu state. Once the user decides to play a game, a new
 * Game state is added to the stack. Once that game is over, a game over state is
 * added to the stack. Once the user decides to begin a new game, the game over
 * state ends and is removed from that stack, then a new game state is presented
 */
class GameStateManager
{

private:
    /**
     * The stack which holds the different states of the game
     */
    std::stack<State> gameStates;
    /**
     * The state that is to be added to the game and the stack
     */
    State newState;

    /**
     * boolean flag to check if a state is being removed
     */
    bool isRemoving;
    /**
     * boolean flag to check if a state is being added
     */
    bool isAdding;
    /**
     * boolean flag to check if a state is being replaced
     */
    bool isReplacing;

public:
    /**
     * Default Constructor
     */
    GameStateManager();
    /**
     * Default Deconstructor
     */
    ~GameStateManager() = default;

    /**
     * Method adds a new state to the stack, the top of the stack is what
     * will be displayed onto the window
     * @param _newState New state to be added
     * @param _isReplacing boolean flag to check if state is being replaced
     */
    void addState(State _newState, bool _isReplacing = true);
    /**
     * Process a change in the games overall state. Once there is a change
     * to the stack, the top of the stack is displayed to the window
     */
    void processStateChanges();

    /**
     * Get method for the current state of the whole program at the time
     * of being called
     * @return The current state of the game
     */
    const State& getActiveState() const;

};
