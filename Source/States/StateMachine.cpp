#include "StateMachine.h"
#include "BaseState.h"

StateMachine::StateMachine()
{
	mNextState = nullptr;
}

StateMachine::~StateMachine()
{
	while (!mStates.empty()) {
		BaseState* state = mStates.back();
		Delete<BaseState>(state);
		mStates.pop_back();
	}
	Delete<BaseState>(mNextState);
}

BaseState* StateMachine::GetCurrentState()
{
	if (!mStates.empty()) {
		return mStates.back();
	}
	return nullptr;
}

BaseState* StateMachine::GetNextState()
{
	return mNextState;
}

void StateMachine::StateTransition(GameStateType stateType)
{
	BaseState* state = BaseState::Create(stateType);
	StateTransition(state);
}

void StateMachine::StateTransition(BaseState* nextState)
{
	mNextState = nextState;
}

bool StateMachine::NeedToChangeState()
{
	return mNextState != nullptr;
}

void StateMachine::PushState()
{
	mStates.push_back(mNextState);
	GetCurrentState()->Start();
	mNextState = nullptr;
}

void StateMachine::PopState()
{
	if (!mStates.empty()) {
		BaseState* state = mStates.back();
		Delete<BaseState>(state);
		mStates.pop_back();
	}
}