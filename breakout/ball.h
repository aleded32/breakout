#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "paddle.h"

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

public:

	
	float x;
	float y;
	float ballSpeed;

	void drawBall(sf::RenderWindow& app);
	void ballMove(paddle Paddle);
	void ballCollision(paddle Paddle);

	ball(paddle Paddle, sf::Clock& clock);
	~ball();

	
};