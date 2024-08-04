#pragma once
#include "Application.h"

class TestScript
	: public Engine::Script
{
	
private:
	Engine::RectRenderer* rect;
	Engine::SpriteRenderer2D* sprite;
	Engine::Button* button;
public:
	void Start();
	void Update();
	void Fixedupdate();
	void OnEnable();
	void OnDisable();
	void OnDestroy();
	void OnCollisionEnter(Engine::Actor* _collision);
	void OnCollisionStay(Engine::Actor* _collision);
	void OnCollisionExit(Engine::Actor* _collision);
	void OnMouseEnter();
	void OnMouseStay();
	void OnMouseExit(); 
};

