#include "Test.h"
#include "ScriptHeaders.h"

void World::Test::WorldLoad()
{
	Engine::Actor* actor = CreateObject<Engine::Actor>("Test");
	actor->AddComponent<TestScript>();
}

void World::Test::WorldDestroy()
{
}

void World::Test::WorldEnter()
{
}

void World::Test::WorldExit()
{
}
