#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

using namespace std;
using namespace sf;

TcpSocket socket;
char sendChar[1024];
char recvChar[1024];
size_t received;

void sendRecv()
{
}

int main()
{

	socket.receive(recvChar, 1024, received);
	cout << recvChar << endl;

	Socket::Status status = socket.connect("localhost", 10006);
	socket.send(sendChar, 1024);

	return 0;
}