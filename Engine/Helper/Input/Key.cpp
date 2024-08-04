#include "pch.h"
#include "Key.h"

void Key::GetKeyDown(WPARAM _wParam)
{
	if (Key_Code[_wParam].IsHold == false) {
		Key_Code[_wParam].IsDown = true;
		Key_Code[_wParam].IsHold = true;
		KeyDown_Reset.push_back(_wParam);
	}
}

void Key::GetKeyUp(WPARAM _wParam)
{
	Key_Code[_wParam].IsHold = false;
	Key_Code[_wParam].IsUp = true;
	KeyUp_Reset.push_back(_wParam);
}

// �� ������Ʈ �������� Down�̳� Up�� �������� �ʱ�ȭ��ŵ�ϴ�.
void Key::ResetKey()
{
	while (!KeyDown_Reset.empty())
	{
		Key_Code[KeyDown_Reset.back()].IsDown = false;
		KeyDown_Reset.pop_back();
	}
	while (!KeyUp_Reset.empty()) 
	{
		Key_Code[KeyUp_Reset.back()].IsUp = false;
		KeyUp_Reset.pop_back();
	}
}

bool Key::KeyDown(int _code)
{
	return Key_Code[_code].IsDown;
}

bool Key::KeyDown(char _code)
{
	return Key_Code[(int)_code].IsDown;
}

bool Key::KeyHold(int _code)
{
	return Key_Code[_code].IsHold;
}

bool Key::KeyHold(char _code)
{
	return Key_Code[(int)_code].IsHold;
}

bool Key::KeyUp(int _code)
{
	return Key_Code[_code].IsUp;
}

bool Key::KeyUp(char _code)
{
	return Key_Code[(int)_code].IsUp;
}
