#include "Test.h"
#include "ScriptHeaders.h"

// ���带 ���� �� �� �ѹ� ȣ��
void World::Test::WorldLoad()
{
	Engine::Actor* actor = CreateObject<Engine::Actor>("Test", LayerTag::UI);
	actor->AddComponent<TestButton>();
}

// ���带 ������ �� �� �ѹ�
void World::Test::WorldDestroy()
{
}

// ���� ��ü �ɶ� �ѹ�
void World::Test::WorldEnter()
{
}

// ���� ���� �� �ѹ�
void World::Test::WorldExit()
{
}
