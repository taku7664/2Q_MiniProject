#include "pch.h"
#include "Texture2D.h"

Engine::Texture2D::Texture2D(const std::wstring& _key, const std::wstring& _path, ResourceType _type)
	: Resource(_key, _path, _type), m_size(Vector2::Zero)
{
}
