#ifndef AUDIONODE_H
#define AUDIONODE_H
#include "ResourceIdentifier.h"
#include "SceneNode.h"
#include "AudioPlayer.h"
class AudioNode : public SceneNode
{
public:
	AudioNode(AudioPlayer& player);
	void playAudio(EffectID effect, sf::Vector2f position);
	virtual unsigned int getCategory() const override;

private:
	AudioPlayer& audioQueues;
};
#endif