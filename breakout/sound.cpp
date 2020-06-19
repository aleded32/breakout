#include "sound.h"


void music::playMusic()
{
	
	this->Sound.play();
	this->Sound.setLoop(true);
}


music::music()
{
	this->buffer.loadFromFile("backgroundMusic.wav");
	this->Sound.setBuffer(buffer);
}

music::~music()
{
	
}