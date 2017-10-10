#ifndef GAMEOBJ_INCLUDED
#define GAMEOBJ_INCLUDED

#include <vector>

struct Coord {
	Coord(); 
	Coord(int x, int y); 
	bool operator==(const Coord& rhs) const; 

	int posx;
	int posy;
};

enum Direction { LEFT, UP, RIGHT, DOWN };

  // Base Class
class gameObject {
public: 
	gameObject();						// Default constructor
	gameObject(int x, int y);			// Secondary constructor

	  // Getters
	int getX(); 
	int getY(); 
	bool isDead(); 
	void setDead(); 

	  // Setters
	void moveObject(int x, int y);		// Move object by incrementing pair(x,y) values by corresponding x,y params
	void setObject(int x, int y);
private:
	  // Holds the coordinates of our gameObject
	Coord pair;
	bool isAlive;
};

  /**************************
  * Subclasses of gameObject 
  ***************************/

class Snake : public gameObject {
public: 
	Snake(); 
	Snake(int x, int y);  
	void changeDirection(Direction d); 
	void animate();

	  // Getters
	int getSize(); 
	Direction getDir(); 
	Direction getOppositeDir(Direction d); 

	  // Setters
	void getBigger(); 
private: 
	int m_size;
	Direction dir; 
};

class Fruit : public gameObject {
public: 
	Fruit(); 
	Fruit(int x, int y);
	void setNewFruit(int x, int y);  
};

class Wall : public gameObject {
public: 
	Wall(int x, int y); 
	bool isWall(int x, int y); 

private: 
	std::vector<Coord> v; 
};


#endif // GAMEOBJ_INCLUDED
