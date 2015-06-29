#include <SFML/Network.hpp>
#include <iostream>

using namespace sf;
using namespace std;

TcpSocket socket;
char sendChar[1024];
char recvChar[1024];

inline void sendRecv()
{
	size_t received;

	while (1)
	{
		socket.send("a", 1024);
		socket.receive(recvChar, 1024, received);
		cout << recvChar << endl;
	}

}

void Play()
{
	cout << "Game started";
}

int main()
{
	Socket::Status status = socket.connect("localhost", 10011);

	bool playerButton[7] = {};

	Thread thread(&sendRecv);
	thread.launch();

	for (int i = 0; i < 7; i++)
	{
		sendChar[i] = playerButton[i];
	}
	socket.send(sendChar, 1024);
	for (int i = 0; i<7; i++)
		cout << sendChar[i] << endl;

	return 0;
}
