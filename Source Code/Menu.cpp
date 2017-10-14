#include <iostream>
#include "Menu.h"

Menu::Menu()
{
	alpha_max = 3 * 255; 
	alpha_div = 3; 
	playing = false;
}

int Menu::Run(sf::RenderWindow &App)
{
	int alpha = 0; 
	int menu = 0; 
	sf::Event e; 
	sf::Texture t; 
	sf::Sprite s; 
	sf::Font f; 

	  // Menu options
	sf::Text menu1;		// Play
	sf::Text menu2;		// Quit
	sf::Text menu3;		// Continue

	if (!t.loadFromFile("images/background.png"))
	{
		std::cerr << "Error loading background.png" << std::endl;
		return (-1);
	}
	s.setTexture(t);

	if (!f.loadFromFile("fonts/font.ttf"))
	{
		std::cerr << "Error loading font.ttf" << std::endl;
		return (-1); 
	}

	  // Menu settings
	menu1.setFont(f); 
	menu1.setCharacterSize(20); 
	menu1.setString("Play"); 
	menu1.setPosition({ 280.f, 160.f }); 

	menu2.setFont(f);
	menu2.setCharacterSize(20);
	menu2.setString("Quit Game");
	menu2.setPosition({ 280.f, 220.f });

	menu3.setFont(f);
	menu3.setCharacterSize(20);
	menu3.setString("Continue");
	menu3.setPosition({ 280.f, 160.f });

	  // Poll for events
	while (App.isOpen())
	{
		while (App.pollEvent(e)) {
			// Window closed
			if (e.type == sf::Event::EventType::Closed)
				App.close();

			if (e.type == sf::Event::KeyPressed)
			{
				switch (e.key.code)
				{
				case sf::Keyboard::Up:
					menu = 0;
					break;
				case sf::Keyboard::Down:
					menu = 1;
					break;
				case sf::Keyboard::Return:
					if (menu == 0)
					{
						playing = true;
						return 1;
					}
					else
						return -1;
					break;
				default:
					break;
				}
			}
		}

		// Shows the user which option he/she is highlighting
		if (menu == 0)
		{
			menu1.setFillColor(sf::Color(255, 0, 0, 255));
			menu2.setFillColor(sf::Color(255, 255, 255, 255));
			menu3.setFillColor(sf::Color(255, 0, 0, 255));
		}
		else
		{
			menu1.setFillColor(sf::Color(255, 255, 255, 255));
			menu2.setFillColor(sf::Color(255, 0, 0, 255));
			menu3.setFillColor(sf::Color(255, 255, 255, 255));
		}

		// Clear screen
		App.clear();

		// Draw
		App.draw(s);
		if (playing)
			App.draw(menu3);
		else
			App.draw(menu1);
		App.draw(menu2);

		App.display();

	}
	return -1; 
}
