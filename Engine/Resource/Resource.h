#pragma once
#include "../Helper/ReferenceCounter.h"

namespace Engine
{
	class Resource abstract
	{
	public:
		Resource(const std::wstring& _key, const std::wstring& _path, ResourceType _type) : m_key(_key), m_path(_path), m_type(_type) {}
		virtual ~Resource() {}

		std::wstring const GetKey() { return m_key; }

	protected:
		std::wstring m_key;     // 키값
		std::wstring m_path;    // 경로
		ResourceType m_type;    // 리소스 타입
	};
}