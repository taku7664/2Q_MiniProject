#include "pch.h"
#include "Application.h"

namespace Engine
{
	bool Application::isQuit = false;
	Vector2 Application::scrennSize = { 0,0 };

	void Application::Initialize(HINSTANCE _hinstance, const WCHAR* _title, const int _width, const int _height)
	{
		m_game = nullptr;
		m_hInstance = _hinstance;
		scrennSize = { _width , _height };

		m_window = new WindowSystem(_hinstance, _title, Vector2(_width, _height));
		m_window->Initialize();
		D2DRenderSystem::Initialize(m_window);
		FMODSystem::Initialize();

		Input::Initialize(m_window);
		Time::Initialize();
	}

	void Application::Run()
	{
		MSG msg;
		while (!isQuit)
		{
			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT) break;
				else
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
			else
			{
				Time::Update();
				FixedUpdate();
				EarlyUpdate();
				Update();
				LateUpdate();
				StateUpdate();
				Render();
			}
		}
	}

	void Application::Release()
	{
		WorldManager::Release();
		D2DRenderSystem::Release();
		SAFE_DELETE(m_game);
		SAFE_DELETE(m_window);
	}

	void Application::FixedUpdate()
	{
		static float deltaCount;
		deltaCount += Time::deltaTime;
		while (deltaCount >= 0.02f)
		{
			if (CollisionManager::ProcessCycle == 0)
				CollisionManager::CollsionProcess();
			if (m_game) m_game->FixedUpdate();
			WorldManager::FixedUpdate();
			deltaCount -= 0.02f;
		}
	}

	void Application::EarlyUpdate()
	{
		if (CollisionManager::ProcessCycle == 1)
			CollisionManager::CollsionProcess();
		
		if (m_game) m_game->EarlyUpdate();
		WorldManager::EarlyUpdate();
		ButtonManager::EarlyUpdate();
	}

	void Application::Update()
	{
		if (m_game) m_game->Update();
		WorldManager::Update();
		FMODSystem::Update();
	}

	void Application::LateUpdate()
	{
		if (CollisionManager::ProcessCycle == 2)
			CollisionManager::CollsionProcess();
		if (m_game) m_game->LateUpdate();
		WorldManager::LateUpdate();
		ButtonManager::LateUpdate();
	}

	void Application::StateUpdate()
	{
		WorldManager::StateUpdate();
	}

	void Application::Render()
	{
		D2DRenderSystem::BeginRender();
		WorldManager::Render();
		D2DRenderSystem::EndRender();
	}
}