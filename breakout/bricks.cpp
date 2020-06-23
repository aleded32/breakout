#include "bricks.h"
#include <stdlib.h>

void bricks::addBricks(sf::Clock& clock, int brickField[20][5], lives *Lives)
{
	this->timeBricks = clock.getElapsedTime().asSeconds();
	srand(time(NULL));
	this->randBrickTime = this->randClock.getElapsedTime().asSeconds();
	
	if(Lives->isgameOver == false)
	{

		if(this->timeBricks >= 5)
		{	
			

			this ->randBrick = rand()% 2 + 2;
			this->randChancePW = rand()% 101;
			this->randRow = rand()% 5;

			
			for(int i = MAX_ROW - 1; i > 0 ; i--)
			{
					for(int j = 0; j < MAX_COLUMN; j++)
				{
					brickField[i][j] =  brickField[i - 1][j];
					if(this->randChancePW >= this->ChancePW)
					brickField[i - 1][j] = 1;
					
					
					clock.restart();
					
				}
			}
			
		}
		else if(randBrickTime >=5)
		{
				if(this->randChancePW <= this->ChancePW)
				{
						brickField[0][this->randRow] = this->randBrick;
						this->randClock.restart();
					
				}
		}	
			
		
	}

	
}


void bricks::spawnBricks(sf::RenderWindow& app, int bricksField[20][5], lives *Lives)
{


	for(int i = 0; i < MAX_COLUMN; i++)
	{
		for(int j = 0; j < MAX_ROW; j++)
		{
			this ->block.setPosition( i * 80, j* 35);
			this ->block.setFillColor(this ->bricksColour[bricksField[j][i]]);
			app.draw(this ->block);
			if(bricksField[MAX_ROW - 4][j] == 1)
					Lives ->isgameOver = true;
		}
	}

}


bricks::bricks()
{
	
	this ->block.setSize(sf::Vector2f(78.0f, 32.0f));

		this ->bricksColour[0] = sf::Color::Transparent;
		this ->bricksColour[1] = sf::Color::Green;
		this ->bricksColour[2] = sf::Color::Red;
		this ->bricksColour[3] = sf::Color::Blue;
		this ->ChancePW = 35;
		
		
		
}

bricks::~bricks()
{

}