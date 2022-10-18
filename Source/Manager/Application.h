#pragma once
#include "../States/StateMachine.h"
#include "MyTemplate.h"
#include "MyDefine.h"

class Application : public Singleton<Application>
{
private:
	RenderWindow* mWindow;
	Event mEvent;
	float mDeltaTime;

	void Start();
	void Update();
	void Render();

public:
	Application();
	~Application();

	void Run();

	RenderWindow* GetWindow();
	Event GetEvent();
	float GetDeltaTime();
};