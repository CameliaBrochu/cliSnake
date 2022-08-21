#pragma once
#include <list>

enum Direction {UP, RIGHT, DOWN, LEFT};

struct Coords 
{
	size_t x,y;
};

class Snake
{
public:
	Direction getDirection() const;
	void setDirection(Direction d);

	std::list<Coords>& getBody();
	void addToBody(Coords c);

	void moveSnake();


private:
	Direction direction;
	std::list<Coords> body;
	size_t speed = 1;
};

