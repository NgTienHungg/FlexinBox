#include "HomeState.h"
#include "StateMachine.h"

HomeState::HomeState(GameStateType type) : BaseState(type)
{
	rect = new RectangleShape();
}

HomeState::~HomeState()
{
	Delete<RectangleShape>(rect);
}

void HomeState::Start()
{
	printf("Home\n");
	rect->setSize(Vector2f(1040.f, 400.f));
	rect->setFillColor(Color::Blue);
	rect->setPosition(0.f, 0.f);
}

void HomeState::Update(float dTime)
{
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		STATE->PopState();
	}
}

void HomeState::Render(RenderWindow* window)
{
	window->draw(*rect);
}