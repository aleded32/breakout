#pragma once
#define MAX_ROW 20
#define MAX_COLUMN 5


//include files
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "player.h"

class bricks
{
private:
	 
	
	sf::RectangleShape block;
	sf::Color bricksColour[2];
	float time;

public:

	void spawnBricks(sf::RenderWindow& app, int bricksField[20][5]);
	void addBricks(sf::Clock& clock, int bricksField[20][5], lives *Lives);

	bricks();
	~bricks();

};