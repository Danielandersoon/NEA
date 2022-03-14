#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
using namespace sf;
class Animation : public Drawable, public Transformable
{
public:
	Animation();
	explicit 				Animation(const Texture& texture);

	void 					setTexture(const Texture& texture);
	const Texture* getTexture() const;

	void setFrameSize(Vector2i fs);
	Vector2i getFrameSize() const;

	void setNumFrames(std::size_t nf);
	std::size_t getNumFrames() const;

	void setDuration(Time d);
	Time getDuration() const;

	void setRepeating(bool flag);
	bool isRepeating() const;

	void restart();
	bool isFinished() const;

	FloatRect getLocalBounds() const;
	FloatRect getGlobalBounds() const;

	void update(Time dt);
private:
	void draw(RenderTarget& target, RenderStates states) const;
private:
	Sprite sprite;
	Vector2i frameSize;
	std::size_t numFrames;
	std::size_t currentFrame;
	Time duration;
	Time elapsedTime;
	bool repeat;
};
#endif