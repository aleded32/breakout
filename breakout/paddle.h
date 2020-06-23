#pragma once

//include files
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "player.h"

class paddle
{
private:

	
	float dt;


public:
	
		float x,y;
	sf::RectangleShape Paddle;
	paddle(sf::Clock& clock);
	~paddle();
	
	
	void drawPaddle(sf::RenderWindow& app);
	void paddleMove(lives *Lives);
	void worldCollision();

};