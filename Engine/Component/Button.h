#pragma once
#include "Component.h"

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

		//// ������ ���� �ѹ��� ȣ���
		//bool OnPress() { return isEnter && Mouse::MouseDown(MouseType::LEFT); }
		//// ������ ���� ������Ʈ���� ȣ���
		//bool OnHold() { return isEnter && Mouse::MouseHold(MouseType::LEFT); }
		//// �� ���� �ѹ��� ȣ���
		//bool OnRelease() { return isEnter && Mouse::MouseUp(MouseType::LEFT); }

	private:

		static Actor* m_targetObject;
		Vector2 	  m_buttonSize;
		bool		  isEnter;

	};
}