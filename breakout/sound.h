#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class sound
{
private:

	sf::SoundBuffer buffer;
	sf::Sound Sound;
	

public:

};


class music : public sound
{

private:

	sf::SoundBuffer buffer;
	sf::Sound Sound;

public:

	void playMusic();
	music();
	~music();

};
