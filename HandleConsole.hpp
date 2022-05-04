#ifndef HANDLECONSOLE_HPP
#define HANDLECONSOLE_HPP

const int LEFT_SPACING = 15;
const int UP_SPACING = 2;
const int INTERFACE_WIDTH = 75;
const int INTERFACE_HEIGHT = 25;
const int INTERFACE_CENTER_X = LEFT_SPACING + INTERFACE_WIDTH / 2;
const int INTERFACE_CENTER_Y = UP_SPACING + INTERFACE_HEIGHT / 2;
const int LEFT_KEY = 331;
const int RIGHT_KEY = 333;
const int UP_KEY = 328;
const int DOWN_KEY = 336;
const int ENTER_KEY = 13;
const int ESCAPE_KEY = 27;

void gotoxy(int x, int y);
void setConsoleCursorInvisible();

#endif