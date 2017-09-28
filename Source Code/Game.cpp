#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "Game.h" 

/************
	Game
*************/

Game::Game()
{
	s[0].setObject(1, 1);					// Initialize member snake variable
	f.setObject(WIDTH / 2, HEIGHT / 2);		// Construct fruit in the middle of the board
	gameOver = false; 
}

void Game::setup() {
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

		  // Draw
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
		  // Have to first find a way to access the m_snake vector and iterate through
		for (int i = 0; i < s[0].getSize(); i++)
		{
			sprite2.setPosition(float(s[i].getX() * SCALE), float(s[i].getY() * SCALE)); 
			renderWindow.draw(sprite2); 
		}

		  // Animate snake
		if (clock.getElapsedTime().asMicroseconds() > 1.0f) {
			maintainSnakeSize(); 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				s[0].changeDirection(LEFT); 
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				s[0].changeDirection(UP);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				s[0].changeDirection(RIGHT);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				s[0].changeDirection(DOWN);
			}
			s[0].animate();
		}

		renderWindow.display();

		if (w.isWall(s[0].getX(), s[0].getY())) {
			gameOver = true;
			renderWindow.close();
		}
		if (s[0].getX() == f.getX() && s[0].getY() == f.getY()) {
			f.setNewFruit((rand() % (WIDTH - 1) + 1), (rand() % (HEIGHT - 1)) + 1);
			s[0].getBigger();
		}		
	}
}

bool Game::isGameOver() {
	return gameOver; 
}

void Game::run() {
	setup(); 
}

void Game::maintainSnakeSize() {
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
