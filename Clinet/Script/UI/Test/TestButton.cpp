#include "TestButton.h"

void TestButton::Start()
{
	__super::Start();
	rect = gameObject->AddComponent<Engine::RectRenderer>();
	rect->size = Vector2(100, 50);
	button->SetSize(rect->size);

	Engine::ResourceManager::AddSprite2D(L"ButtonSheet", L"Sprite/button1.png", SpriteData(Vector2(3, 2)));
	mainSprite->SetSprite(L"ButtonSheet", 3);
}

void TestButton::Update()
{
	mainSprite->index = buttonState;
}

void TestButton::OnMouseEnter()
{
	buttonState = 1;
	Debug::Log("Enter");
	rect->SetFillColor(RGB(100, 100, 100));
}

void TestButton::OnMouseStay()
{
	if (Input::MouseIsDown(Mouse::LEFT))
	{
		Debug::Log("Click");
	}
	if (Input::MouseIsHold(Mouse::LEFT))
	{
		buttonState = 2;
	}
}

void TestButton::OnMouseExit()
{
	Debug::Log("Exit");
	rect->SetFillColor(RGB(255, 255, 255));
	buttonState = 0;
}
