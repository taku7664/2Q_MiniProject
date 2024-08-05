#pragma once
#include "Application.h"

class UIBase
	: public Engine::Script
{
public:
	void Start();
protected:
	Engine::SpriteRenderer2D* mainSprite;
private:
};