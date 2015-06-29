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


	Socket::Status status = socket.connect("localhost", 10006);
	socket.send(sendChar, 1024);

	return 0;
}