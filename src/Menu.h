#ifndef MENU_INCLUDED
#define MENU_INCLUDED

#include "cScreens.h"

class Menu : public cScreen {
public: 
	Menu(); 
	virtual int Run(sf::RenderWindow &App); 
	
private:
	int alpha_max; 
	int alpha_div; 
	bool playing; 
};

#endif // MENU_INCLUDED