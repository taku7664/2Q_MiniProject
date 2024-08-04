#include "Application.h"
#include "World/Test.h"

void GameApplication::Initialize(HINSTANCE _hinstance, const WCHAR* _title, const int _width, const int _height)
{
	__super::Initialize(_hinstance, _title, _width, _height);
	LoadWorld();
}

void GameApplication::LoadWorld()
{
	Engine::WorldManager::CreateWorld<World::Test>("Test", WorldTag::Default);
	Engine::WorldManager::ChangeWorld("Test");
}
