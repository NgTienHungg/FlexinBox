#include "BaseState.h"
#include "IntroState.h"
#include "HomeState.h"
#include "PlayState.h"

BaseState::BaseState(GameStateType type)
{
	mType = type;
}

BaseState::~BaseState()
{
}

BaseState* BaseState::Create(GameStateType type)
{
	BaseState* state = nullptr;
	switch (type)
	{
	case GameStateType::INTRO:
		state = new IntroState(GameStateType::INTRO);
		break;
	case GameStateType::HOME:
		state = new HomeState(GameStateType::HOME);
		break;
	case GameStateType::PLAY:
		state = new PlayState(GameStateType::PLAY);
		break;
	default:
		break;
	}
	return state;
}

GameStateType BaseState::GetType()
{
	return mType;
}