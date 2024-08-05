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
	// 임시로 만듬 나중엔 MainSprite 사용
	Engine::RectRenderer* rect;
private:
};

