//GameStateManager.h
#pragma once

#include <memory>
#include <stack>
#include "GameState.h"

typedef std::unique_ptr<GameState> State;

class GameStateManager
{

private:
    std::stack<State> gameStates;
    State newState;

    bool isRemoving;
    bool isAdding;
    bool isReplacing;

public:
    GameStateManager();
    ~GameStateManager() = default;

    void addState(State _newState, bool _isReplacing = true);
    void processStateChanges();

    const State& getActiveState() const;

};
