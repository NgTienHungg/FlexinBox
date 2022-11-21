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

void IntroState::Start()
{
	printf("Intro\n");
	rect->setSize(Vector2f(100.f, 100.f));
	rect->setFillColor(Color::Green);
	rect->setPosition(200.f, 50.f);
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