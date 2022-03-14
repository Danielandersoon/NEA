#ifndef MAPSELECTIONSTATE_H
#define MAPSELECTIONSTATE_H
#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "State.h"


using namespace sf; 
class MapSelectionState : public State
{
public:
	MapSelectionState(StateStack& stack, Context context);
	virtual void draw() override;
	virtual bool update(Time dt) override;
	virtual bool handleEvents(const Event& event) override;
	void updateOptionText();

private:
	enum OptionNames
	{
		M1, // MAP 1
		M2, // MAP 2
		M3, // MAP 3
		M4, // MAP 3
		Exit,
	};

	std::map<OptionNames, std::string> backgroundFilePaths;
	std::map<OptionNames, std::string> platformFilePaths;

private:
	Sprite backgroundSprite;
	std::vector<Text>    mOptions;
	std::size_t mOptionIndex;
	Sprite m1Portrait;
	Sprite m2Portrait;
	Sprite m3Portrait;
	Sprite m4Portrait;
	Texture	m1PortraitTexture;
	Texture	m2PortraitTexture;
	Texture	m3PortraitTexture;
	Texture	m4PortraitTexture;
	Text menuTitle;
};
#endif