#include "HandleConsole.hpp"
#include "WelcomeScreen.hpp"
#include <iostream>

int main() {
    setConsoleCursorInvisible();
    bool exit = false;

    while (!exit) {
        switch (renderWelcomeScreen()) {
            case PLAY_OPTION:
                // Initialize game
                break;

            case QUIT_OPTION:
                exit = true;
                break;
        }
    }

    return 0;
}