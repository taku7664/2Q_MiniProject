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
		std::wstring m_key;     // Ű��
		std::wstring m_path;    // ���
		ResourceType m_type;    // ���ҽ� Ÿ��
	};
}