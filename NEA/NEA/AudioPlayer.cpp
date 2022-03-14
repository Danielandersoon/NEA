#include <cmath>
#include <SFML/Audio/Listener.hpp>
#include "AudioPlayer.h"

namespace
{
	// Audio coordinate system, point of view of a player in front of the screen:
	// X = left; Y = up; Z = back (out of the screen)
	const float ListenerZ = 300.f;
	const float Attenuation = 8.f;
	const float MinDistance2D = 200.f;
	const float MinDistance3D =
		std::sqrt(MinDistance2D * MinDistance2D
			+ ListenerZ * ListenerZ);
}

AudioPlayer::AudioPlayer() : AudioBuffers(), audioQueues()
{
	AudioBuffers.load(EffectID::GongHit, "Media/Audio/gong-hit.wav");
	AudioBuffers.load(EffectID::GongRoll, "Media/Audio/gong-roll.wav");
	AudioBuffers.load(EffectID::H1Attack1, "Media/Audio/redAttack1.wav");
	AudioBuffers.load(EffectID::H1Attack2, "Media/Audio/redAttack2.wav");
	AudioBuffers.load(EffectID::H1GetHit, "Media/Audio/redGetHit.wav");
	AudioBuffers.load(EffectID::H2Attack1, "Media/Audio/blueAttack1.wav");
	AudioBuffers.load(EffectID::H2Attack2, "Media/Audio/blueAttack2.wav");
	AudioBuffers.load(EffectID::H2GetHit, "Media/Audio/blueGetHit.wav");
	AudioBuffers.load(EffectID::H3Attack1, "Media/Audio/girlAttack1.wav");
	AudioBuffers.load(EffectID::H3Attack2, "Media/Audio/girlAttack2.wav");
	AudioBuffers.load(EffectID::H3GetHit, "Media/Audio/girlGetHit.wav");
	AudioBuffers.load(EffectID::TakeDamage, "Media/Audio/takeDamage.wav");
	AudioBuffers.load(EffectID::MissAttack, "Media/Audio/missAttack.wav");
	AudioBuffers.load(EffectID::Block, "Media/Audio/block.wav");
	sf::Listener::setDirection(0.f, 0.f, -1.f);
}

void AudioPlayer::play(EffectID effect)
{
	play(effect, getListenerPosition());

}

void AudioPlayer::play(EffectID effect, sf::Vector2f position)
{
	audioQueues.push_back(sf::Sound());
	sf::Sound& Audio = audioQueues.back();
	Audio.setLoop(false);
	Audio.setBuffer(AudioBuffers.get(effect));
	Audio.setPosition(position.x, -position.y, 0.f);
	Audio.setAttenuation(Attenuation);
	Audio.setMinDistance(MinDistance3D);
	Audio.play();
}




void AudioPlayer::removeStoppedAudio()
{

	audioQueues.remove_if([](const sf::Sound& x)
	{
		return x.getStatus() == sf::Sound::Stopped;
	});
}

void AudioPlayer::setListenerPosition(sf::Vector2f position)
{
	sf::Listener::setPosition(position.x, -position.y, ListenerZ);
}

sf::Vector2f AudioPlayer::getListenerPosition()
{
	auto pos = sf::Listener::getPosition();
	return  sf::Vector2f(pos.x, pos.y);
}
