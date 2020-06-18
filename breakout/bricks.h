#pragma once
#define MAX_ROW 20
#define MAX_COLUMN 5


//include files
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class bricks
{
private:
	 
	
	sf::RectangleShape block;
	sf::Color bricksColour[2];

public:

	void spawnBricks(sf::RenderWindow& app, int bricksField[20][5]);

	bricks();
	~bricks();

};