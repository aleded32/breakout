#include "ball.h"

void ball::drawBall(sf::RenderWindow& app)
{
	this ->SpriteBall.setFillColor(sf::Color::White);
	this ->SpriteBall.setRadius(5.0f);
	app.draw(this ->SpriteBall);
}


void ball::ballMove(paddle Paddle)
{
	if(this->isBallMoving == false)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			this->x = Paddle.x +50;
			this->y = Paddle.y -10;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->x = Paddle.x +50;
			this->y = Paddle.y -10;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isBallMoving == false)
		{
			this->isBallMoving =true;
		}

	}
	else if(this->isBallMoving == true)
	{

		srand((NULL));
		
		if(isCollidingTop ==false)
		{
			randAngle = rand()% 35 + 150;
			this->y -= (this->ballSpeed * 75)* this->dt;
			
			if(isCollidingPaddleLeft == true)
			{
				this->x -= sin(randAngle) * 0.1;
			}
			else if(isCollidingPaddleright == true)
			{

				this->x += sin(randAngle) * 0.1;
			}
		}
		else if(isCollidingTop == true)
		{
			randAngle = rand()% 35 + 150;
			this->y += (this->ballSpeed * 75)* this->dt;
			
		}
		if(isCollidingLeft == true)
		{
			this ->x += sin(randAngle) * 0.15;
			
		}
		else if(isCollidingRight == true)
		{
			this ->x -= sin(randAngle) * 0.15;
		}
		
	}
		this->SpriteBall.setPosition(x, y);
}

void ball::ballCollision(paddle Paddle, int brickField[20][5], score *Score)
{
	this ->BallX = (int)this->x/80;
	this ->BallY = (int)this->y/35;

	if(this->isBallMoving == true)
	{
		

		if(this->y <= 0)
		{
			isCollidingTop = true;
			
		}
		else if(this->y >= Paddle.y - 10 && this->x >= Paddle.x && this->x <= Paddle.x + 40)
		{
			isCollidingTop = false;
			isCollidingPaddleLeft = true;
			isCollidingPaddleright = false;
		}
		else if(this->y >= Paddle.y - 10 && this->x >= Paddle.x + 81 && this->x <= Paddle.x + 120)
		{
			isCollidingTop = false;
			isCollidingPaddleLeft = false;
			isCollidingPaddleright = true;
		}
		else if(this->y >= Paddle.y - 10 && this->y <= Paddle.y  && this->x >= Paddle.x + 41 && this->x <= Paddle.x + 80)
		{
			isCollidingTop = false;
			isCollidingPaddleLeft = false;
			isCollidingPaddleright = false;
		}
		if(this->x < 1)
		{
			isCollidingLeft = true;
			isCollidingRight = false;
		}
		else if(this ->x >390)
		{
			isCollidingLeft = false;
			isCollidingRight = true;
		}
		else if(this ->y > 699)
		{
			isBallMoving= false;
		}
		
		std::cout << BallX;

		if(brickField[BallY][BallX] == 1 && isCollidingTop == false)
		{
			brickField[BallY][BallX] = 0;
			isCollidingTop = true;
			Score ->Score +=1;
		}
		else if(brickField[BallY][BallX] == 1 && isCollidingTop == true)
		{
			brickField[BallY][BallX] = 0;
			isCollidingTop = false;
			Score ->Score +=1;
		}

	}
}



ball::ball(paddle Paddle, sf::Clock& clock)
{
	
	this ->x = Paddle.x + 50;
	this ->y = Paddle.y - 10;
	
	this ->isCollidingTop = false;
	this ->isCollidingLeft = false;
	this ->isCollidingRight = false;
	this ->isCollidingPaddleLeft = false;
	this ->dt = clock.restart().asSeconds();
	this ->isBallMoving = false;
	this -> ballSpeed = 25.0f;
}

ball::~ball()
{

}