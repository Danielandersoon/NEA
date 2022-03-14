#ifndef OPTIONSSTATE_H
#define OPTIONSSTATE_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include "State.h"

using namespace sf;
class OptionsState :
	public State
{
public:
	OptionsState(StateStack& stack, Context context);
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
		Exit,
	};
private:
	Sprite backgroundSprite;
	Text gameTitle;
	Text menuTitle;
	std::vector<Text> mOptions;
	std::size_t mOptionIndex;

};
#endif