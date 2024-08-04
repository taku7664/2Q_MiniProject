#pragma once

namespace Engine
{
    class WindowSystem
    {

    public:
        WindowSystem() {}
        WindowSystem(HINSTANCE _hInstance, const WCHAR* _title, Vector2 _size);
        virtual ~WindowSystem();

        void Initialize();

        HWND      GetHandle() const { return m_handle; }
        HINSTANCE GetHInstace() const { return m_hInstance; }
        Vector2   GetSize()   const { return m_windowSize; }

    private:

        HINSTANCE   m_hInstance;
        HWND        m_handle;
        WNDCLASS    m_class;

        Vector2     m_windowPosition;
        Vector2     m_windowSize;

        static void SetScreenToCenter(HWND _hwnd);
        static LRESULT CALLBACK WinProc(HWND _hwnd, UINT _msg, WPARAM _wParam, LPARAM _lParam);

        void Create();
        void Show();

    };
}