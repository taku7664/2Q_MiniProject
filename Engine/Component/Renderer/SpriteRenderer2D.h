#pragma once
#include "Renderer.h"
#include "Resource/Sprite/Sprite2D.h"

namespace Engine
{
	class SpriteRenderer2D
		: public Renderer
	{
	public:
		SpriteRenderer2D();
		virtual ~SpriteRenderer2D();

		virtual bool Draw(Camera2D* _camera) final;

		void SetSprite(std::wstring _key);
		void SetSprite(std::wstring _key, int _index);
		void SetSprite(Sprite2D* _sprite);
		void SetSprite(Sprite2D* _sprite, int _index);

		int GetIndexXY(int _x, int _y) { return _x * _y - 1; }

		int index = 0;

		float alpha;

	private:

		Sprite2D* m_sprite;

	};
}
