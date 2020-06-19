//include files
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "paddle.h"
#include "bricks.h"
#include "ball.h"
#include "player.h"
#include "sound.h"


//main 
int main()
{
	//clock
	sf::Clock clock;

	int bricksField[20][5] =
	{
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
	lives *ptrLives;
	music *ptrMusic;


	//classes
	paddle Paddle(clock);
	bricks Bricks;
	ball Ball(Paddle,clock);
	score Score;
	lives Lives;
	music Music;

	//point to class address
	ptrPaddle = &Paddle;
	ptrBricks = &Bricks;
	ptrBall = &Ball;
	ptrScore = &Score;
	ptrLives =&Lives;
	ptrMusic = &Music;

	ptrMusic ->playMusic();

	sf::Event e;

	while(app.isOpen())
	{
		while (app.pollEvent(e))
		{
			if(e.type == sf::Event::Closed)
			app.close();
		}

		

		ptrPaddle ->worldCollision();

		ptrPaddle ->paddleMove(ptrLives);

		ptrBall ->ballCollision(ptrPaddle, bricksField, ptrScore, ptrLives);

		ptrBall ->ballMove(ptrPaddle, ptrLives);

		ptrBricks ->addBricks(clock, bricksField, ptrLives);

		ptrScore ->SetText();

		ptrLives ->SetText();

		
		app.clear();

		ptrScore ->drawText(app);

		ptrLives ->drawText(app);

		

		ptrBricks ->spawnBricks(app, bricksField, ptrLives);

		ptrPaddle ->drawPaddle(app);

		ptrBall ->drawBall(app);
		

		app.display();

	}






	return 0;
	getchar();
}