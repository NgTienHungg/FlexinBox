#include "Application.h"

Application::Application()
{
	mWindow = new RenderWindow();
	mEvent = Event();
	mDeltaTime = 0.f;
} 

Application::~Application()
{
	Delete<RenderWindow>(mWindow);
}

void Application::Start()
{
	mWindow = new RenderWindow(VideoMode(ScreenWidth, ScreenHeight), TitleGame, Style::Close);
	mWindow->setFramerateLimit(60);
	mWindow->setVerticalSyncEnabled(false);
	STATE->StateTransition(GameStateType::INTRO);
}

void Application::Update()
{
	if (STATE->NeedToChangeState()) {
		STATE->PushState();
	}
	STATE->GetCurrentState()->Update(mDeltaTime);
}

void Application::Render()
{
	mWindow->clear(Color::Black);
	STATE->GetCurrentState()->Render(mWindow);
	mWindow->display();
}


void Application::Run()
{
	Start();
	Clock clock;

	while (mWindow->isOpen()) {
		mDeltaTime = clock.restart().asSeconds();
		while (mWindow->pollEvent(mEvent)) {
			if (mEvent.type == Event::Closed) {
				mWindow->close();
			}
		}
		Update();
		Render();
	}
}

RenderWindow* Application::GetWindow()
{
	return mWindow;
}

Event Application::GetEvent()
{
	return mEvent;
}

float Application::GetDeltaTime()
{
	return mDeltaTime;
}