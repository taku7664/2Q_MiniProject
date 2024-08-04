#pragma once
#include "../Engine/Application.h"

class GameApplication
	: public Engine::Application
{
public:
	void Initialize(HINSTANCE _hinstance, const WCHAR* _title, const int _width, const int _height);
	void LoadWorld();
};