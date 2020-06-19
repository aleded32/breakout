#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "paddle.h"
#include "player.h"

class ball 
{
private:

	float dt;
	sf::CircleShape SpriteBall;
	bool isBallMoving;
	bool isCollidingTop;
	bool isCollidingLeft;
	bool isCollidingRight;
	bool isCollidingPaddleLeft;
	bool isCollidingPaddleright;
	float randAngle;
	int BallX;
	int BallY;

public:

	
	float x;
	float y;
	float ballSpeed;

	void drawBall(sf::RenderWindow& app);
	void ballMove(paddle *Paddle, lives *Lives);
	void ballCollision(paddle *Paddle, int brickfield[20][5], score *Score, lives *Lives);

	ball(paddle Paddle, sf::Clock& clock);
	~ball();

	
};