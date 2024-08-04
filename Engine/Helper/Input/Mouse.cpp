#include "pch.h"
#include "Mouse.h"

void Mouse::Update()
{
	// 마우스 업데이트
	preState = curState;

	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(m_ownerWindow->GetHandle(), &pt);

	mousePos = { (float)pt.x , (float)pt.y };
	curState.Mid = 0;

	curState.Left = (GetKeyState(VK_LBUTTON) & 0x8000) != 0;
	curState.Right = (GetKeyState(VK_RBUTTON) & 0x8000) != 0;
	curState.Mid = (GetKeyState(VK_MBUTTON) & 0x8000) != 0;
}

bool Mouse::MouseDown(int _code)
{
	if (_code == RIGHT && !preState.Right) return curState.Right;
	if (_code == ROLL && !preState.Mid) return curState.Mid;
	if (_code == LEFT && !preState.Left) return curState.Left;
	return false;
}

bool Mouse::MouseHold(int _code)
{
	if (_code == RIGHT) return curState.Right;
	if (_code == ROLL) return curState.Mid;
	if (_code == LEFT) return curState.Left;
	return false;
}

bool Mouse::MouseUp(int _code)
{
	if (_code == RIGHT && !curState.Right && preState.Right) return true;
	if (_code == ROLL && !curState.Mid && preState.Mid) return true;
	if (_code == LEFT && !curState.Left && preState.Left) return true;
	return false;
}