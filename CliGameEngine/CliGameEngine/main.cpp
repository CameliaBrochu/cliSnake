#include <stdio.h>
#include <list>
#include "CliGameEngine.h"
#include "Snake.h"

class snakeGame : public cliGE::CliGameEngine
{
public:
	using CliGameEngine::CliGameEngine;

	void onGameLoad() {
		this->snake.setDirection(RIGHT);

		Coords start = {10,10};
		this->snake.addToBody(start);

		Coords test1 = { 9,10 };
		this->snake.addToBody(test1);
		Coords test2 = { 8,10 };
		this->snake.addToBody(test2);
		Coords test3 = { 8,9 };
		this->snake.addToBody(test3);
		Coords test4 = { 8,8 };
		this->snake.addToBody(test4);
	}
	void onGameUpdate() {

		// A : 0x41
		if (keyPressed(0x41)) {
			this->snake.setDirection(LEFT);
		}
		// D : 0x44
		if (keyPressed(0x44)) {
			this->snake.setDirection(RIGHT);
		}
		// W : 0x57
		if (keyPressed(0x57)) {
			this->snake.setDirection(UP);
		}
		// S : 0x53
		if (keyPressed(0x53)) {
			this->snake.setDirection(DOWN);
		}

		this->snake.moveSnake();
	}

	void onGameDraw() {
		for (auto it = snake.getBody().begin(); it != snake.getBody().end(); it++)
		{
			if (it == snake.getBody().begin()) {
				writeCharAt('S', it->x, it->y);
			}
			else {
				writeCharAt('s', it->x, it->y);
			}
			
		}
	}
private:
	Snake snake;
};

int main() {

	snakeGame snakeGame(120, 60);
	snakeGame.start();

	return 0;
}