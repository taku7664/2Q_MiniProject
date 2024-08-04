#pragma once
#include "Resource/Resource.h"

namespace Engine
{
	class Texture2D
		: public Resource
	{
	public:
		Texture2D(const std::wstring& _key, const std::wstring& _path, ResourceType _type);
		virtual ~Texture2D();

		Vector2 GetSize() { return m_size; }

	private:

		Vector2 m_size;

	};
}

