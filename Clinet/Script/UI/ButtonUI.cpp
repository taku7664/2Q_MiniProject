#include "ButtonUI.h"

void ButtonUI::Start()
{
	__super::Start();
	button = gameObject->AddComponent<Engine::Button>();
}
