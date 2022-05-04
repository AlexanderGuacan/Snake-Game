#include "WelcomeScreen.hpp"
#include "HandleConsole.hpp"
#include <windows.h>
#include <cstdio>
#include <conio.h>

const int TITLE_POSITION_X = INTERFACE_CENTER_X - 2;
const int TITLE_POSITION_Y = INTERFACE_CENTER_Y - 2;
const int PLAY_OPTION_POSITION_X = TITLE_POSITION_X + 1;
const int PLAY_OPTION_POSITION_Y = TITLE_POSITION_Y + 2;
const int QUIT_OPTION_POSITION_X = TITLE_POSITION_X + 1;
const int QUIT_OPTION_POSITION_Y = PLAY_OPTION_POSITION_Y + 1;

int renderWelcomeScreen() {
    system("cls");

    gotoxy(TITLE_POSITION_X, TITLE_POSITION_Y);
    printf("SNAKE GAME");

    gotoxy(PLAY_OPTION_POSITION_X, PLAY_OPTION_POSITION_Y);
    printf("> PLAY <");

    gotoxy(QUIT_OPTION_POSITION_X, QUIT_OPTION_POSITION_Y);
    printf("  QUIT");

    return input();
}

int input() {
    bool hasPressedEnter = false;
    
    int optionSelected = PLAY_OPTION;
    int cursorPosition = PLAY_OPTION_POSITION_Y;

    while (!hasPressedEnter) {
        if (kbhit()) {
            int keyPressed = getch();

            if (keyPressed == 0 || keyPressed == 224)
                keyPressed = 256 + getch();

            switch (keyPressed) {
                case UP_KEY:
                    if (cursorPosition > PLAY_OPTION_POSITION_Y)
                        cursorPosition--;

                    break;

                case DOWN_KEY:
                    if (cursorPosition < QUIT_OPTION_POSITION_Y)
                        cursorPosition++;

                    break;

                case ENTER_KEY:
                    hasPressedEnter = true;
                    break;
            }

            switch (cursorPosition) {
                case PLAY_OPTION_POSITION_Y:
                    optionSelected = renderPlayOptionSelected();
                    break;

                case QUIT_OPTION_POSITION_Y:
                    optionSelected = renderQuitOptionSelected();
                    break;
            }
        }
    }

    return optionSelected;
}

int renderPlayOptionSelected() {
    gotoxy(PLAY_OPTION_POSITION_X, PLAY_OPTION_POSITION_Y);
    printf("%c PLAY %c", '>', '<');

    gotoxy(QUIT_OPTION_POSITION_X, QUIT_OPTION_POSITION_Y);
    printf("%c QUIT %c", ' ', ' ');

    return PLAY_OPTION;
}

int renderQuitOptionSelected() {
    gotoxy(PLAY_OPTION_POSITION_X, PLAY_OPTION_POSITION_Y);
    printf("%c PLAY %c", ' ', ' ');

    gotoxy(QUIT_OPTION_POSITION_X, QUIT_OPTION_POSITION_Y);
    printf("%c QUIT %c", '>', '<');

    return QUIT_OPTION;
}