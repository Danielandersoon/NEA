#ifndef CONTROLLSTATE_H
#define CONTROLLSTATE_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include "State.h"

using namespace sf;
class ControllState : public State
{
public:

	ControllState(StateStack& stack, Context context);

	virtual void draw() override;
	virtual bool update(Time dt) override;
	virtual bool handleEvents(const Event& event) override;

	void updateOptionText();

private:
	enum OptionNames
	{
		Option1,
		Option2,
		Option3,
		Exit
	};
private:
	Sprite backgroundSprite;
	Sprite p1Controls;
	Sprite p2Controls;
	Text gameTitle;
	Text menuTitle;
	Text player1Text;
	Text player2Text;
	std::vector<Text> mOptions;
	std::size_t mOptionIndex;
};
#endif