#ifndef ROUNDOVERSTATE_H
#define ROUNDOVERSTATE_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "State.h"

class RoundOverState : public State
{
public:
	RoundOverState(StateStack& stack, Context context);
	virtual void draw() override;
	virtual bool update(sf::Time dt) override;
	virtual bool handleEvents(const sf::Event& event) override;

private:
	sf::Sprite backgroundSprite;
	sf::Text roundOverText;
	sf::Text instructionText;
};
#endif