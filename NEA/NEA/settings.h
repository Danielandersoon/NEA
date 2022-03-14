#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>

bool upscale;
bool vertical_sync;
int window_scale;

std::ifstream ifs("config.ini");
sf::VideoMode window_bounds(800, 600);
void settings() {
	if (ifs.is_open())
	{
		ifs >> vertical_sync;
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> upscale;
	}
	ifs.close();
}