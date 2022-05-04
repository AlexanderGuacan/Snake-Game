#include "HandleConsole.hpp"
#include "WelcomeScreen.hpp"
#include "GameInterface.hpp"
#include <iostream>

int main() {
    setConsoleCursorInvisible();

    bool exit = false;
    while (!exit) {
        switch (drawWelcomeScreen()) {
            case PLAY_OPTION:
                drawGameInterface();
                
                exit = true;
                break;

            case QUIT_OPTION:
                exit = true;
                break;
        }
    }

    return 0;
}