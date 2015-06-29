# include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Header.h"

using namespace std;
using namespace sf;
/////////////////////////////globals
TcpSocket socket;
char sendChar[1024];
char recvChar[1024];
size_t received;

int playerID;
bool playerButton[7] = { 0, 0, 0, 0, 0, 0, 0 };

vector <Walls> wall;
vector <Tanks> tank;
vector <Bullets> bullet;

char anotherClient = '*';
////////gui globals


//tank body
float r = 60;
float s = 740;

//tank pipe
float p;
float q;


////////////////////////////end of globals


////////////////////////////funcs

////////////////////////////////////////////////////build map
inline void buidMap()
{

}
////////////////////////////////////////////////////end of build walls



////////////////////////////////////////////////////send & recv from server
void sendRecv()
{
	while (1)
	{
		socket.receive(recvChar, 1024, received);
		cout << recvChar << endl;

		if (recvChar[0] != anotherClient)
		{
			for (int i0 = 0; i0 < tank.size(); i0++)
			{
				sendChar[i0] = playerButton[i0];
			}

			for (int i1 = 0; i1 < tank.size(); i1++)
			{
				for (int i2 = 0; i2 < 7; i2++)
				{
					tank[i1].button[i2] = recvChar[7 * i1 + i2];
					cout << tank[i1].button[i2] << endl;
				}
			}
			///making send char for normal use
			sendChar[0] = playerID;
			for (int i0 = 0; i0 < 7; i0++)
			{
				sendChar[i0 + 1] = playerButton[i0];
			}
			socket.send(sendChar, 1024);
		}
		else
		{
		}

	}
}

int main(){
	Socket::Status status = socket.connect("localhost", 10004);
	socket.send(sendChar, 1024);

	buidMap();

	/////build threads
	Thread sendrecvThread(&sendRecv);
	Thread mainGameThread(&mainGame);
	Thread pressButtonThread(&pressButton);

	/////launch threads
	sendrecvThread.launch();
	pressButtonThread.launch();
	mainGameThread.launch();
	/////////////////////////////////////
	return 0;
}
