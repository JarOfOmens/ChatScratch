// ChatScratch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	sf::TcpListener listener;

	//bind the listener to a port
	if (listener.listen(53000) != sf::Socket::Done)
	{
		// error...
		std::cout << "Port did not bind!" << std::endl;
	}

	//accept a new connection
	sf::TcpSocket client;
	if (listener.accept(client) != sf::Socket::Done)
	{
		// error...
		std::cout << "Error accepting connection" << std::endl;
		char input = getchar();
	}
	std::cout << "Successsful connection from client" << std::endl;
	
	sf::Packet packet;

	if (client.receive(packet) != sf::Socket::Done)
	{
		std::cout << "Error receiving data.\n";
		char input = getchar();
	}
	
	std::string text;
	packet >> text;
	std::cout << "Received " << text << std::endl;

	char input = getchar();
    return 0;
}

