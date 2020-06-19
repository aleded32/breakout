#include "player.h"


player::player()
{
	this ->font.loadFromFile("Acadian_Runes-Regular_PERSONAL_USE.ttf");
	this ->text.setFont(font);
	this ->text.setCharacterSize(25);
	this ->text.setFillColor(sf::Color::White);
	
}

player::~player()
{

}

score::score()
{
	this ->Score = 0;
}

score::~score()
{

}

void lives::SetText()
{
	
	this ->text.setString("Lives " + std::to_string(this->Lives));
	this ->text.setPosition(300,650);
}

void lives::drawText(sf::RenderWindow& app)
{
	
	app.draw(this ->text);
	
}

lives::lives()
{
	this ->Lives = 3;
	this->isgameOver= false;
}

lives::~lives()
{

}

void score::SetText()
{
	
	this ->text.setString("score: " + std::to_string(this->Score));
	this ->text.setPosition(0,650);
}

void score::drawText(sf::RenderWindow& app)
{
	
	app.draw(this ->text);
	
}