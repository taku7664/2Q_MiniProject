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

		float lineWidth;  // 외곽선 두께
		float radius;

	private:

		Color4 m_linecolor; // 선
		Color4 m_fillcolor; // 채우기
		bool isFill;			  // 채우기 여부	
		bool isLine;			  // 외곽선 여부
	};
}