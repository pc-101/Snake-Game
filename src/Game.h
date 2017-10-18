#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "GameObject.h"
#include "cScreens.h"

class Game : public cScreen {
public: 
	Game(); 
	bool isGameOver();
	bool isSnakeCollision(); 
	void maintainSnakeSize(); 
	virtual int Run(sf::RenderWindow &App); 

	  // Getters
	const int getWidth(); 
	const int getHeight(); 
	const int getRenderWidth(); 
	const int getRenderHeight(); 

private: 
	const int WIDTH			= 30; 
	const int HEIGHT		= 20; 
	const int SCALE			= 16; 
	const int RENDER_WIDTH	= WIDTH * SCALE; 
	const int RENDER_HEIGHT = HEIGHT * SCALE; 

	Snake s[100];
	Fruit f;		
	bool gameOver; 
	bool gameWin; 

	void setup();
};

#endif // GAME_INCLUDED