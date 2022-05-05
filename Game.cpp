#include "Game.hpp"
#include "GameInterface.hpp"
#include "Snake.hpp"

Snake snake = Snake();

void startGame() {
    drawGameInterface();

    bool gameOver = false;
    while (!gameOver) {
        gameLogic();
    }
}

void gameLogic() {
    snake.move();
}