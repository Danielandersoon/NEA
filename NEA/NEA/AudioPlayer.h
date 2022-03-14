#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H
#include <SFML/System/Vector2.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <list>
#include "ResourceHolder.h"
#include "ResourceIdentifier.h"

class AudioPlayer : private sf::NonCopyable
{
public:
	AudioPlayer();
	void play(EffectID effect);
	void play(EffectID effect, sf::Vector2f position);
	void removeStoppedAudio();
	void setListenerPosition(sf::Vector2f position);
	sf::Vector2f getListenerPosition();

private:
	SoundBufferHolder_t AudioBuffers;
	std::list<sf::Sound> audioQueues;
};
#endif