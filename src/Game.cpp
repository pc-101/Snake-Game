#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include "Game.h" 

/************
	Game
*************/

Game::Game() : gameOver(false), gameWin(false)
{
	s[0].setObject(1, 1);					// Initialize member snake variable
	f.setObject(WIDTH / 2, HEIGHT / 2);		// Construct fruit in the middle of the board
}

void Game::setup() 
{
	  // Render the window for events
	sf::RenderWindow renderWindow(sf::VideoMode(RENDER_WIDTH, RENDER_HEIGHT), "SnakeGame.exe");
	sf::Event e;
	sf::Clock clock; 

	Wall w(WIDTH, HEIGHT);				// Construct wall for the game

	  // Pseudo random number generator
	srand(time(NULL)); 

	  // Textures and Sprites

	/***********************************
	* sprite1 and texture1 is the board, 
	* sprite2 and texture2 is the snake,
	* sprite3 and texture3 is the fruit
	************************************/
	sf::Texture texture1; 
	texture1.loadFromFile("images/white.png"); 
	sf::Sprite sprite1(texture1); 

	sf::Texture texture2; 
	texture2.loadFromFile("images/blue.png"); 
	sf::Sprite sprite2(texture2); 

	sf::Texture texture3;
	texture3.loadFromFile("images/green.png");
	sf::Sprite sprite3(texture3);
	

      // Main render window loop
	while (renderWindow.isOpen()) {
		while (renderWindow.pollEvent(e)) {
			if (e.type == sf::Event::EventType::Closed)
				renderWindow.close();
		}
		renderWindow.clear();

		  // Draw walls
		for (int i = 0; i < HEIGHT; i++)
			for (int j = 0; j < WIDTH; j++) {
				if (w.isWall(j, i)) {
					sprite1.setPosition(float(j * SCALE), float(i * SCALE));
					renderWindow.draw(sprite1);
				}
				if (f.getX() == j && f.getY() == i) {
					sprite3.setPosition(float(j * SCALE), float(i * SCALE));
					renderWindow.draw(sprite3);
				}
			}

		  // Draw out the snake 
		for (int i = 0; i < s[0].getSize(); i++)
		{
			sprite2.setPosition(float(s[i].getX() * SCALE), float(s[i].getY() * SCALE)); 
			renderWindow.draw(sprite2); 
		}

		  // Animate snake
		if (clock.getElapsedTime().asMicroseconds() > 1.0f) {
			maintainSnakeSize(); 

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return; 

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
				s[0].changeDirection(LEFT); 
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
				s[0].changeDirection(UP);
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
				s[0].changeDirection(RIGHT);
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
				s[0].changeDirection(DOWN);
			

			s[0].animate();
		}

		renderWindow.display();

		  // Snake-Wall collision or Snake self-collision ends the game
		if (w.isWall(s[0].getX(), s[0].getY()) || isSnakeCollision()) {
			gameOver = true;
			renderWindow.close();
		}

		  // If the snake reaches maximum size, the user wins the game
		if (s[0].getSize() == 100) {
			gameOver = true;
			gameWin = true; 
			renderWindow.close();
		}

		  // Randomize the new location of fruit
		if (s[0].getX() == f.getX() && s[0].getY() == f.getY()) {
			int randw, randh; 

			  // Generate value between ([0, WIDTH],[0, HEIGHT]), inclusive
			randw = rand() % (WIDTH - 1) + 1; 
			randh = rand() % (HEIGHT - 1) + 1; 

			  // Never generate our fruit on the wall
			while (w.isWall(randw, randh))
			{
				randw = rand() % (WIDTH - 1) + 1;
				randh = rand() % (HEIGHT - 1) + 1;
			}

			f.setNewFruit(randw, randh);
			s[0].getBigger();
		}		
	}
}

bool Game::isGameOver() 
{
	return gameOver; 
}

bool Game::isSnakeCollision()
{
	if (s[0].getSize() > 1)
		for (int i = s[0].getSize(); i > 0; i--)
			if (s[i].getX() == s[0].getX() && s[i].getY() == s[0].getY())
				return true;	// We have a collision
	return false; 
}

int Game::Run(sf::RenderWindow &App) 
{
	setup();

	if (!isGameOver())
		return 0;	// Return 0 for the Menu screen if game isn't over
	else if (isGameOver() && gameWin == true)
		return 3;	// Return 3 for the win screen
	else 
		return 2;	// Return 2 for the End Menu screen if game is over
}

void Game::maintainSnakeSize() 
{
	for (int i = s[0].getSize(); i > 0; i--)
		s[i].setObject(s[i - 1].getX(), s[i - 1].getY());
}

const int Game::getWidth()
{
	return WIDTH;
}

const int Game::getHeight()
{
	return HEIGHT; 
}

const int Game::getRenderWidth()
{
	return RENDER_WIDTH;
}

const int Game::getRenderHeight()
{
	return RENDER_HEIGHT; 
}

