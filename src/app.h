#pragma once

#include <map>
#include <string>

extern bool godMode;
extern bool endlessAmmo;
extern bool gravity;
extern bool recoil;

namespace app
{
    void initializeImGui();
    void renderImGui();
    void initializeHook();
}