#include "pch.h"
#include "Font.h"
#include "System/Render/D2DRenderSystem.h"

namespace Engine
{
    Font::Font(std::wstring _key, const std::wstring& _path, ResourceType _type)
        : Resource(_key, _path, _type)
    {
        m_path = _path;

        m_fontName = _key;

        HRESULT check;
        // ��Ʈ ���� ���� ����
        check = D2DRenderSystem::GetWriteFactory()->CreateFontFileReference(_path.c_str(), nullptr, &m_fontFile);
        if (FAILED(check)) assert(false);
        // �ؽ�Ʈ ���� ����
        check = D2DRenderSystem::GetWriteFactory()->CreateTextFormat(
            _path.c_str(),
            nullptr,
            DWRITE_FONT_WEIGHT_NORMAL,
            DWRITE_FONT_STYLE_NORMAL,
            DWRITE_FONT_STRETCH_NORMAL,
            20.0f,
            L"",
            &m_textFormat
        );
        if (FAILED(check)) assert(false);
    }

    Font::~Font()
    {

    }
}