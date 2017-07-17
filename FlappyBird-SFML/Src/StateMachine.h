#pragma once

#include <memory> //unique_ptr
#include <stack>

#include "State.h"

namespace FlappyBird
{
	typedef std::unique_ptr<State> StateRef; 

	class StateMachine
	{
	public:
		StateMachine() {};
		~StateMachine() {};

		void AddState(StateRef newState, bool isReplacingPrevious = true);
		void RemoveState();

		void ProcessStateChanges();

		StateRef& GetActiveState();

	private:
		std::stack<StateRef> mStates; //Vector que almacena siguiente un estilo LIFO (Last Input First Output)
		StateRef mNewState;

		bool mIsRemoving;
		bool mIsReplacingPrevious;
		bool mIsAdding;
	};

}

