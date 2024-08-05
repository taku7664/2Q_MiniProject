#include "Application.h"
#include "World/Test.h"

void GameApplication::Initialize(HINSTANCE _hinstance, const WCHAR* _title, const int _width, const int _height)
{
	__super::Initialize(_hinstance, _title, _width, _height);
	LoadWorld();
}

void GameApplication::LoadWorld()
{
	// 월드를 생성
	Engine::WorldManager::CreateWorld<World::Test>("Test", WorldTag::Default);
	// 월드를 교체
	Engine::WorldManager::ChangeWorld("Test");
}
