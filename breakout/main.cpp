//include files
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "paddle.h"
#include "bricks.h"
#include "ball.h"
#include "player.h"


//main 
int main()
{
	//clock
	sf::Clock clock;

	int bricksField[20][5] =
	{
		0,0,0,0,0,
		1,1,1,1,1,
		1,1,1,1,1,
		1,1,1,1,1,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	};


	//window
	sf::RenderWindow app(sf::VideoMode(400,700), "breakout");

	//class pointers
	paddle *ptrPaddle;
	bricks *ptrBricks;
	ball *ptrBall;
	score *ptrScore;


	//classes
	paddle Paddle(clock);
	bricks Bricks;
	ball Ball(Paddle,clock);
	score Score;

	//point to class address
	ptrPaddle = &Paddle;
	ptrBricks = &Bricks;
	ptrBall = &Ball;
	ptrScore = &Score;

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

		ptrBall ->ballCollision(Paddle, bricksField, ptrScore);

		ptrBall ->ballMove(Paddle);

		ptrScore ->SetText();

		
		app.clear();

		ptrScore ->drawText(app);

		ptrPaddle ->drawPaddle(app);

		ptrBricks ->spawnBricks(app, bricksField);

		ptrBall ->drawBall(app);

		app.display();

	}






	return 0;
	getchar();
}