#pragma once
#include "BaseState.h"

class PlayState : public BaseState
{
private:

public:
	PlayState(GameStateType type);
	~PlayState();

	void Start();
	void Update(float dTime);
	void Render(RenderWindow* window);
};