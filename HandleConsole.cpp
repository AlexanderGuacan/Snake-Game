#include "HandleConsole.hpp"
#include <windows.h>

void gotoxy(int x, int y) {
    HANDLE consoleIdentificator = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD cursorCoordinate;
    cursorCoordinate.X = x;
    cursorCoordinate.Y = y;

    SetConsoleCursorPosition(consoleIdentificator, cursorCoordinate);
}

void setConsoleCursorInvisible() {
    HANDLE consoleIdentificator = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = 1;
    
    SetConsoleCursorInfo(consoleIdentificator, &cursor);
}