#include "UIBase.h"

void UIBase::Start()
{
	mainSprite = gameObject->AddComponent<Engine::SpriteRenderer2D>();
}
