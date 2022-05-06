#include "Game.hpp"
#include "GameInterface.hpp"
#include "Snake.hpp"

Snake snake = Snake(8);
Food food = Food();

void startGame() {
    drawGameInterface();
    food.spawn();

    bool gameOver = false;
    while (!gameOver) {
        gameOver = gameLogic();
    }

    snake.setDefaultProperties();
    food.setRandomPosition();
}

bool gameLogic() {
    snake.move();

    if (snake.hasEating(food)) {
        updateGameInterface(snake.getScore());
        food.setRandomPosition();
        food.spawn();
    }

    return snake.hasCollidedWithWall();
}