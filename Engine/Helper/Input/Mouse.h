#pragma once
#include "InputDevice.h"

class Mouse : public Engine::InputDevice
{
private:
	struct MouseState {
		bool Left = false;
		bool Right = false;
		bool Mid = false;
	};
	MouseState curState;
	MouseState preState;
	Vector2	   mousePos;

public:
	enum Type // ¸¶¿ì½º
	{
		LEFT = VK_LBUTTON,
		ROLL = VK_MBUTTON,
		RIGHT = VK_RBUTTON,
	};
	Mouse(Engine::WindowSystem* _owner) : InputDevice(_owner) {};
	virtual ~Mouse() {}

	virtual void Update() override;

	Vector2 MousePosition() { return mousePos; }
	bool MouseDown(int _code);
	bool MouseHold(int _code);
	bool MouseUp(int _code);

};