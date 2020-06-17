#pragma once

//include files
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class paddle
{
private:

	sf::RectangleShape Paddle;
	float dt;
	float x,y;

public:

	paddle(sf::Clock& clock);
	~paddle();
	
	
	void drawPaddle(sf::RenderWindow& app);
	void paddleMove();
	void worldCollision();

};