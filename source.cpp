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

bool playerButton[7] = { 0, 0, 0, 0, 0, 0, 0 };

vector <Walls> wall;
vector <Tanks> tank;
vector <Bullets> bullet;
////////////////////////////end of globals


////////////////////////////funcs

////////////////////////////////////////////////////send & recv from server
void sendRecv()
{
	while (1)
	{
		socket.receive(recvChar, 1024, received);
		cout << recvChar << endl;
	}
}
////////////////////////////////////////////////////end of send & recv from server


int main(){

	Socket::Status status = socket.connect("localhost", 10004);
	socket.send(sendChar, 1024);

	return 0;
}
