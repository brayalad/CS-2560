//GameStateManager.cpp
#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
    this->isAdding = false;
    this->isRemoving = false;
    this->isReplacing = false;
}


void GameStateManager::addState(State _newState, bool _isReplacing)
{
    this->isAdding = true;
    this->isReplacing = _isReplacing;

    this->newState = std::move(_newState);
}

void GameStateManager::processStateChanges()
{
    if (this->isRemoving && !this->gameStates.empty())
    {
        this->gameStates.pop();

        this->isRemoving = false;
    }

    if (this->isAdding)
    {
        if (!this->gameStates.empty())
        {
            if (this->isReplacing)
            {
                this->gameStates.pop();
            }
        }

        this->gameStates.push(std::move(this->newState));
        this->gameStates.top()->initialize();
        this->isAdding = false;
    }
}

const State& GameStateManager::getActiveState() const
{
    return this->gameStates.top();
}
