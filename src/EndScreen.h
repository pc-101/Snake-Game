#ifndef ENDSCREEN_INCLUDED
#define ENDSCREEN_INCLUDED

#include "cScreens.h"

class EndScreen : public cScreen {
public: 
	EndScreen(int num); 
	virtual int Run(sf::RenderWindow &App); 
private: 
	int count; 
};


#endif  // ENDSCREEN_INCLUDED