#ifndef CHARACTERSELECTIONSTATE_H
#define CHARACTERSELECTIONSTATE_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include "State.h"
#include "Actor.h"

using namespace sf;
class CharacterSelectionState : public State
{
public:
	Actor::Type p1Char;
	Actor::Type p2Char;
	CharacterSelectionState(StateStack& stack, Context context);

	virtual void draw() override;
	virtual bool update(Time dt) override;
	virtual bool handleEvents(const Event& event) override;

	void updateOptionText();

private:
	enum OptionNames
	{
		C1, // CHARACTER 1
		C2, // CHARACTER 2
		C3, // CHARACTER 3
		Exit,
	};
	std::map<OptionNames, std::string> hudLeftFilePaths;
	std::map<OptionNames, std::string> hudRightFilePaths;
private:
	Sprite backgroundSprite;
	Sprite c1Portrait;
	Sprite c2Portrait;
	Sprite c3Portrait;
	Texture	c1PortraitTexture;
	Texture	c2PortraitTexture;
	Texture	c3PortraitTexture;
	std::vector<Text> mOptions;
	std::size_t mOptionIndex;
	int selectionCount;
	Text menuTitle;
	
	Text p1Selection;
	Text p2Selection;

	Sprite p1SelectedChar;
	Sprite p2SelectedChar;
};
#endif