#pragma once
#include "Renderer.h"

namespace Engine
{
	class CircleRenderer
		: public Renderer
	{
	public:

		CircleRenderer();
		virtual ~CircleRenderer();

		virtual bool Draw(Camera2D* _camera) final;

		void SetLineColor(Color4 _color);
		void SetFillColor(Color4 _color);
		void SetLine(bool _val);
		void SetFill(bool _val);

		float lineWidth;  // �ܰ��� �β�
		float radius;

	private:

		Color4 m_linecolor; // ��
		Color4 m_fillcolor; // ä���
		bool isFill;			  // ä��� ����	
		bool isLine;			  // �ܰ��� ����
	};
}