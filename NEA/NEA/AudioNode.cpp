#include "AudioNode.h"
#include "AudioPlayer.h"

AudioNode::AudioNode(AudioPlayer& player):SceneNode(), audioQueues(player)
{
}

void AudioNode::playAudio(EffectID effect, sf::Vector2f position)
{
    audioQueues.play(effect, position);
}

unsigned int AudioNode::getCategory() const
{
    return Category::SoundEffect;
}
