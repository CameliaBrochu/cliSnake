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
	}
	void onGameUpdate() {

	}

	void onGameDraw() {
		for (auto it = snake.getBody().begin(); it != snake.getBody().end(); it++)
		{
			writeCharAt('s', it->x, it->y);
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