#include "EndScreen.h"
#include <iostream>

int EndScreen::Run(sf::RenderWindow &App) {
	sf::Event e;
	sf::Sprite s; 
	sf::Font f;

	// Menu options
	sf::Text menu1;		// Game Over
	sf::Text menu2;		// "Hit enter to close the game"

	s.setColor(sf::Color(255, 255, 255, 0));

	if (!f.loadFromFile("fonts/font.ttf"))
	{
		std::cerr << "Error loading font.ttf" << std::endl;
		return (-1);
	}

	// Menu settings
	menu1.setFont(f);
	menu1.setCharacterSize(20);
	menu1.setString("GAME OVER");
	menu1.setPosition({ 200.f, 160.f });

	menu2.setFont(f);
	menu2.setCharacterSize(15);
	menu2.setString("HIT ENTER TO CLOSE THE GAME");
	menu2.setPosition({ 200.f, 180.f });

	// Poll for events
	while (App.isOpen())
	{
		while (App.pollEvent(e)) {
			// Window closed
			if (e.type == sf::Event::EventType::Closed)
				App.close();

			if (e.type == sf::Event::KeyPressed)
				if (e.key.code == sf::Keyboard::Return)
					return -1;

			// Shows the user which option he/she is highlighting

			menu1.setFillColor(sf::Color(255, 0, 0, 255));
			menu2.setFillColor(sf::Color(255, 255, 255, 255)); 

			// Clear screen
			App.clear();

			// Draw
			App.draw(s);
			App.draw(menu1);
			App.draw(menu2); 

			App.display();
		}
	}
	return -1;
}

