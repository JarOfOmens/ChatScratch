// ChatClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	sf::TcpSocket socket;
	sf::Socket::Status status = socket.connect("127.0.0.1", 53000);
	if (status != sf::Socket::Done)
	{
		std::cout << "Error\n";
		char input = getchar();
	}
	std::cout << "CLIENT: Successsful connection to server" << std::endl;

	char data[100];
	std::string data_string = "Hello";
	sf::Packet packet;
	packet << data_string;
	
	if (socket.send(packet) != sf::Socket::Done)
	{
		// error...
		std::cout << "Error sending packet to server." << std::endl;
	}

	char input = getchar();
    return 0;
}

