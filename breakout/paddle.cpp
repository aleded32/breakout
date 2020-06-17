#include "paddle.h"

//draw the paddle
void paddle::drawPaddle(sf::RenderWindow& app)
{
	

	 app.draw(this ->Paddle);
}

void paddle::paddleMove()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		x -= 0.5 * dt;
		
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		x += 0.5 * dt;
		
	}
	Paddle.setPosition(x, y);
}

void paddle::worldCollision()
{
	if(x < 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		x = 1;
		
	}
	else if(x + Paddle.getGlobalBounds().width >399 && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		x = 399 - Paddle.getGlobalBounds().width;
	}
	
}

//paddle constuctor
paddle::paddle(sf::Clock& clock)
{
	x = 200.0f;
	y = 600.0f;
	Paddle.setSize(sf::Vector2f(100, 20));
	Paddle.setFillColor(sf::Color::Green);
	Paddle.setPosition(x, y);
	dt = clock.restart().asSeconds();
	
}

//paddle deconstructor
paddle::~paddle()
{
	this ->Paddle;
}