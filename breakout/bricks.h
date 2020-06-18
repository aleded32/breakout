#pragma once
#define MAX_ROW 3
#define MAX_COLUMN 6


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

	void spawnBricks(sf::RenderWindow& app, int bricksField[5][3]);

	bricks();
	~bricks();

};