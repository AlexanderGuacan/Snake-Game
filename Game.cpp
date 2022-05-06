#include "Game.hpp"
#include "GameInterface.hpp"
#include "Snake.hpp"

Snake snake = Snake(8);

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