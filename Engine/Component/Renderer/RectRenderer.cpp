#include "pch.h"
#include "RectRenderer.h"
#include "System/Render/D2DRenderSystem.h"
#include "../../World/Object/Actor/Actor.h"
#include "../Camera2D.h"
#include "../Transform2D.h"

namespace Engine
{
	RectRenderer::RectRenderer()
		: isFill(true),
		isLine(true),
		lineWidth(1.f),
		m_fillcolor(RGB(255, 255, 255)),
		m_linecolor(RGB(0, 0, 0))
	{
		m_type = ComponentType::RectRenderer;
	}

	RectRenderer::~RectRenderer()
	{
	}

	bool RectRenderer::Draw(Camera2D* _camera)
	{
		ID2D1BitmapRenderTarget* renderTarget = _camera->GetBitmapRenderTarget();

		renderTarget->SetTransform(CalCulateMatrix(_camera));

		Rect_F rect(renderOffset.x, renderOffset.y,
			renderOffset.x + size.x, renderOffset.y + size.y);

		if (isFill)
		{
			D2DRenderSystem::DrawFillRect(rect, m_fillcolor, renderTarget);
		}

		if (isLine)
		{
			D2DRenderSystem::DrawRect(rect, m_linecolor, lineWidth, renderTarget);
		}

		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

		return true;
	}

	void RectRenderer::SetLineColor(Color4 _color)
	{
		m_linecolor = _color;
	}

	void RectRenderer::SetFillColor(Color4 _color)
	{
		m_fillcolor = _color;
	}

	void RectRenderer::SetLine(bool _val)
	{
		isLine = _val;
	}

	void RectRenderer::SetFill(bool _val)
	{
		isFill = _val;
	}
}