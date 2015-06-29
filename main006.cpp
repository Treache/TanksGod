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
		///////////////////////////send to server
		sendChar[0] = wall.size();
		for (int j = 0; j < wall.size(); j++)
		{
			sendChar[Walls::tedade_vijegi * j + 1] = wall[j].ID;
			sendChar[Walls::tedade_vijegi * j + 2] = wall[j].centerPoint.x;
			sendChar[Walls::tedade_vijegi * j + 3] = wall[j].centerPoint.y;
			sendChar[Walls::tedade_vijegi * j + 4] = wall[j].width;
			sendChar[Walls::tedade_vijegi * j + 5] = wall[j].lenght;
			sendChar[Walls::tedade_vijegi * j + 6] = wall[j].alfa;
		}

		sendChar[wall.size() * Walls::tedade_vijegi + 1] = bullet.size();
		for (int j = 0; j < bullet.size(); j++)
		{
			sendChar[wall.size() * Walls::tedade_vijegi + Bullets::tedade_vijegi * j + 2] = bullet[j].ID;
			sendChar[wall.size() * Walls::tedade_vijegi + Bullets::tedade_vijegi * j + 3] = bullet[j].centerPoint.x;
			sendChar[wall.size() * Walls::tedade_vijegi + Bullets::tedade_vijegi * j + 4] = bullet[j].centerPoint.y;
			sendChar[wall.size() * Walls::tedade_vijegi + Bullets::tedade_vijegi * j + 5] = bullet[j].time_left;
		}
		sendChar[wall.size() * Walls::tedade_vijegi + bullet.size() * Bullets::tedade_vijegi + 2] = tank.size();
		for (int j = 0; j < tank.size(); j++)
		{
			sendChar[wall.size() * Walls::tedade_vijegi + bullet.size() * Bullets::tedade_vijegi + Tanks::tedade_vijegi * j + 3] = tank[j].ID;
			sendChar[wall.size() * Walls::tedade_vijegi + bullet.size() * Bullets::tedade_vijegi + Tanks::tedade_vijegi * j + 4] = tank[j].tedade_tank;
			sendChar[wall.size() * Walls::tedade_vijegi + bullet.size() * Bullets::tedade_vijegi + Tanks::tedade_vijegi * j + 5] = tank[j].centerPoint.x;
			sendChar[wall.size() * Walls::tedade_vijegi + bullet.size() * Bullets::tedade_vijegi + Tanks::tedade_vijegi * j + 6] = tank[j].centerPoint.y;
			sendChar[wall.size() * Walls::tedade_vijegi + bullet.size() * Bullets::tedade_vijegi + Tanks::tedade_vijegi * j + 7] = tank[j].mana;
			sendChar[wall.size() * Walls::tedade_vijegi + bullet.size() * Bullets::tedade_vijegi + Tanks::tedade_vijegi * j + 8] = tank[j].health;
			sendChar[wall.size() * Walls::tedade_vijegi + bullet.size() * Bullets::tedade_vijegi + Tanks::tedade_vijegi * j + 9] = tank[j].alfa;
			sendChar[wall.size() * Walls::tedade_vijegi + bullet.size() * Bullets::tedade_vijegi + Tanks::tedade_vijegi * j + 10] = tank[j].beta;
			sendChar[wall.size() * Walls::tedade_vijegi + bullet.size() * Bullets::tedade_vijegi + Tanks::tedade_vijegi * j + 11] = tank[j].acceleration.x;
			sendChar[wall.size() * Walls::tedade_vijegi + bullet.size() * Bullets::tedade_vijegi + Tanks::tedade_vijegi * j + 12] = tank[j].acceleration.y;
			sendChar[wall.size() * Walls::tedade_vijegi + bullet.size() * Bullets::tedade_vijegi + Tanks::tedade_vijegi * j + 13] = tank[j].velocity.x;
			sendChar[wall.size() * Walls::tedade_vijegi + bullet.size() * Bullets::tedade_vijegi + Tanks::tedade_vijegi * j + 14] = tank[j].velocity.y;
		}
	}
	///////////////////////////////////////end sending

	//////////////////////receive from server
	for (int i = 0; i < recvChar[0]; i++)
	{
		wall[i].ID = recvChar[i * Walls::tedade_vijegi + 1];
		wall[i].centerPoint.x = recvChar[i * Walls::tedade_vijegi + 2];
		wall[i].centerPoint.y = recvChar[i * Walls::tedade_vijegi + 3];
		wall[i].width = recvChar[i * Walls::tedade_vijegi + 4];
		wall[i].lenght = recvChar[i * Walls::tedade_vijegi + 5];
		wall[i].alfa = recvChar[i * Walls::tedade_vijegi + 6];
	}

	for (int i = recvChar[0] * Walls::tedade_vijegi + 1; i < recvChar[recvChar[0] * Walls::tedade_vijegi + 1]; i++)
	{
		bullet[i].ID = recvChar[recvChar[0] * Walls::tedade_vijegi + i * Bullets::tedade_vijegi + 2];
		bullet[i].centerPoint.x = recvChar[recvChar[0] * Walls::tedade_vijegi + i * Bullets::tedade_vijegi + 3];
		bullet[i].centerPoint.y = recvChar[recvChar[0] * Walls::tedade_vijegi + i * Bullets::tedade_vijegi + 4];
		bullet[i].time_left = recvChar[recvChar[0] * Walls::tedade_vijegi + i * Bullets::tedade_vijegi + 5];
	}

	for (int i = recvChar[0] * Walls::tedade_vijegi + recvChar[recvChar[0] * Walls::tedade_vijegi + 1] * Bullets::tedade_vijegi + 2; i < recvChar[recvChar[0] * Walls::tedade_vijegi + recvChar[recvChar[0] * Walls::tedade_vijegi] * Bullets::tedade_vijegi + 2 - 1]; i++)
	{
		tank[i].ID = recvChar[recvChar[0] * Walls::tedade_vijegi + recvChar[recvChar[0] * Walls::tedade_vijegi] * Bullets::tedade_vijegi + 3];
		tank[i].tedade_tank = recvChar[recvChar[0] * Walls::tedade_vijegi + recvChar[recvChar[0] * Walls::tedade_vijegi] * Bullets::tedade_vijegi + 4];
		tank[i].centerPoint.x = recvChar[recvChar[0] * Walls::tedade_vijegi + recvChar[recvChar[0] * Walls::tedade_vijegi] * Bullets::tedade_vijegi + 5];
		tank[i].centerPoint.y = recvChar[recvChar[0] * Walls::tedade_vijegi + recvChar[recvChar[0] * Walls::tedade_vijegi] * Bullets::tedade_vijegi + 6];
		tank[i].mana = recvChar[recvChar[0] * Walls::tedade_vijegi + recvChar[recvChar[0] * Walls::tedade_vijegi] * Bullets::tedade_vijegi + 7];
		tank[i].health = recvChar[recvChar[0] * Walls::tedade_vijegi + recvChar[recvChar[0] * Walls::tedade_vijegi] * Bullets::tedade_vijegi + 8];
		tank[i].alfa = recvChar[recvChar[0] * Walls::tedade_vijegi + recvChar[recvChar[0] * Walls::tedade_vijegi] * Bullets::tedade_vijegi + 9];
		tank[i].beta = recvChar[recvChar[0] * Walls::tedade_vijegi + recvChar[recvChar[0] * Walls::tedade_vijegi] * Bullets::tedade_vijegi + 10];
		tank[i].acceleration.x = recvChar[recvChar[0] * Walls::tedade_vijegi + recvChar[recvChar[0] * Walls::tedade_vijegi] * Bullets::tedade_vijegi + 11];
		tank[i].acceleration.y = recvChar[recvChar[0] * Walls::tedade_vijegi + recvChar[recvChar[0] * Walls::tedade_vijegi] * Bullets::tedade_vijegi + 12];
		tank[i].velocity.x = recvChar[recvChar[0] * Walls::tedade_vijegi + recvChar[recvChar[0] * Walls::tedade_vijegi] * Bullets::tedade_vijegi + 13];
		tank[i].velocity.y = recvChar[recvChar[0] * Walls::tedade_vijegi + recvChar[recvChar[0] * Walls::tedade_vijegi] * Bullets::tedade_vijegi + 14];
	}

	//////////////////////////////////////end receiving


	Socket::Status status = socket.connect("localhost", 10006);
	socket.send(sendChar, 1024);

	return 0;
}