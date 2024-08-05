#pragma once
#include "ObjectBase.h"

class CircleObject
	: public ObjectBase
{
public:
protected:
	Engine::CircleCollider2D* body;
private:
};
