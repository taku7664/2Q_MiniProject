#include "pch.h"
#include "Animation2D.h"

namespace Engine
{
	Animation2D::Animation2D(std::wstring _key, ResourceType _type, Sprite2D* _sprite, std::vector<AnimationData>& _data)
		: Resource(_key, L"", _type)
	{
		m_key = _key;
		m_sprite = _sprite;
		m_frameData = _data;
	}

	Animation2D::~Animation2D()
	{
	}
}