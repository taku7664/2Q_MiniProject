#pragma once
#include "System/Window/WindowSystem.h"

class Engine::WindowSystem;

namespace Engine
{
	class InputDevice abstract
	{
	public:
		virtual ~InputDevice() {}
	protected:
		HANDLE m_handle;
		Engine::WindowSystem* m_ownerWindow;
	private:
	};
}
