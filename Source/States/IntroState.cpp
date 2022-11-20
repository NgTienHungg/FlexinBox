#include "IntroState.h"
#include "StateMachine.h"

IntroState::IntroState(GameStateType type) : BaseState(type)
{
	rect = new RectangleShape();
}

IntroState::~IntroState()
{
	Delete<RectangleShape>(rect);
}

void IntroState::setMessage()
{
}

void IntroState::Start()
{
	printf("Intro\n");
}

void IntroState::Update(float dTime)
{
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		STATE->StateTransition(GameStateType::HOME);
	}
}

void IntroState::Render(RenderWindow* window)
{
	window->draw(*rect);
}