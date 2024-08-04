#pragma once
#include "Component.h"

class Input;

namespace Engine
{
	class Button
		: public Component
	{
	public:
		Button();
		virtual ~Button();

		virtual void EarlyUpdate() final;
		virtual void Update() final;

		bool& IsEnter() { return isEnter; }
		void  SetSize(Vector2 _size) { m_buttonSize = _size; }
		
		// ������ ���� �ѹ��� ȣ���
		bool OnPress();
		// ������ ���� ������Ʈ���� ȣ���
		bool OnHold();
		// �� ���� �ѹ��� ȣ���
		bool OnRelease();

	private:

		static Actor* m_targetObject;
		Vector2 	  m_buttonSize;
		bool		  isEnter;

	};
}