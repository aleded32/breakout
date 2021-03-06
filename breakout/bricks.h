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
	sf::Color bricksColour[4];
	float timeBricks;
	int randChancePW;
	int ChancePW;
	int randBrick;
	int randRow;
	float randBrickTime;
	sf::Clock randClock;

public:

	

	void spawnBricks(sf::RenderWindow& app, int bricksField[20][5], lives *Lives);
	void addBricks(sf::Clock& clock, int bricksField[20][5], lives *Lives);

	bricks();
	~bricks();

};