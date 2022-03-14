#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include "ResourceHolder.h"
#include "ResourceIdentifier.h"
#include "StateStack.h"
#include "Player.h"
#include "MusicPlayer.h"
#include "AudioPlayer.h"
//#include "settings.h"

using namespace sf;
class Application
{
public:
	Application();
	void run();

private:
	void render();
	void updateStatistics(Time et);
	void processInput();
	void update(Time dt);
	void registerStates();

private:
	static const Time TimePerFrame;

	//context
	RenderWindow window;
	TextureHolder_t textures;
	FontHolder_t fonts;
	Player player;
	//OnlinePlayer OnlinePlayer;
	MusicPlayer	music;
	AudioPlayer	sounds;

	StateStack stateStack;

	Text statsText;
	Time statsUpdateTime;
	std::size_t	statsNumFrames;

	Actor::Type	p1Char;
	Actor::Type	p2Char;
	std::string	backGroundFilePath;
	std::string	platformFilePath;
	std::string	hudLeftFilePath;
	std::string	hudRightFilePath;
	Image skicon;
};
#endif