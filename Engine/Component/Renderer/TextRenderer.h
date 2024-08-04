#pragma once
#include "Renderer.h"
#include "Resource/Font/Font.h"

namespace Engine
{
	class TextRenderer
		: public Renderer
	{
	public:
		TextRenderer();
		virtual ~TextRenderer();

		virtual void Initialize() final;
		virtual bool Draw(Camera2D* _camera) final;

	private:

		IDWriteTextLayout* m_textLayout;
		Rect_F m_textBox;
		std::wstring m_text;                 // 츨력할 텍스트
		Engine::Font* m_font;              // 폰트
		float m_textSize;                    // 글씨 크기
		D2D1_COLOR_F m_textColor;            // 글씨 색

		void UpdateLayout();

	};
}
