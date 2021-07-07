#pragma once
#include "game.h"

class player
{
private:
	sf::Texture playerSkin;
	playerSkin.LoadFromFile("sprites/player 1 character/fighter 1-1")
	sf::Sprite playerSprite;
	sf::RectangleShape playerBox;
	void initPlayer();
};

