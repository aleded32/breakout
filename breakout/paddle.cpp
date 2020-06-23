#include "paddle.h"

//draw the paddle
void paddle::drawPaddle(sf::RenderWindow& app)
{
	

	 app.draw(this ->Paddle);
}

void paddle::paddleMove(lives *Lives)
{
	if(Lives ->isgameOver == false)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			this->x -= 0.35 * this->dt;
		
		
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->x += 0.35 * this->dt;
		
		}
	}
	this->Paddle.setPosition(x, y);
}

void paddle::worldCollision()
{
	if(x < 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->x = 1;
		
	}
	else if(x + Paddle.getGlobalBounds().width >399 && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->x = 399 - this->Paddle.getGlobalBounds().width;
	}
	
}

//paddle constuctor
paddle::paddle(sf::Clock& clock)
{
	this->x = 200.0f;
	this->y = 600.0f;
	this->Paddle.setSize(sf::Vector2f(90, 20));
	this ->Paddle.setFillColor(sf::Color::Green);
	this ->Paddle.setPosition(x, y);
	this->dt = clock.restart().asSeconds();
	
}

//paddle deconstructor
paddle::~paddle()
{
	this ->Paddle;
}