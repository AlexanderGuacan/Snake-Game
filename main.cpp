#include "HandleConsole.hpp"
#include "WelcomeScreen.hpp"

int main() {
    setConsoleCursorInvisible();
    bool exit = false;

    while (!exit) {
        switch (drawWelcomeScreen()) {
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