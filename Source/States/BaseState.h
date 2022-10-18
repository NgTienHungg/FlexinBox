#pragma once
#include "../Enums/GameStateType.h"
#include "../Manager/MyTemplate.h"
#include "../Manager/MyDefine.h"

class BaseState
{
protected:
	GameStateType mType;

public:
	BaseState(GameStateType type);
	virtual ~BaseState();

	virtual void Start() = 0;
	virtual void Update(float dTime) = 0;
	virtual void Render(RenderWindow* window) = 0;

	// Factory method
	static BaseState* Create(GameStateType type);

	GameStateType GetType();
};