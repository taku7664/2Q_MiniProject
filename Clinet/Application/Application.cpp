#include "Application.h"

//void Application::Initialize(HINSTANCE _hinstance, Rect_F _size, const wchar_t* _title)
//{
//	GameApp::Initialize(_hinstance, _size, _title);
//}

void GameApplication::Initialize(HINSTANCE _hinstance, const WCHAR* _title, const int _width, const int _height)
{
	__super::Initialize(_hinstance, _title, _width, _height);

}

void GameApplication::LoadWorld()
{
}
