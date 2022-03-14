#ifndef INITONLINESTATE_H
#define INITONLINESTATE_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/Socket.hpp>
#include <SFML/Network/UdpSocket.hpp>
#include <vector>
#include "State.h"

using namespace sf;
class InitOnlineState
	: public State
{
public:
	InitOnlineState(StateStack& stack, Context context);

	virtual void draw() override;
	virtual bool update(Time dt) override;
	virtual bool handleEvents(const Event& event) override;

	
	void ConnectToUser();

private:
	enum
	{
		connecting,
		exit,
	};
private:
	Sprite backgroundSprite;
	Text Connecting;
	Text Exit;
	std::vector<Text> mOptions;
	sf::IpAddress server = "10.10.25.105";
	sf::IpAddress opponent;
	sf::IpAddress own;
	sf::UdpSocket socket;
};
#endif