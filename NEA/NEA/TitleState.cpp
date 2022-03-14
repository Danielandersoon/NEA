#include <SFML/Graphics/RenderWindow.hpp>
#include <sstream>
#include <iostream>
#include "TitleState.h"
#include "State.h"
#include "Utility.h"
#include "ResourceHolder.h"
#include "MusicPlayer.h"

TitleState::TitleState(StateStack& stack, Context context)
	:State(stack, context)
	, text()
	, showText(true)
	, textEffectTime(sf::Time::Zero)
	, displayStory(false)
{

	backgroundSprite.setTexture(context.textures->get(TextureID::TitleScreen));


	gameTitle.setFont(context.fonts->get(FontID::Main));
	gameTitle.setString("Rock World Tour");
	gameTitle.setFillColor(sf::Color::Red);
	centerOrigin(gameTitle);
	gameTitle.setScale(2.0f, 2.0f);
	gameTitle.setPosition(context.window->getView().getSize().x / 2, 250.f);

	text.setFont(context.fonts->get(FontID::Main));
	text.setString("Press any key to start");
	centerOrigin(text);
	text.setPosition(context.window->getView().getSize() / 2.f);
	context.music->play(MusicID::TitleTheme);
}

void TitleState::draw()
{
	auto& window = *getContext().window;
	window.draw(backgroundSprite);
	window.draw(gameTitle);
	if (showText)
		window.draw(text);
		
}

bool TitleState::update(sf::Time dt)
{
	// flashing text effect
	textEffectTime += dt;
	if (!displayStory) {
		if (textEffectTime >= sf::seconds(0.5f)) {
			showText = !showText;
			textEffectTime = sf::Time::Zero;
		}
	}
	else {
		gameTitle.setPosition(gameTitle.getPosition().x, gameTitle.getPosition().y - 0.5f);
		text.setPosition(text.getPosition().x, text.getPosition().y - 0.5f);
		if(text.getPosition().y <= -1000){
			requestStackPop();
			requestStackPush(StateID::Menu);
		}
	}


	return true;
}

bool TitleState::handleEvents(const sf::Event& event)
{
	// If any key is pressed, trigger the next screen
		if (event.type == sf::Event::KeyPressed)
		{
			requestStackPop();
			requestStackPush(StateID::Menu);

		}
	return true;
}