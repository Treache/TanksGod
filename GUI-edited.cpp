#include "GUI.h"

////////////////////////////////////////////////////build map
void build_Map(std::vector<Walls*>* wall)
{
	//example
	Vector2D center;
	center.x = 1500;
	center.y = 125;
	(*wall).push_back(new Walls(center, 125, 500, 0));
	center.x = 100;
	center.y = 600;
	(*wall).push_back(new Walls(center, 100, 100, 0));
	center.x = 1250;
	center.y = 950;
	(*wall).push_back(new Walls(center, 50, 750, 0));
	center.x = 2600;
	center.y = 1375;
	(*wall).push_back(new Walls(center, 875, 100, 0));
	center.x = 3600;
	center.y = 600;
	(*wall).push_back(new Walls(center, 100, 100, 0));
	center.x = 750;
	center.y = 1250;
	(*wall).push_back(new Walls(center, 125, 250, 0));
	center.x = 3625;
	center.y = 1550;
	(*wall).push_back(new Walls(center, 50, 375, 0));
	center.x = 1250;
	center.y = 1750;
	(*wall).push_back(new Walls(center, 125, 125, 0));
	center.x = 50;
	center.y = 2250;
	(*wall).push_back(new Walls(center, 250, 50, 0));
	center.x = 2250;
	center.y = 2250;
	(*wall).push_back(new Walls(center, 125, 250, 0));
	center.x = 750;
	center.y = 2750;
	(*wall).push_back(new Walls(center, 125, 250, 0));
	center.x = 950;
	center.y = 3250;
	(*wall).push_back(new Walls(center, 500, 50, 0));
	center.x = 25;
	center.y = 3475;
	(*wall).push_back(new Walls(center, 25, 25, 0));
	center.x = 1375;
	center.y = 3600;
	(*wall).push_back(new Walls(center, 100, 375, 0));
	center.x = 1625;
	center.y = 3250;
	(*wall).push_back(new Walls(center, 125, 125, 0));
	center.x = 1750;
	center.y = 2875;
	(*wall).push_back(new Walls(center, 125, 250, 0));
	center.x = 3000;
	center.y = 2950;
	(*wall).push_back(new Walls(center, 50, 250, 0));
	center.x = 3375;
	center.y = 2750;
	(*wall).push_back(new Walls(center, 250, 125, 0));
	center.x = 3125;
	center.y = 3600;
	(*wall).push_back(new Walls(center, 100, 375, 0));
	center.x = 2125;
	center.y = 3875;
	(*wall).push_back(new Walls(center, 125, 125, 0));
	
	
}
////////////////////////////////////////////////////end of build walls

////////////////////////////////////////////////////click the buttons
void press_Button(Players* player)
{
	//player->button[0] = 1;
}
////////////////////////////////////////////////////end of click the buttons

////////////////////////////////////////////////////print the game
void print_Game(std::vector<Walls*> wall, std::vector<Bullets*> bullet, std::vector<Tanks*> tank)
{

}
////////////////////////////////////////////////////end of print the game
