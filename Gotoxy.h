#pragma once
#include <Windows.h>

inline void gotoxy(int x, int y)
{
    COORD c = { static_cast<short>(x), static_cast<short>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}