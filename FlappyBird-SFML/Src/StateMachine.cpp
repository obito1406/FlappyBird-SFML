#include "StateMachine.h"



namespace FlappyBird
{
	void StateMachine::AddState(StateRef newState, bool isReplacingPrevious)
	{
		mIsAdding = true;
		mIsReplacingPrevious = isReplacingPrevious;

		mNewState = std::move(newState);
	}

	void StateMachine::RemoveState()
	{
		mIsRemoving = true;
	}

	void StateMachine::ProcessStateChanges() //Similar to OnStateChange
	{
		//Remove
		if (!mStates.empty && mIsRemoving)
		{
			mStates.pop(); //Pop removes the "top" element. The top element its always the last to join the stack as LIFO dictates.
			
			if (!mStates.empty)
			{
				mStates.top()->Resume();	//Once the previous state has been remove we return and resume the previous state on the stack. Eg: We "remove" the pause state and "resume" come back to the main game.
			}

			mIsRemoving = false;
		}

		//Add
		if (mIsAdding)
		{
			if (!mStates.empty())
			{
				if (mIsReplacingPrevious)
				{
					mStates.pop();
				}
				else
				{
					mStates.top()->Pause();
				}
			}

			mStates.push(std::move(mNewState));
			mStates.top()->Init();
			mIsAdding = false;
		}
	}

	StateRef &StateMachine::GetActiveState()
	{
		return mStates.top();
	}
}