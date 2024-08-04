#include "pch.h"
#include "LineRenderer.h"
#include "System/Render/D2DRenderSystem.h"
#include "../Camera2D.h"
#include "../Transform2D.h"

namespace Engine
{
	LineRenderer::LineRenderer()
	{
		m_type = ComponentType::LineRenderer;
		lineWidth = 1.f;
		m_linecolor = Color4(RGB(0,0,0));
		startPos = { 0,0 };
		endPos = { 0,0 };
	}

	void LineRenderer::SetLineColor(Color4 _color)
	{
		m_linecolor = _color;
	}

	bool LineRenderer::Draw(Camera2D* _camera)
	{
		ID2D1BitmapRenderTarget* renderTarget = _camera->GetBitmapRenderTarget();

		renderTarget->SetTransform(_camera->CameraMatrix());

		D2DRenderSystem::DrawLine(startPos.x, startPos.y, endPos.x, endPos.y, m_linecolor, lineWidth, renderTarget);

		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

		return true;
	}
}