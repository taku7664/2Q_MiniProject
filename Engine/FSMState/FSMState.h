#pragma once

namespace Engine
{
	class FiniteStateMachine;

	class FSMState abstract
	{
	private:

		std::string m_name;

	public:

		FiniteStateMachine* FSM;

		virtual void Start() {}				// �߰��� �� ȣ��Ǵ� �Լ�
		virtual void StateEnter() = 0;		// ���¿� ������ �� �ѹ� ȣ��Ǵ� �Լ�
		virtual void StateUpdate() = 0;		// ���°� �������� �� �� ������Ʈ���� ȣ��Ǵ� �Լ�
		virtual void StateExit() = 0;		// ���¸� ��� �� �ѹ� ȣ��Ǵ� �Լ�

		virtual void OnAnimationEnter(int _index) {}

		void SetName(const std::string& _name) { m_name = _name; }
		std::string GetName() const { return m_name; }
	};

	// owner�� ���ϰ� ���� ���ؼ� ����ϴ� �Լ�
	template<typename T>
	class Template_FSMState : public FSMState
	{
	private:
	public: T* owner;
	};
}