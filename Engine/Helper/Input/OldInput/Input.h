#pragma once
#include "Key.h"
#include "Mouse.h"

namespace Engine
{
	class WindowSystem;

	enum class InputType
	{
		None,
		KeyBoard,
		Mouse,
	};

	class Input
	{
	public:

		static void Initialize(WindowSystem* _window);

		static void GetKeyDown(HRAWINPUT hRawInput);
		static void GetKeyUp(HRAWINPUT hRawInput);
		static void GetMouseMove(HRAWINPUT hRawInput);

		static void KeyIsDown(int _code, HANDLE _handle);
		static void KeyIsHold(int _code, HANDLE _handle);
		static void KeyIsUp(int _code, HANDLE _handle);

	private:

		static WindowSystem* m_targetWindow;
		static std::unordered_map<HANDLE, InputDevice*>   m_inputDevices;

		static std::vector<BYTE> GetInputBuffer(HRAWINPUT hRawInput);
		template <class T>
		static T* GetHandle(HANDLE _handle)
		{
			auto it = m_inputDevices.find(_handle);
			if (it == m_inputDevices.end())
			{
				// 디바이스가 없으면 새로 생성
				T* newInput = new T();
				m_inputDevices[_handle] = newInput;
				return newInput;
			}
			else
			{
				// 디바이스가 존재하면 타입 캐스팅
				T* input = dynamic_cast<T*>(it->second);
				return input;
			}
		}
	};

	
}
