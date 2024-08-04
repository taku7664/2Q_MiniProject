#include "Application.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    GameApplication App;

    Debug::Active();
    App.Initialize(hInstance, L"Test", 1024, 768);
    App.Run();
    App.Release();
    Debug::Close();
    return 0;
}
