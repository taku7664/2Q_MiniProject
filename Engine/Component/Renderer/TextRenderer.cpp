#include "pch.h"
#include "TextRenderer.h"
#include "System/Render/D2DRenderSystem.h"

namespace Engine
{
	TextRenderer::TextRenderer()
	{
		m_type = ComponentType::TextRenderer;
	}

	TextRenderer::~TextRenderer()
	{
		SAFE_RELEASE(m_textLayout)
	}

	void TextRenderer::Initialize()
	{

	}

	bool TextRenderer::Draw(Camera2D* _camera)
	{
		return false;
	}
	void TextRenderer::UpdateLayout()
	{
		UINT32 len = m_text.length();

		if (m_textLayout)
		{
			m_textLayout->Release();
			m_textLayout = nullptr;
		}

		HRESULT check;
		if (m_font)
		{
			check = D2DRenderSystem::GetWriteFactory()->CreateTextLayout(
				m_text.c_str(),
				len,
				m_font->GetTextFormat(),
				size.x,
				size.y,
				&m_textLayout
			);
		}
		else
		{
			check = D2DRenderSystem::GetWriteFactory()->CreateTextLayout(
				m_text.c_str(),
				len,
				D2DRenderSystem::GetTextFormat(),
				size.x,
				size.y,
				&m_textLayout
			);
		}
	}
}