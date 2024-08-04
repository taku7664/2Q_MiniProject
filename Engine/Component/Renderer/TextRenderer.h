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
		std::wstring m_text;                 // ������ �ؽ�Ʈ
		Engine::Font* m_font;              // ��Ʈ
		float m_textSize;                    // �۾� ũ��
		D2D1_COLOR_F m_textColor;            // �۾� ��

		void UpdateLayout();

	};
}
