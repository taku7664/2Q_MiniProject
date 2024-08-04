#include "pch.h"
#include "Input.h"

Key*   Input::m_key;
Mouse* Input::m_mouse;

void Input::Initialize(Engine::WindowSystem* _window)
{
	m_key = new Key(_window);
	m_mouse = new Mouse(_window);
}

void Input::StateUpdate()
{
	m_key->ResetKey();
}

void Input::Release()
{
	SAFE_DELETE(m_key);
	SAFE_DELETE(m_mouse);
}

void Input::GetKeyDown(int _keyCode)
{
	m_key->GetKeyDown(_keyCode);
}

void Input::GetKeyUp(int _keyCode)
{
	m_key->GetKeyUp(_keyCode);
}

void Input::GetMouseMove()
{
	m_mouse->Update();
}

bool Input::KeyIsDown(int _keyCode)
{
	return m_key->KeyDown(_keyCode);
}

bool Input::KeyIsHold(int _keyCode)
{
	return m_key->KeyHold(_keyCode);
}

bool Input::KeyIsUp(int _keyCode)
{
	return m_key->KeyUp(_keyCode);
}

bool Input::MouseIsDown(int _type)
{
	return m_mouse->MouseDown(_type);
}

bool Input::MouseIsHold(int _type)
{
	return m_mouse->MouseHold(_type);
}

bool Input::MouseIsUp(int _type)
{
	return m_mouse->MouseUp(_type);
}

Vector2 Input::MousePosition()
{
	return m_mouse->MousePosition();
}
