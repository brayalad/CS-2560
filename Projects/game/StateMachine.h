#pragma once

#include <memory>
#include <stack>

#include "State.h"

namespace gameEngine {

	typedef std::unique_ptr<State> StateRef;

	class StateMachine {

	private:
		std::stack<StateRef> states;
		StateRef newState;

		bool isRemoving;
		bool isAdding;
		bool isReplacing;

	public:
		StateMachine(){}
		~StateMachine(){}

		void addState(StateRef newState, bool isReplaced = true);
		void removeState();

		void processStateChanges();

		const StateRef& getActiveState() const{ return this->states.top(); }

	};

}
