#include "bricks.h"


void bricks::addBricks(sf::Clock& clock, int brickField[20][5], lives *Lives)
{
	this->time = clock.getElapsedTime().asSeconds();

	if(Lives->isgameOver == false)
	{
		if(this->time >= 5)
		{
			for(int i = MAX_ROW - 1; i > 0 ; i--)
			{
					for(int j = 0; j < MAX_COLUMN; j++)
				{
					brickField[i][j] =  brickField[i - 1][j];
					brickField[i - 1][j] = 1;
					clock.restart();
				}
			}
		}
	}

	std::cout << time << std::endl;
}


void bricks::spawnBricks(sf::RenderWindow& app, int bricksField[20][5])
{


	for(int i = 0; i < MAX_COLUMN; i++)
	{
		for(int j = 0; j < MAX_ROW; j++)
		{
			this ->block.setPosition( i * 80, j* 35);
			
			this ->block.setFillColor(this ->bricksColour[bricksField[j][i]]);
			app.draw(this ->block);
		}
	}

}


bricks::bricks()
{
	
	this ->block.setSize(sf::Vector2f(78.0f, 32.0f));

		this ->bricksColour[0] = sf::Color::Transparent;
		this ->bricksColour[1] = sf::Color::Green;
		
}

bricks::~bricks()
{

}