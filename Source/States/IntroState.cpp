#include "IntroState.h"
#include "StateMachine.h"

IntroState::IntroState(GameStateType type) : BaseState(type)
{
	rect = new RectangleShape(Vector2f(100, 100));
}

IntroState::~IntroState()
{
	Delete<RectangleShape>(rect);
}

void IntroState::Start()
{
	printf("Intro\n");
	rect->setPosition(100.f, 100.f);
	rect->setFillColor(Color::Green);
	rect->setOutlineThickness(5.f);
	rect->setOutlineColor(Color::Red);
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