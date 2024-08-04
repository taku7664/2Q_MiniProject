#pragma once
#include "pch.h"
#include "Helper/Input/Input.h"
#include "System/Render/D2DRenderSystem.h"
#include "System/Window/WindowSystem.h"
#include "System/Game/GameSystem.h"
#include "System/Sound/FMODSystem.h"

#include "World/WorldManager.h"
#include "Resource/ResourceManager.h"
#include "Collision/CollisionManager.h"
#include "Collision/ButtonManager.h"

namespace Engine
{
	class Application
	{
	public:
		static void		Quit()			{ isQuit = true; }
		static Vector2  GetScreenSize() { return scrennSize; }

		void Initialize(HINSTANCE _hinstance, const WCHAR* _title, const int _width, const int _height);
		void Run();
		void Release();
	protected:
		template<class T> void SetGameSystem() {
			SAFE_DELETE(m_game) m_game = new T();
		}
	private:
		void FixedUpdate();
		void EarlyUpdate();
		void Update();
		void LateUpdate();
		void Render();
		void StateUpdate();
	private:
		Application*		m_aInstance;
		HINSTANCE			m_hInstance;
		WindowSystem*		m_window;
		GameSystem*			m_game;

		static bool			isQuit;
		static Vector2		scrennSize;
	};
}