#include "ScriptHeaders.h"

void TestScript::Start()
{
	gameObject->transform->position = Vector2(100, 100);

	rect = gameObject->AddComponent<Engine::RectRenderer>();
	sprite = gameObject->AddComponent<Engine::SpriteRenderer2D>();
	button = gameObject->AddComponent<Engine::Button>();

	rect->size = Vector2(100, 100);
	button->SetSize(rect->size);
}

void TestScript::Update()
{
}

void TestScript::Fixedupdate()
{
}

void TestScript::OnEnable()
{
}

void TestScript::OnDisable()
{
}

void TestScript::OnDestroy()
{
}

void TestScript::OnCollisionEnter(Engine::Actor* _collision)
{
}

void TestScript::OnCollisionStay(Engine::Actor* _collision)
{
}

void TestScript::OnCollisionExit(Engine::Actor* _collision)
{
}

void TestScript::OnMouseEnter()
{
	Debug::Log("Button Enter!");
}

void TestScript::OnMouseStay()
{
	Debug::Log("Button Stay!");
}

void TestScript::OnMouseExit()
{
	Debug::Log("Button Exit!");
}
