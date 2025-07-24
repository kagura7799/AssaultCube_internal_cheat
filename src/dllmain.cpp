#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "app.h"
#include "imgui_hook.h"
#include "cheat/cheat.hpp"

static HMODULE g_hModule    = nullptr;
static bool    g_isDetached = false;

DWORD WINAPI MainThread(LPVOID lpThreadParameter)
{
    g_hModule = (HMODULE)lpThreadParameter;
    app::initializeHook();

    while (!g_isDetached)
    {
        if (godMode)
            setPlayerHp(414);

        if (endlessAmmo)
            setEndlessAmmo(414);

        if (recoil)
            setRecoil();
    }

    return S_OK;
}

DWORD WINAPI ExitThread(LPVOID lpThreadParameter)
{
    if (!g_isDetached)
    {
        g_isDetached = true;
        ImGuiHook::Unload();
        FreeLibraryAndExitThread(g_hModule, TRUE);
    }
    return S_OK;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hMod);
        CreateThread(nullptr, 0, MainThread, nullptr, 0, nullptr);
        break;
    case DLL_PROCESS_DETACH:
        CreateThread(nullptr, 0, ExitThread, nullptr, 0, nullptr);
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    }
    return TRUE;
}