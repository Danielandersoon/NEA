#include <iostream>
#include "game.h"

int main()
{
	//initiate game engine
	game Game;

	//start game loop

	while (Game.isRunning())
	{
		//update
		Game.update();

		//render
		Game.render();
	}

	//End Game
	return 0;
}