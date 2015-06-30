#include <cmath>

#include "Classes.h"
int Tanks::tedade_tank = 0;    //vase inke error nadahad fln ezafe shode ast
void Tanks::update()
{
	//mana
	if (this->mana <= 100 - this->mana_plus)
		this->mana += this->mana_plus;
	else
		this->mana = 100;
	//health
	if (this->health <= 100 - this->health_plus)
		this->health += this->health_plus;
	else
		this->health = 100;

	//////////
	this->mass = Tanks::mass0 + 2* this->mana;
	}