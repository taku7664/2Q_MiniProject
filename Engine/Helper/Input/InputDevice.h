#pragma once
#include "System/Window/WindowSystem.h"

namespace Engine
{
	class InputDevice abstract
	{
	public:
		InputDevice(WindowSystem* _owner) : m_ownerWindow(_owner) {}
		virtual void Update() = 0;
	protected:
		WindowSystem* m_ownerWindow;
	private:
	};
}
