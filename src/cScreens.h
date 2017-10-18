#ifndef CSCREENS_INCLUDED
#define CSCREENS_INCLUDED

#include <SFML\Graphics.hpp>

class cScreen {
public: 
	virtual int Run(sf::RenderWindow &App) = 0; 
};


#endif // CSCREENS_INCLUDED