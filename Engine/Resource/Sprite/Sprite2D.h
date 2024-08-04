#pragma once
#include "Resource/Resource.h"

struct SpriteData
{
	Vector2		  cut_by_grid;
	Vector2	      margin;
	D2D_RECT_F    offset;

	SpriteData(
		Vector2 _grid = { 1,1 },
		Vector2 _margin = { 0,0 },
		D2D_RECT_F _offset = { 0,0,0,0 })
		: cut_by_grid(_grid),
		offset(_offset),
		margin(_margin) {}
};

struct CSVSpriteData
{

};

namespace Engine
{
	class Sprite2D
		: public Resource
	{
	public:

		Sprite2D(const std::wstring& _key, const std::wstring& _path, ResourceType _type, SpriteData _data);
		Sprite2D(const std::wstring& _key, const std::wstring& _path, CSVSpriteData _data);
		virtual ~Sprite2D();

		ID2D1Bitmap* GetSprite(int _index = 0) 
		{
			return m_spriteSheet[_index];
		}

	protected:

		std::vector<ID2D1Bitmap*> m_spriteSheet; // ��������Ʈ �����͸� ���� �ڸ� ��������Ʈ
		SpriteData m_spriteData;				 // ��������Ʈ �̹����� �ڸ� ����

	};
}
