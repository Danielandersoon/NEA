#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

// Game engine class

class game
{
private:

	//variables
	//window
	sf::RenderWindow* window;
	sf::VideoMode vidMode;
	sf::Event event;

	//private functions
	void initVariables();
	void initWiondow();

public:
	//constructor + destructors
	game();
	virtual ~game();

	//accessors
	const bool isRunning() const;
	//functions
	void update();
	void pollEvents();
	void render();

};

