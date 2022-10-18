#include "PlayState.h"

PlayState::PlayState(GameStateType type) : BaseState(type)
{
}

PlayState::~PlayState()
{
}

void PlayState::Start()
{
	printf("Play\n");
}

void PlayState::Update(float dTime)
{
}

void PlayState::Render(RenderWindow* window)
{
}