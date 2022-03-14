#ifndef NETWORKCONNECTION_H
#define NETWORKCONNECTION_H
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Network.hpp>
#include <vector>

class NetworkConnection
{

public:

	NetworkConnection();
	sf::IpAddress ConnectToServer(sf::IpAddress ServerIPAddress);
	sf::IpAddress ConnectToOpponent(sf::IpAddress OpponentIPAddress);

private:
	sf::IpAddress ServerIPAddress;
	sf::IpAddress YourIPAddress;
	sf::IpAddress OpponentIPAddress;
	sf::UdpSocket socket;
};
#endif
