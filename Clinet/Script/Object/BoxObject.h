#pragma once
#include "ObjectBase.h"

class BoxObject
	: public ObjectBase
{
public:
	void Start();
protected:
	Engine::BoxCollider2D* body;
private:
};

