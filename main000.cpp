#include "Classes.h"
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "math.h"

using namespace std;
using namespace sf;

TcpSocket socket;
char sendChar[1024];
char recvChar[1024];
size_t received;

vector <Walls> wall;
vector <Tanks> tank;
vector <Bullets> bullet;

void sendRecv()
{
}





int main()
{
	Players player;

	socket.receive(recvChar, 1024, received);
	cout << recvChar << endl;

	if (recvChar[0] != '*')
	{
		for (int i = 0; i < tank.size(); i++)
		{
			sendChar[i] = player.button[i];
		}
		for (int i0 = 0; i0 < tank.size(); i0++)
		{
			for (int i1 = 0; i1 < 7; i1++)
			{
				tank[i0].button[i1] = recvChar[7 * i0 + i1];
				//	cout << tank[i0].button[i1] << endl;
			}
		}
		///////////////////////sendchar for nurmal use
		sendChar[0] = player.playerID;
		for (int i = 0; i < 7; i++)
		{
			sendChar[i + 1] = player.button[i];
		}
		socket.send(sendChar, 1024);
	}

	else
	{

	}

	Socket::Status status = socket.connect("localhost", 10006);
	socket.send(sendChar, 1024);

	return 0;
}