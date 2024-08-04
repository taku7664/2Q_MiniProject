#include "pch.h"
#include "Input.h"
#include "System/Window/WindowSystem.h"

namespace Engine
{
    WindowSystem*                            Input::m_targetWindow;
    std::unordered_map<HANDLE, InputDevice*> Input::m_inputDevices{};

    void Input::Initialize(WindowSystem* _window)
    {
        m_targetWindow = _window;

        RAWINPUTDEVICE Rid[2];

        // Mouse
        Rid[0].usUsagePage = 0x01;          // HID_USAGE_PAGE_GENERIC
        Rid[0].usUsage = 0x02;              // HID_USAGE_GENERIC_MOUSE
        Rid[0].dwFlags = RIDEV_NOLEGACY;    // adds mouse and also ignores legacy mouse messages
        Rid[0].hwndTarget = _window->GetHandle();

        // Keyboard
        Rid[1].usUsagePage = 0x01;          // HID_USAGE_PAGE_GENERIC
        Rid[1].usUsage = 0x06;              // HID_USAGE_GENERIC_KEYBOARD
        Rid[1].dwFlags = RIDEV_NOLEGACY;    // adds keyboard and also ignores legacy keyboard messages
        Rid[1].hwndTarget = _window->GetHandle();

        if (RegisterRawInputDevices(Rid, 2, sizeof(Rid[0])) == FALSE)
        {
            assert(false && "Fail - Register Input");
        }
    }
    void Input::GetKeyDown(HRAWINPUT hRawInput)
    {
        std::vector<BYTE> lpb = GetInputBuffer(hRawInput);
        if (lpb.empty()) return;
        RAWINPUT* raw = (RAWINPUT*)lpb.data();

        Key* key = GetHandle<Key>(raw->header.hDevice);

        key->GetKeyDown(raw->data.keyboard.VKey);
    }
    void Input::GetKeyUp(HRAWINPUT hRawInput)
    {
        std::vector<BYTE> lpb = GetInputBuffer(hRawInput);
        if (lpb.empty()) return;
        RAWINPUT* raw = (RAWINPUT*)lpb.data();

        Key* key = GetHandle<Key>(raw->header.hDevice);

        key->GetKeyUp(raw->data.keyboard.VKey);
    }
    void Input::GetMouseMove(HRAWINPUT hRawInput)
    {
        std::vector<BYTE> lpb = GetInputBuffer(hRawInput);
        if (lpb.empty()) return;
        RAWINPUT* raw = (RAWINPUT*)lpb.data();

        Mouse* mouse = GetHandle<Mouse>(raw->header.hDevice);

        mouse->Update();
    }
    void Input::KeyIsDown(int _code, HANDLE _handle)
    {

    }
    std::vector<BYTE> Input::GetInputBuffer(HRAWINPUT hRawInput)
    {
       
        UINT data;
        // �Է� �������� ����Ʈ�� ���� - 0 ���ϸ� ����
        if (GetRawInputData(hRawInput, RID_INPUT, nullptr, &data, sizeof(RAWINPUTHEADER)) == -1 || data <= 0)
            return {};
        std::vector<BYTE> lpb(data); // �޸� �Ҵ�
        // �޾ƿ� ����Ʈ�� ������� �޸� ���� ����. ����� ����Ʈ�� �ٸ��� ����
        if (GetRawInputData(hRawInput, RID_INPUT, lpb.data(), &data, sizeof(RAWINPUTHEADER)) != data)
        {
            return {};
        }
        return lpb;
    }
}

//UINT GetRawInputData(
//    HRAWINPUT  hRawInput,    // RAW �Է� �ڵ�
//    UINT       uiCommand,    // ��û�� �������� ����
//    LPVOID     pData,        // �����͸� ������ ����
//    PUINT      pcbSize,      // �������� ũ��
//    UINT       cbSizeHeader  // RAWINPUTHEADER ����ü�� ũ��
//);