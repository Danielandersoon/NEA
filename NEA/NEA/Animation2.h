#ifndef ANIMATION2_H
#define ANIMATION2_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <vector>

using Frame = sf::IntRect;
using namespace sf;
class Animation2
{
public:
	explicit Animation2(bool repeat = true);
	void addFrame(Frame frame);
	void addFrameSet(std::vector<Frame> frames);
	void setDuration(Time duration);
	Time getDuration() const;
	void setRepeating(bool flag);
	bool isRepeating() const;
	void restart();
	bool isFinished() const;
	Frame getCurrentFrame() const;
	Frame update(Time dt);
	bool isStarting() const;
private:
	std::vector<Frame> frames_;
	std::size_t currentFrame_;
	Time duration_;
	Time elapsedTime_;
	bool repeat_;
};
#endif