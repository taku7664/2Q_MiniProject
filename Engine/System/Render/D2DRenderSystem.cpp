#include "pch.h"
#include "D2DRenderSystem.h"
#include "System/Window/WindowSystem.h"

namespace Engine
{
	WindowSystem*			D2DRenderSystem::m_window;
	ID2D1Factory*			D2DRenderSystem::m_factory;
	IDWriteFactory*			D2DRenderSystem::m_writeFactory;
	IWICImagingFactory*		D2DRenderSystem::m_imgFactory;
	ID2D1HwndRenderTarget*  D2DRenderSystem::m_renderTarget;
	IDWriteTextFormat*		D2DRenderSystem::m_textFormat;
	ID2D1SolidColorBrush*   D2DRenderSystem::m_brush;
	ID2D1DeviceContext*		D2DRenderSystem::m_deviceContext;
	D2D1_COLOR_F			D2DRenderSystem::oldColor;
	float					D2DRenderSystem::oldAlpha;

	void D2DRenderSystem::Initialize(WindowSystem* _window)
	{
		m_window = _window;
		HRESULT check;

		check = CoInitialize(NULL);

		// 팩토리 초기화
		check = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_factory);
		if (FAILED(check))
			assert(false);
		check = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&m_writeFactory));
		if (FAILED(check))
			assert(false);
		// Create WIC factory
		check = CoCreateInstance(
			CLSID_WICImagingFactory,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_PPV_ARGS(&m_imgFactory));

		// 렌더타겟 설정
		RECT rc;
		GetClientRect(_window->GetHandle(), &rc);
		D2D1_SIZE_U size = D2D1::SizeU(
			rc.right - rc.left,
			rc.bottom - rc.top);
		check = m_factory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(_window->GetHandle(), size),
			&m_renderTarget);
		if (FAILED(check)) assert(false);

		check = m_renderTarget->QueryInterface(&m_deviceContext);
		if (FAILED(check)) assert(false);

		check = m_writeFactory->CreateTextFormat(
			L"맑은 고딕",                        // 폰트 이름
			nullptr,                            // 폰트 컬렉션 (nullptr은 기본 폰트 컬렉션)
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			20.0f,                              // 폰트 크기
			L"ko-kr",                           // 로캘(글씨 지역이름 설정이라는데 모르겠네요)
			&m_textFormat);
		if (FAILED(check)) assert(false);

		// 기본 브러쉬 생성
		check = m_renderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &m_brush);
		if (FAILED(check)) assert(false);

	}
	void D2DRenderSystem::Release()
	{
		SAFE_RELEASE(m_factory);
		SAFE_RELEASE(m_renderTarget);
		SAFE_RELEASE(m_writeFactory);
		SAFE_RELEASE(m_imgFactory);
		SAFE_RELEASE(m_textFormat);
		SAFE_RELEASE(m_brush);
		CoUninitialize();
	}


	//void D2DRenderSystem::CreateDeviceContext()
	//{
	//	IDXGIDevice* dxgiDevice;
	//	HRESULT hr = m_renderTarget->QueryInterface(___uuidof(ID2D1DeviceContext),
	//		reinterpret_cast<void**>(&dxgiDevice));
	//	if (FAILED(hr))
	//	{
	//		assert(false);
	//		return;
	//	}

	//	// Create Direct2D device and device context
	//	ID2D1Device* d2dDevice;
	//	hr = m_factory->CreateDevice(dxgiDevice.Get(), &d2dDevice);
	//	if (FAILED(hr))
	//	{
	//		assert(false);
	//		return;
	//	}

	//	hr = d2dDevice->CreateDeviceContext(D2D1_DEVICE_CONTEXT_OPTIONS_NONE, &m_deviceContext);
	//	if (FAILED(hr))
	//	{
	//		assert(false);
	//		return;
	//	}
	//}

	void D2DRenderSystem::BeginRender()
	{
		m_renderTarget->BeginDraw();
		m_renderTarget->Clear(D2D1::ColorF(D2D1::ColorF::CadetBlue));
	}

	void D2DRenderSystem::EndRender()
	{
		m_renderTarget->EndDraw();
	}

	D2D1_COLOR_F D2DRenderSystem::SwitchColor(UINT32 _color, ID2D1SolidColorBrush** _brush)
	{
		D2D1_COLOR_F tempColor = (*_brush)->GetColor(); // 기존 색상 저장
		m_brush->SetColor(D2D1::ColorF(_color));
		return tempColor; // 기존 색상 반환
	}

	float D2DRenderSystem::SwitchAlpha(float _alpha, ID2D1SolidColorBrush** _brush)
	{
		float tempAlpha = (*_brush)->GetOpacity(); // 기존 색상 저장
		m_brush->SetOpacity(_alpha);
		return tempAlpha; // 기존 색상 반환
	}

	void D2DRenderSystem::DrawRect(Rect_F _rect, Color4 _color, float _lineWidth, ID2D1RenderTarget* _renderTarget)
	{
		oldColor = SwitchColor(_color.rgb, &m_brush);
		oldAlpha = SwitchAlpha(_color.alpha, &m_brush);

		D2D1_RECT_F rect = D2D1::RectF(_rect.left, _rect.top, _rect.right, _rect.bottom);
		_renderTarget->DrawRectangle(rect, m_brush);

		m_brush->SetColor(oldColor);
		m_brush->SetOpacity(oldAlpha);
	}

	void D2DRenderSystem::DrawFillRect(Rect_F _rect, Color4 _color, ID2D1RenderTarget* _renderTarget)
	{
		oldColor = SwitchColor(_color.rgb, &m_brush);
		oldAlpha = SwitchAlpha(_color.alpha, &m_brush);

		D2D1_RECT_F rect = D2D1::RectF(_rect.left, _rect.top, _rect.right, _rect.bottom);
		_renderTarget->FillRectangle(rect, m_brush);

		m_brush->SetColor(oldColor);
		m_brush->SetOpacity(oldAlpha);
	}

	void D2DRenderSystem::DrawCircle(Vector2 _pos, float _radius, Color4 _color, float _lineWidth, ID2D1RenderTarget* _renderTarget)
	{
		oldColor = SwitchColor(_color.rgb, &m_brush);
		oldAlpha = SwitchAlpha(_color.alpha, &m_brush);

		D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2F(_pos.x, _pos.y), _radius, _radius);
		_renderTarget->DrawEllipse(ellipse, m_brush, _lineWidth);

		m_brush->SetColor(oldColor);
		m_brush->SetOpacity(oldAlpha);
	}

	void D2DRenderSystem::DrawFillCircle(Vector2 _pos, float _radius, Color4 _color, ID2D1RenderTarget* _renderTarget)
	{
		oldColor = SwitchColor(_color.rgb, &m_brush);
		oldAlpha = SwitchAlpha(_color.alpha, &m_brush);

		D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2F(_pos.x, _pos.y), _radius, _radius);
		_renderTarget->FillEllipse(&ellipse, m_brush);

		m_brush->SetColor(oldColor);
		m_brush->SetOpacity(oldAlpha);
	}

	void D2DRenderSystem::DrawLine(float _startX, float _startY, float _endX, float _endY, Color4 _color, float _lineWidth, ID2D1RenderTarget* _renderTarget)
	{
		oldColor = SwitchColor(_color.rgb, &m_brush);
		oldAlpha = SwitchAlpha(_color.alpha, &m_brush);

		_renderTarget->DrawLine(D2D1::Point2F(_startX, _startY), D2D1::Point2F(_endX, _endY), m_brush, _lineWidth);

		m_brush->SetColor(oldColor);
		m_brush->SetOpacity(oldAlpha);
	}
}
