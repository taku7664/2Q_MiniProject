#include "pch.h"
#include "Button.h"
#include "Helper/Input/Input.h"
#include "../World/Object/Actor/Actor.h"
#include "Collision/ButtonManager.h"


namespace Engine
{
	Button::Button()
	{
		m_type = ComponentType::Button;
		isEnter = false;
	}

	Button::~Button()
	{
	}

	void Button::EarlyUpdate()
	{
		Vector2 mousePos = Input::MousePosition();
		Vector2 ownerPos = gameObject->transform->WorldPosition();

		// ��ư�� �� ���� �ִ� ��ư�� �����ؾ���. Enter, Stay, Exit�� ����.
		if (ownerPos.x - m_buttonSize.x / 2 < mousePos.x &&
			ownerPos.y - m_buttonSize.y / 2 < mousePos.y &&
			ownerPos.x + m_buttonSize.x / 2 > mousePos.x &&
			ownerPos.y + m_buttonSize.y / 2 > mousePos.y)
		{
			ButtonManager::SetTarget(gameObject);
		}
	}

	void Button::Update()
	{
		if (isEnter && ButtonManager::GetTarget() != gameObject)
		{
			for (Component* scr : gameObject->GetComponentList(ComponentType::Script))
			{
				dynamic_cast<Script*>(scr)->OnMouseExit();
			}
			isEnter = false;
		}
	}
	bool Button::OnPress()
	{
		return isEnter && Input::MouseIsDown(Mouse::LEFT);
	}
	bool Button::OnHold()
	{
		return isEnter && Input::MouseIsHold(Mouse::LEFT);
	}
	bool Button::OnRelease()
	{
		return isEnter && Input::MouseIsUp(Mouse::LEFT);
	}
}