#ifndef ONLINEGAMESTSTE_H
#define ONLINEGAMESTATE_H
#include "GameState.h"
#include "OnlinePlayer.h"

class OnlineGameState : public State
{
public:
    OnlineGameState(StateStack& stack, Context context);

	virtual void draw() override;
	virtual bool update(sf::Time dt) override;
	virtual bool handleEvents(const sf::Event& event) override;

private:
	World world;
	OnlinePlayer& OnlinePlayer;
	sf::Text roundOverText;
};
#endif