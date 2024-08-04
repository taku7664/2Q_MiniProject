#pragma once
#include "InputDevice.h"

#define KEYBOARD_MAX 256

class Key : public Engine::InputDevice
{
private:
	struct KeyState {
		bool IsDown = false;
		bool IsHold = false;
		bool IsUp = false;
	};
	std::vector<short> KeyDown_Reset;
	std::vector<short> KeyUp_Reset;
	KeyState Key_Code[KEYBOARD_MAX];
public:
	enum Type // Ű����
	{
		UP = VK_UP,
		DOWN = VK_DOWN,
		LEFT = VK_LEFT,
		RIGHT = VK_RIGHT,
		SPACEBAR = VK_SPACE,
	};
	Key(Engine::WindowSystem* _owner) : InputDevice(_owner) {};
	virtual ~Key() {};

	virtual void Update() override {}

	void GetKeyDown(WPARAM _wParam);
	void GetKeyUp(WPARAM _wParam);
	void ResetKey();

	// Ű���尡 ���ȴ��� Ȯ���մϴ�.
	bool KeyDown(int _code);
	bool KeyDown(char _code);
	// Ű���尡 ������ �ִ� ������ Ȯ���մϴ�.
	bool KeyHold(int _code);
	bool KeyHold(char _code);
	// Ű���带 �ô��� Ȯ���մϴ�.
	bool KeyUp(int _code);
	bool KeyUp(char _code);
};
