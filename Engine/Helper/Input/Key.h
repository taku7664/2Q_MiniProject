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
	enum Type // 키보드
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

	// 키보드가 눌렸는지 확인합니다.
	bool KeyDown(int _code);
	bool KeyDown(char _code);
	// 키보드가 누르고 있는 중인지 확인합니다.
	bool KeyHold(int _code);
	bool KeyHold(char _code);
	// 키보드를 뗐는지 확인합니다.
	bool KeyUp(int _code);
	bool KeyUp(char _code);
};
