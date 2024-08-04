#pragma once
#include "Renderer.h"

namespace Engine
{
	class RectRenderer
		: public Renderer
	{
	public:

		RectRenderer();
		virtual ~RectRenderer();

		virtual bool Draw(Camera2D* _camera) final;

		void SetLineColor(Color4 _color);
		void SetFillColor(Color4 _color);
		void SetLine(bool _val);
		void SetFill(bool _val);

		float lineWidth;  // �ܰ��� �β�

	private:

		Color4 m_linecolor; // ��
		Color4 m_fillcolor; // ä���
		bool isFill;			  // ä��� ����	
		bool isLine;			  // �ܰ��� ����
	};
}