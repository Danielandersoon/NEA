#ifndef MENUSTATE_H
#define MENUSTATE_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include "State.h"


using namespace sf;
class MenuState : public State
{
public:
	MenuState(StateStack& stack, Context context);

	virtual void draw() override;
	virtual bool update(Time dt) override;
	virtual bool handleEvents(const Event& event) override;

	void updateOptionText();

private:
	enum OptionNames
	{
		Play,
		OnlinePlay,
		Options,
		Controlls,
		Exit
	};
private:
	Sprite backgroundSprite;
	Text gameTitle;
	std::vector<Text> mOptions;
	std::size_t mOptionIndex;

};
#endif