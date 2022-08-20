#include "Snake.h"

Direction Snake::getDirection() const
{
	return this->direction;
}

void Snake::setDirection(Direction d) {
	this->direction = d;
}


const std::list<Coords>& Snake::getBody() const {
	return this->body;
}

void Snake::addToBody(Coords c) {
	this->body.push_back(c);
}
