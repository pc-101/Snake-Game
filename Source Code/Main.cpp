#include "Screens.h"

int main() {
	Game		g; 
	Menu		m; 
	EndScreen	e; 
	std::vector<cScreen*> Screens; 
	int screen = 0; 

	  // Render initial window
	sf::RenderWindow App(sf::VideoMode(g.getRenderWidth(), g.getRenderHeight()), "SnakeGame.exe"); 

	  // Make menu purely keyboard-based
	App.setMouseCursorVisible(false); 

	  // Load screens into vector
	Screens.push_back(&m); 
	Screens.push_back(&g); 
	Screens.push_back(&e); 

	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App); 
	}

	return 0; 
}