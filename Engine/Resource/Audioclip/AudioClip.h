#pragma once
#include "Resource/Resource.h"

namespace Engine
{
	class AudioClip
		: public Resource
	{
	public:
		AudioClip(const std::wstring& _key, const std::wstring& _path, ResourceType _type);
		virtual ~AudioClip() {}

	private:
	};
}