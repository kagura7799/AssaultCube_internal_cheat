#include "app.h"
#include "imgui_hook.h"
#include "external/imgui/imgui.h"

bool godMode = false;
bool endlessAmmo = false;
bool gravity = false;
bool recoil = false;

namespace app
{
    void initializeImGui()
    {
        ImGui::StyleColorsDark();
    }

    void renderImGui()
    {
        ImGui::SetNextWindowSize(ImVec2(600, 400), 1);
        ImGui::Begin("Assault Cube cheat menu");

        ImGui::SetCursorPos(ImVec2(5, 25));
        ImGui::Checkbox("GodMode", &godMode);
        ImGui::SetCursorPos(ImVec2(5, 45));
        ImGui::Checkbox("Endless ammo (all guns)", &endlessAmmo);
        ImGui::SetCursorPos(ImVec2(5, 65));
        ImGui::Checkbox("Recoil", &recoil);

        ImGui::End();
    }

    void initializeHook()
    {
        ImGuiHook::Load(renderImGui, initializeImGui);
    }
}