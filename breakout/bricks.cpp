#include "bricks.h"


void bricks::spawnBricks(sf::RenderWindow& app, int bricksField[5][3])
{
	for(int i = 0; i < MAX_COLUMN; i++)
	{
		for(int j = 0; j < MAX_ROW; j++)
		{
			this ->block.setPosition( i * 67, j* 35);
			this ->block.setFillColor(this ->bricksColour[bricksField[j][i]]);
			app.draw(this ->block);
		}
	}
}


bricks::bricks()
{
	
	this ->block.setSize(sf::Vector2f(65.0f, 32.0f));

	
		this ->bricksColour[0] = sf::Color::Green;
		this ->bricksColour[1] = sf::Color::Transparent;
}

bricks::~bricks()
{

}