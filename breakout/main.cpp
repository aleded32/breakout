//include files
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "paddle.h"
#include "bricks.h"


//main 
int main()
{
	//clock
	sf::Clock clock;

	//collision boolean (subject to movement)
	bool ispaddleCollidingEdge = false;

	//window
	sf::RenderWindow app(sf::VideoMode(400,700), "breakout");

	//class pointers
	paddle *ptrPaddle;
	bricks *ptrBricks;

	//classes
	paddle Paddle(clock);
	bricks Bricks;

	//point to class address
	ptrPaddle = &Paddle;
	ptrBricks = &Bricks;

	sf::Event e;

	while(app.isOpen())
	{
		while (app.pollEvent(e))
		{
			if(e.type == sf::Event::Closed)
			app.close();
		}

		ptrPaddle ->worldCollision();

		ptrPaddle ->paddleMove();

		app.clear();

		ptrPaddle ->drawPaddle(app);

		ptrBricks ->spawnBricks(app);

		app.display();

	}






	return 0;
	getchar();
}