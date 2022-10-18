#pragma once
#include "BaseState.h"

class HomeState : public BaseState
{
private:
	RectangleShape* rect;

public:
	HomeState(GameStateType type);
	~HomeState();

	void Start();
	void Update(float dTime);
	void Render(RenderWindow* window);
};