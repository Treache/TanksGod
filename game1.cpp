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


}

////////////////////////////////////////////////////end of send & recv from server

////////////////////////////////////////////////////click the buttons
void pressButton()
{

}
////////////////////////////////////////////////////end of click the buttons

////////////////////////////////////////////////////main game
inline void mainGame()
{
	//cout << "Game started" ;

	////
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
			///gui show the pics
		}
	}
}
////////////////////////////////////////////////////end of main game

////////////////////////////end of funcs


int main()
{
	
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
