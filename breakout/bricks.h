#pragma once
#define MAX_ROW 3
#define MAX_COLUMN 6


//include files
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class bricks
{
private:
	 
	
	sf::RectangleShape block;


public:

	void spawnBricks(sf::RenderWindow& app);

	bricks();
	~bricks();

};