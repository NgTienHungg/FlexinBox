#pragma once
#include "BaseState.h"

class IntroState : public BaseState
{
private:
	RectangleShape* rect;

public:
	IntroState(GameStateType type);
	~IntroState();

	void Start();
	void Update(float dTime);
	void Render(RenderWindow* window);
};