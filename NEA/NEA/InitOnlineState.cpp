#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include "Utility.h"
#include "ResourceHolder.h"
#include "MusicPlayer.h"
#include "InitOnlineState.h"

InitOnlineState::InitOnlineState(StateStack& stack, Context context):State(stack, context)
{
	sf::Font& font = context.fonts->get(FontID::Main);
	backgroundSprite.setTexture(context.textures->get(TextureID::OptionsScreen));
	
	Connecting.setFont(context.fonts->get(FontID::Main));
	Connecting.setString("Connecting...");
	Connecting.setFillColor(sf::Color::Yellow);
	centerOrigin(Connecting);
	Connecting.setScale(2.0f, 2.0f);
	Connecting.setPosition(context.window->getView().getSize().x / 2, 250.f);

	Exit.setFont(context.fonts->get(FontID::Main));
	Exit.setString("Exit?");
	Exit.setFillColor(sf::Color::Black);
	centerOrigin(Exit);
	Exit.setScale(2.0f, 2.0f);
	Exit.setPosition(Connecting.getPosition().x, Connecting.getPosition().y + 100);
}

bool InitOnlineState::update(sf::Time dt)
{
	return false;
}

bool InitOnlineState::handleEvents(const sf::Event& event)
{
	if (event.type != sf::Event::KeyPressed)
		return false;

	if (event.key.code == sf::Keyboard::Return)
	{
		requestStackPop();
		requestStackPush(StateID::Menu);
	
	}
	return false;
}

void InitOnlineState::draw()
{
	auto& window = *getContext().window;
	window.setView(window.getDefaultView());
	window.draw(backgroundSprite);
	window.draw(Connecting); 
	window.draw(Exit);

	for (const auto& text : mOptions) {
		window.draw(text);
	}
}

void InitOnlineState::ConnectToUser()
{
	/*char data[100];
	std::size_t received;
	//bind to socket
	socket.bind(4400);

	//define self as online 
	unsigned short port = 54000;
	if (socket.send(data, 100, server, port) != sf::Socket::Done)
	{
		// error...
	}
	else {
		//Set online true & send Own IPADDRESS
	}

	//obtaining IP from server
	unsigned short port;
	if(socket.receive(data, 100, received, server, port) != sf::Socket::Done)
	{
		// error...
	}
	else {
	//request Opponent IpAddress


	//defining opponent IP address 
		opponent = "";
	}
	*/
}