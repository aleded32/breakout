#pragma once

//include files
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class player
{
private:

	

public:

	float x,y;
	sf::Font font;
	sf::Text text;

	player();
	~player();

	void drawText();
	void SetText();

};


class score : public player
{
public:
	
	void drawText(sf::RenderWindow& app);
	void SetText();
	int Score;

	score();
	~score();

private:

	

};
