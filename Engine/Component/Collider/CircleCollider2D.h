#pragma once
#include "Collider.h"

namespace Engine
{
	class CircleCollider2D
		: public Collider
	{
	public:

		CircleCollider2D();
		virtual ~CircleCollider2D();

		float radius;

	private:

	};
}