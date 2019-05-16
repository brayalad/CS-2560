/**
 * GameStateManager.cpp
 */
#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
    this->isAdding = false;
    this->isRemoving = false;
    this->isReplacing = false;
}

//Adds new state of the game into the stack
void GameStateManager::addState(State _newState, bool _isReplacing)
{
    this->isAdding = true;
    this->isReplacing = _isReplacing;

    this->newState = std::move(_newState);//new state that will be added
}

//Processes any changes in the games state
void GameStateManager::processStateChanges()
{
    //If a state is being removed, check if stack is not empty then remove top
    if (this->isRemoving && !this->gameStates.empty())
    {
        this->gameStates.pop();

        this->isRemoving = false;
    }

    //If state is being added, add the new state to the stack
    if (this->isAdding)
    {
        if (!this->gameStates.empty())
        {
            //If new state is replcing a state in the stack, pop the top and place new state
            if (this->isReplacing)
            {
                this->gameStates.pop();
            }
        }

        this->gameStates.push(std::move(this->newState));
        this->gameStates.top()->initialize(); //Initializes the top of the stack in order to be displayed
        this->isAdding = false;
    }
}

//Returns the top of the stack, which is the games current active state
const State& GameStateManager::getActiveState() const
{
    return this->gameStates.top();
}
