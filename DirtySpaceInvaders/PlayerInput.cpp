#include "PlayerInput.h"
#include <windows.h>

bool PlayerInput::Left()
{
    return GetKeyState(VK_LEFT) < 0;
}

bool PlayerInput::Right()
{
    return GetKeyState(VK_RIGHT) < 0;
}

bool PlayerInput::Fire()
{
    if (GetKeyState(VK_SPACE) < 0 && !haveFired)
    {
        haveFired = true;
        return true;
    }
    else
    {
        haveFired = false;
    }
    return false;
}