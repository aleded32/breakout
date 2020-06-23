#include "ball.h"

void ball::drawBall(sf::RenderWindow& app)
{
	this ->SpriteBall.setFillColor(sf::Color::White);
	this ->SpriteBall.setRadius(5.0f);
	app.draw(this ->SpriteBall);
}


void ball::ballMove(paddle *Paddle, lives *Lives)
{
	if(Lives->isgameOver == false)
	{
		if(this->isBallMoving == false)
		{
			this->x = Paddle->x + (Paddle ->Paddle.getGlobalBounds().width/2 - 5);
			this->y = Paddle->y -10;

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				this->x = Paddle->x + (Paddle ->Paddle.getGlobalBounds().width/2 - 5);
				this->y = Paddle->y -10;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				this->x = Paddle->x + (Paddle ->Paddle.getGlobalBounds().width/2 - 5);
				this->y = Paddle->y -10;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isBallMoving == false)
			{
				if(this ->y < 695)
					this->isBallMoving =true;
			}

		}
		else if(this->isBallMoving == true)
		{

			srand((NULL));
		
			if(isCollidingTop ==false)
			{
				randAngle = rand()% 80 + 120;
				this->y -= (this->ballSpeed * 65)* this->dt;
			
				if(isCollidingPaddleLeft == true)
				{
					this->x -= sin(randAngle) * 0.15;
				}
				else if(isCollidingPaddleright == true)
				{

					this->x += sin(randAngle) * 0.15;
				}
			}
			else if(isCollidingTop == true)
			{
				randAngle = rand()% 80 + 120;
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
	}
			this->SpriteBall.setPosition(x, y);

	}

void ball::ballCollision(paddle *Paddle, int brickField[20][5], score *Score, lives *Lives)
{
	this ->BallX = (int)this->x/80;
	this ->BallY = (int)this->y/35;
	this ->PWtime = PWClock.getElapsedTime().asSeconds();

	if(this->isBallMoving == true)
	{
		

		if(this->y <= 0)
		{
			isCollidingTop = true;
			
		}
		else if(this->y >= Paddle->y - 10 && this->y <= Paddle->y  && this->x >= Paddle->x && this->x <= Paddle->x + ballLeft)
		{
			isCollidingTop = false;
			isCollidingPaddleLeft = true;
			isCollidingPaddleright = false;
		}
		else if(this->y >= Paddle->y - 10 && this->y <= Paddle->y && this->x >= Paddle->x + ballMiddle1 && this->x <= Paddle->x + ballMiddle2)
		{
			isCollidingTop = false;
			isCollidingPaddleLeft = false;
			isCollidingPaddleright = true;
		}
		else if(this->y >= Paddle->y - 10 && this->y <= Paddle->y  && this->x >= Paddle->x + ballRight1 && this->x <= Paddle->x + ballRight2)
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
		else if(this ->y > 695)
		{
			isBallMoving= false;
			Lives->Lives -= 1;
			if(Lives->Lives <=0)
				Lives->isgameOver = true;
			else
				this ->x = Paddle->x + 40;
				this ->y = Paddle->y - 10;
		}
		
		

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
		else if(brickField[BallY][BallX] == 2 && isCollidingTop == false)
		{
			brickField[BallY][BallX] = 0;
			isCollidingTop = true;
			PWClock.restart();
			Paddle ->Paddle.setSize(sf::Vector2f(45,20));
			this ->ballLeft = 15;
			this ->ballMiddle1 = 16;
			this ->ballMiddle2 = 30;
			this ->ballRight1 = 31;
			this ->ballRight2 = 45;
		}
		else if(brickField[BallY][BallX] == 2 && isCollidingTop == true)
		{
			brickField[BallY][BallX] = 0;
			isCollidingTop = false;
			PWClock.restart();
			Paddle ->Paddle.setSize(sf::Vector2f(45,20));
			this ->ballLeft = 15;
			this ->ballMiddle1 = 16;
			this ->ballMiddle2 = 30;
			this ->ballRight1 = 31;
			this ->ballRight2 = 45;
			
		}else if(brickField[BallY][BallX] == 3 && isCollidingTop == false)
		{
			brickField[BallY][BallX] = 0;
			isCollidingTop = true;
			Score ->Score += 3;
			PWClock.restart();
			Paddle ->Paddle.setSize(sf::Vector2f(180,20));
			this ->ballLeft = 60;
			this ->ballMiddle1 = 61;
			this ->ballMiddle2 = 120;
			this ->ballRight1 = 121;
			this ->ballRight2 = 180;
		}
		else if(brickField[BallY][BallX] == 3 && isCollidingTop == true)
		{
			brickField[BallY][BallX] = 0;
			isCollidingTop = false;
			Score ->Score += 3;
			PWClock.restart();
			Paddle ->Paddle.setSize(sf::Vector2f(180,20));
			this ->ballLeft = 60;
			this ->ballMiddle1 = 61;
			this ->ballMiddle2 = 120;
			this ->ballRight1 = 121;
			this ->ballRight2 = 180;
			
		}
		if(PWtime >= 5)
		{
			Paddle ->Paddle.setSize(sf::Vector2f(90,20));
			this ->ballLeft = 30;
			this ->ballMiddle1 = 31;
			this ->ballMiddle2 = 60;
			this ->ballRight1 = 61;
			this ->ballRight2 = 90;
			PWClock.restart();
		}
	}
}



ball::ball(paddle Paddle, sf::Clock& clock)
{
	
	this ->x = Paddle.x + 40;
	this ->y = Paddle.y - 10;
	
	this ->isCollidingTop = false;
	this ->isCollidingLeft = false;
	this ->isCollidingRight = false;
	this ->isCollidingPaddleLeft = false;
	this ->dt = clock.restart().asSeconds();
	this ->isBallMoving = false;
	this -> ballSpeed = 40.0f;
	this ->ballLeft = 30;
	this ->ballMiddle1 = 31;
	this ->ballMiddle2 = 60;
	this ->ballRight1 = 61;
	this ->ballRight2 = 90;
}

ball::~ball()
{

}