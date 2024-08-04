#pragma once
#include "Application.h"

namespace World
{
	class Test : public Engine::World
	{
	public:
		virtual void WorldLoad() override;
		virtual void WorldDestroy() override;
		virtual void WorldEnter() override;
		virtual void WorldExit() override;
	private:
	};
}
