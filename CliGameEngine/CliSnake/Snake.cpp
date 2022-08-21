#include "Snake.h"

Direction Snake::getDirection() const
{
	return this->direction;
}

void Snake::setDirection(Direction d) {
	this->direction = d;
}


std::list<Coords>& Snake::getBody() {
	return this->body;
}

void Snake::addToBody(Coords c) {
	this->body.push_back(c);
}

void Snake::moveSnake()
{
	Coords head = getBody().front();

	Coords newCoords = { 0,0 };
	if (getDirection() == LEFT) {
		newCoords = { head.x - 1, head.y };
	}


	if (getDirection() == RIGHT) {
		newCoords = { head.x + 1, head.y };
	}


	if (getDirection() == UP) {
		newCoords = { head.x, head.y - 1 };
	}


	if (getDirection() == DOWN) {
		newCoords = { head.x, head.y + 1 };
	}

	Coords prevCoords = { head.x, head.y };
	for (auto it = getBody().begin(); it != getBody().end(); it++)
	{
		prevCoords = { it->x, it->y };

		it->x = newCoords.x;
		it->y = newCoords.y;

		newCoords.x = prevCoords.x;
		newCoords.y = prevCoords.y;
	}
}
