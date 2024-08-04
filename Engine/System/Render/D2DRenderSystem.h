#pragma once
#include "System/Interface/IRenderSystem.h"
#include "Resource/Sprite/Sprite2D.h"
#include "Resource/Animation/Animation2D.h"

namespace Engine
{
	class WindowSystem;
	class D2DMainRender;
	class D2DSubRender;
	class Sprite2D;
	class Animation2D;

	class D2DRenderSystem
		: public IRenderSystem
	{
	public:

		D2DRenderSystem() = default;
		virtual ~D2DRenderSystem();

		static void Initialize(WindowSystem* _window);
		static void Release();

		static void BeginRender();
		static void EndRender();

		static void DrawRect(Rect_F _rect, Color4 _color, float _lineWidth, ID2D1RenderTarget* _renderTarget = m_renderTarget);
		static void DrawFillRect(Rect_F _rect, Color4 _color, ID2D1RenderTarget* _renderTarget = m_renderTarget);
		static void DrawCircle(Vector2 _pos, float _radius, Color4 _color, float _lineWidth, ID2D1RenderTarget* _renderTarget = m_renderTarget);
		static void DrawFillCircle(Vector2 _pos, float _radius, Color4 _color, ID2D1RenderTarget* _renderTarget = m_renderTarget);
		static void DrawLine(float _startX, float _startY, float _endX, float _endY, Color4 _color, float _lineWidth, ID2D1RenderTarget* _renderTarget = m_renderTarget);
		static void DrawBitmap(ID2D1Bitmap* _sprite, Rect_F _rect, Color4 _color, ID2D1RenderTarget* _renderTarget = m_renderTarget);

		static  WindowSystem* GetWindow() { return m_window; }
		static ID2D1Factory* GetFactory() { return m_factory; }
		static IDWriteFactory* GetWriteFactory() { return m_writeFactory; }
		static IWICImagingFactory* GetIMGFactory() { return m_imgFactory; }
		static ID2D1HwndRenderTarget* GetRenderTarget() { return m_renderTarget; }
		static IDWriteTextFormat* GetTextFormat() { return m_textFormat; }
		static ID2D1SolidColorBrush* GetBrush() { return m_brush; }

	private:

		static WindowSystem*			m_window;
		static ID2D1Factory*			m_factory;
		static ID2D1HwndRenderTarget*	m_renderTarget;
		static IDWriteFactory*			m_writeFactory;
		static IWICImagingFactory*		m_imgFactory;
		static IDWriteTextFormat*		m_textFormat;
		static ID2D1SolidColorBrush*	m_brush;
		static ID2D1DeviceContext*		m_deviceContext;

		static D2D1_COLOR_F				oldColor;
		static float					oldAlpha;

		static D2D1_COLOR_F   SwitchColor(UINT32 _color, ID2D1SolidColorBrush** _brush);
		static float	      SwitchAlpha(float  _alpha, ID2D1SolidColorBrush** _brush);

	};
}