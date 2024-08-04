#include "pch.h"
#include "CircleRenderer.h"
#include "System/Render/D2DRenderSystem.h"
#include "../../World/Object/Actor/Actor.h"
#include "../Camera2D.h"
#include "../Transform2D.h"

namespace Engine
{
	CircleRenderer::CircleRenderer()
		: isFill(true),
		isLine(true),
		lineWidth(1.f),
		m_fillcolor(RGB(255, 255, 255)),
		m_linecolor(RGB(0, 0, 0))
	{
		m_type = ComponentType::CircleRenderer;
	}

	CircleRenderer::~CircleRenderer()
	{
	}

	bool CircleRenderer::Draw(Camera2D* _camera)
	{
		ID2D1BitmapRenderTarget* renderTarget = _camera->GetBitmapRenderTarget();

		renderTarget->SetTransform(CalCulateMatrix(_camera));

		if (isFill)
		{
			D2DRenderSystem::DrawFillCircle(renderOffset, radius, m_fillcolor, renderTarget);
		}

		if (isLine)
		{
			D2DRenderSystem::DrawCircle(renderOffset, radius, m_linecolor, lineWidth, renderTarget);
		}

		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

		return true;
	}

	void CircleRenderer::SetLineColor(Color4 _color)
	{
		m_linecolor = _color;
	}

	void CircleRenderer::SetFillColor(Color4 _color)
	{
		m_fillcolor = _color;
	}

	void CircleRenderer::SetLine(bool _val)
	{
		isLine = _val;
	}

	void CircleRenderer::SetFill(bool _val)
	{
		isFill = _val;
	}
}