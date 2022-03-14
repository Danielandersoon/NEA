#include "NetworkConnection.h"

NetworkConnection::NetworkConnection()
{
}

sf::IpAddress NetworkConnection::ConnectToServer(sf::IpAddress ServerIPAddress)
{
	socket.bind(4400);
	if (socket.bind(4400) != sf::Socket::Done) {
		
	}

	//opponentIPAddress = ip recived from server 

	return sf::IpAddress();
	
	this->ConnectToOpponent(OpponentIPAddress);
}

sf::IpAddress NetworkConnection::ConnectToOpponent(sf::IpAddress OpponentIPAddress)
{
	socket.bind(4400);
	if (socket.bind(4400) != sf::Socket::Done) {

	}
	return sf::IpAddress();
}



