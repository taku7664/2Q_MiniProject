#pragma once
#include "../ButtonUI.h"

class TestButton
	:public ButtonUI
{
public:
	void Start();
	void Update();
	void OnMouseEnter();
	void OnMouseStay();
	void OnMouseExit();
protected:
	int buttonState;
	// �ӽ÷� ���� ���߿� MainSprite ���
	Engine::RectRenderer* rect;
private:
};

