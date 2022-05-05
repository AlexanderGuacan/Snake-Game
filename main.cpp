#include "HandleConsole.hpp"
#include "WelcomeScreen.hpp"
#include "Game.hpp"

int main() {
    setConsoleCursorInvisible();

    bool exit = false;
    while (!exit) {
        switch (drawWelcomeScreen()) {
            case PLAY_OPTION:
                startGame();
                break;

            case QUIT_OPTION:
                exit = true;
                break;
        }
    }

    return 0;
}