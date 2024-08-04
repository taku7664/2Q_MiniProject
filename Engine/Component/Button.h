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
		
		// 누르는 순간 한번만 호출됨
		bool OnPress();
		// 누르는 동안 업데이트마다 호출됨
		bool OnHold();
		// 뗀 순간 한번만 호출됨
		bool OnRelease();

	private:

		static Actor* m_targetObject;
		Vector2 	  m_buttonSize;
		bool		  isEnter;

	};
}