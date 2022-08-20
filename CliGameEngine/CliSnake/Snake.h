#pragma once
#include <list>

enum Direction {UP, RIGHT, BOTTOM, LEFT};

struct Coords 
{
	size_t x,y;
};

class Snake
{
public:
	Direction getDirection() const;
	void setDirection(Direction d);


	const std::list<Coords>& getBody() const;
	void addToBody(Coords c);


private:
	Direction direction;
	std::list<Coords> body;
	size_t speed = 1;
};

