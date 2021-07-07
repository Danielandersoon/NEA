#include "game.h"
#include "player.h"

//global variable
int screenHeight = 1080;
int screenWidth = 1920;

//accessors

const bool game::isRunning() const
{
	return this->window->isOpen();
}

//functions

//initiate functioins
void game::initVariables()
{
	this->window = nullptr;
}

void game::initWiondow()
{
	this->vidMode.height = screenHeight;
	this->vidMode.width = screenWidth;

	this->window = new sf::RenderWindow(this->vidMode,
		"game window",
		sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(30);
}

//event detection

void game::pollEvents()
{
	//event polling
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

//scene drawing

void game::render()
{
	this->window->clear();
	
	//draw game object
	//this->window->draw(this->enemy);
	this->window->display();
}

void game::update()
{
	
}

//constructors + destructors 
game::game()
{
	this->initVariables();
	this->initWiondow();
	this->pollEvents();
}

game::~game()
{
	delete this->window;
}