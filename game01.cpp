# include <iostream>
#include <SFML/Network.hpp>
#include "Header.h"

using namespace std;
using namespace sf;
/////////////////////////////globals
TcpSocket socket;
char sendChar[1024];
char recvChar[1024];
size_t received;

bool playerButton[7];
vector <Tanks> tank;
vector <Bullets> bullet;
////////////////////////////end of globals


////////////////////////////funcs
////////////////////////////////////////////////////send & recv from server
void sendRecv()
{


	while (1)
	{
		for (int i = 0; i < tank.size(); i++)
		{
			sendChar[i] = playerButton[i];
		}

		socket.send("a", 1024);
		socket.receive(recvChar, 1024, received);
		cout << recvChar << endl;

		for (int i0 = 0; i0 < tank.size(); i0++)
		{
			for (int i1 = 0; i1 < 7; i1++)
			{
				tank[i0].button[i1] = recvChar[7 * i0 + i1];
				cout << tank[i0].button[i1] << endl;
			}
		}
	}

}

////////////////////////////////////////////////////end of send & recv from server

////////////////////////////////////////////////////main game
inline void mainGame()
{
	//cout << "Game started" ;

	////
	int playerID;

	while (true)
	{
		for (int i0 = 0; i0 < tank.size(); i0++)
		{
			/////////////////////////////////////////////////////////////button works
			if (tank[i0].button[0] == true && tank[i0].button[1] == false)
				tank[i0].velocity = tank[i0].vecForwardVelocity;
			if (tank[i0].button[1] == true && tank[i0].button[0] == false)
				tank[i0].velocity = tank[i0].vecBackwardVelocity;
			if (tank[i0].button[2] == true && tank[i0].button[3] == false)
				tank[i0].bodyRotateSpeed = tank[i0].bodyRotationVelocity;
			if (tank[i0].button[3] == true && tank[i0].button[2] == false)
				tank[i0].bodyRotateSpeed = -tank[i0].bodyRotationVelocity;
			if (tank[i0].button[4] == true && tank[i0].button[5] == false)
				tank[i0].pipeRotateSpeed = tank[i0].pipeRotationVelocity;
			if (tank[i0].button[5] == true && tank[i0].button[4] == false)
				tank[i0].pipeRotateSpeed = -tank[i0].pipeRotationVelocity;
			if (tank[i0].button[6] == true)
				tank[i0].button[6] = false;
			/////////////////////////////////////////////////////////////END button works
			///update();
			///gui
		}
	}
}
////////////////////////////////////////////////////end of main game
////////////////////////////end of funcs


int main()
{
	Socket::Status status = socket.connect("localhost", 10011);

	/////build threads
	Thread sendrecvThread(&sendRecv);
	Thread mainGameThread(&mainGame);

	/////launch threads
	sendrecvThread.launch();
	mainGameThread.launch();
	/////////////////////////////////////
	return 0;
}
