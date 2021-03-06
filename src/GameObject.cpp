#include <random>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Game.h"

Coord::Coord() : posx(0), posy(0)
{}

Coord::Coord(int x, int y) : posx(x), posy(y)
{}

bool Coord::operator==(const Coord &rhs) const
{
	if (this->posx == rhs.posx && this->posy == rhs.posy)
		return true; 
	else 
		return false; 
}

/************
  GameObject
*************/

gameObject::gameObject() : isAlive(true)
{
	this->pair.posx = 1; 
	this->pair.posy = 1;  
}

gameObject::gameObject(int x, int y) : isAlive(true)
{
	this->pair.posx = x;
	this->pair.posy = y;
}

const int gameObject::getX() const
{
	return pair.posx;
}

const int gameObject::getY() const
{
	return pair.posy; 
}

const bool gameObject::isDead() const
{
	return isAlive; 
}

void gameObject::setDead()
{
	isAlive = false; 
}

void gameObject::moveObject(int x, int y)
{
	pair.posx += x; 
	pair.posy += y; 
}

void gameObject::setObject(int x, int y)
{
	pair.posx = x; 
	pair.posy = y; 
}

/************
    Snake
*************/
Snake::Snake() : gameObject()
{
	m_size = 1; 
}

Snake::Snake(int x, int y)
	: gameObject(x, y)
{
	m_size = 1; 
	dir = RIGHT; 
}

void Snake::changeDirection(Direction d)
{
	  // Only change direction if the snake doesn't backtrack
	if (d != getOppositeDir(dir))
		dir = d; 
}

void Snake::animate()
{
	gameObject* g = this;
	switch (dir)
	{
	case LEFT:
		moveObject(-1, 0); 
		break;
	case UP:
		moveObject(0, -1); 
		break;
	case RIGHT:
		moveObject(1, 0); 
		break;
	case DOWN:
		moveObject(0, 1); 
		break;
	default:
		break;
	}
}

int Snake::getSize()
{
	return m_size; 
}

Direction Snake::getDir()
{
	return dir;
}

Direction Snake::getOppositeDir(Direction d) {
	switch (d)
	{
	case LEFT:
		return RIGHT; 
		break;
	case UP:
		return DOWN; 
		break;
	case RIGHT:
		return LEFT; 
		break;
	case DOWN:
		return UP; 
		break;
	default:
		break;
	}
}

void Snake::getBigger()
{
	m_size++; 
}

/************
	Fruit
*************/

Fruit::Fruit() : gameObject()
{
}

Fruit::Fruit(int x, int y) : gameObject(x, y)
{
}

void Fruit::setNewFruit(int x, int y)
{
	gameObject* g = this; 
	g->setObject(x, y); 
}

/************
	Wall
*************/
Wall::Wall(int x, int y)
{ 
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			if (i == 0 || j == 0 || i == y - 1 || j == x - 1)
			{
				Coord c(i, j); 
				v.push_back(c); 
			}
}

bool Wall::isWall(int x, int y)
{ 
	Coord c(y, x); 

	for (std::vector<Coord>::iterator it = v.begin(); it != v.end(); it++)
		if (*it == c)
			return true;

	return false; 
}


