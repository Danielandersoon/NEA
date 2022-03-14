#ifndef TITLESTATE_H
#define TITLESTSTE_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "State.h"

class TitleState : public State
{
public:
	TitleState(StateStack& stack, Context context);

	virtual void draw() override;
	virtual bool update(sf::Time dt) override;
	virtual bool handleEvents(const sf::Event& event) override;

private:
	sf::Sprite backgroundSprite;
	sf::Text text;
	sf::Text Story;
	sf::Text gameTitle;

	bool showText;
	bool displayStory;
	sf::Time textEffectTime;
};
#endif