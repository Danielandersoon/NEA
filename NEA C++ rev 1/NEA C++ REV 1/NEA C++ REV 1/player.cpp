#include "player.h"
#include "game.h"

void player::initPlayer()
{
	/*
		player box is created as an object in the player header
		position is set to (0,0) of screen
		size is set to 100*100 px
	*/

	this->playerBox.setPosition(0.f, 0.f);
	this->playerBox.setSize(sf::Vector2f(100.f, 100.f));
	this->playerBox.setFillColor(sf::Color(0, 0, 0, 0));
	this->playerBox.setOutlineColor(sf::Color(0, 255, 0, 255));
	this->playerBox.setOutlineThickness(20.f);
}
