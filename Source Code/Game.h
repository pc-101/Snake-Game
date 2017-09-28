#ifndef GAME_H
#define GAME_H

#include "GameObject.h"

class Game {
public: 
	Game(); 
	bool isGameOver();
	void run(); 
	void maintainSnakeSize(); 

	  // Getters
	const int getWidth(); 
	const int getHeight(); 

private: 
	const int WIDTH			= 30; 
	const int HEIGHT		= 20; 
	const int SCALE			= 16; 
	const int RENDER_WIDTH	= WIDTH * SCALE; 
	const int RENDER_HEIGHT = HEIGHT * SCALE; 

	Snake s[100];
	Fruit f;		
	bool gameOver; 

	void setup();
};

#endif // GAME_H