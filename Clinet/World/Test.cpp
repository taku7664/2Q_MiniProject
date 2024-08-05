#include "Test.h"
#include "ScriptHeaders.h"

// 월드를 만들 때 딱 한번 호출
void World::Test::WorldLoad()
{
	Engine::Actor* actor = CreateObject<Engine::Actor>("Test", LayerTag::UI);
	actor->AddComponent<TestButton>();
}

// 월드를 삭제될 떄 딱 한번
void World::Test::WorldDestroy()
{
}

// 월드 교체 될때 한번
void World::Test::WorldEnter()
{
}

// 월드 나갈 때 한번
void World::Test::WorldExit()
{
}
