#pragma once
#include "Key.h"
#include "Mouse.h"

class Input
{
public:
	static void Initialize(Engine::WindowSystem* _window);
	static void Update();
	static void StateUpdate();
	static void Release();

	static void GetKeyDown(int _keyCode);
	static void GetKeyUp(int _keyCode);
	static void GetMouseMove();

	//===================Key===================
	static bool KeyIsDown(int _keyCode);
	static bool KeyIsHold(int _keyCode);
	static bool KeyIsUp(int _keyCode);
	//===================Mouse===================
	static bool MouseIsDown(int _type);
	static bool MouseIsHold(int _type);
	static bool MouseIsUp(int _type);
	static Vector2 MousePosition();
private:
	static Key*	  m_key;
	static Mouse* m_mouse;
};
