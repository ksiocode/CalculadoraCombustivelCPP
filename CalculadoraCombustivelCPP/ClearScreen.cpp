#include "Header.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

int clear_screen()
{
    HANDLE hStdOut;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos = { 0, 0 };
    SetConsoleCursorPosition(hStdOut, pos);

    DWORD mode = 0;
    if (!GetConsoleMode(hStdOut, &mode))
    {
        return ::GetLastError();
    }

    const DWORD originalMode = mode;
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;


    if (!SetConsoleMode(hStdOut, mode))
    {
        return ::GetLastError();
    }

    DWORD written = 0;
    PCWSTR sequence = L"\x1b[2J";
    if (!WriteConsoleW(hStdOut, sequence, (DWORD)wcslen(sequence), &written, NULL))
    {

        SetConsoleMode(hStdOut, originalMode);
        return ::GetLastError();
    }

    SetConsoleMode(hStdOut, originalMode);
    return 0;

}