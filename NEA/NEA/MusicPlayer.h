#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/Music.hpp>
#include <map>
#include <string>
#include "ResourceHolder.h"
#include "ResourceIdentifier.h"

class MusicPlayer : private sf::NonCopyable
{
public:
	enum class MUSIC_TYPE {
		Texas,
		Japan,
		Sweeden,
		UK
	};

	MusicPlayer();

	void play(MusicID theme);
	void stop();

	void setPaused(bool paused);
	void setVolume(float vol);

	MUSIC_TYPE getType();
	void setMusicType(MUSIC_TYPE type);
private:
	MUSIC_TYPE musicType;
	sf::Music music;
	std::map<MusicID, std::string> filenames;
	float volume;


};
#endif