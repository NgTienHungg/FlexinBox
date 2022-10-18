#pragma once
#include "BaseState.h"
#include <list>

class StateMachine : public Singleton<StateMachine>
{
private:
	list<BaseState*> mStates;
	BaseState* mNextState;
	
public:
	StateMachine();
	~StateMachine();

	BaseState* GetCurrentState();
	BaseState* GetNextState();

	void StateTransition(GameStateType stateType);
	void StateTransition(BaseState* nextState);

	bool NeedToChangeState();
	void PushState();
	void PopState();
};