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
	this->mass = Tanks::mass0 + 2 * this->mana;

	//////buttons
	//pishran
	if (this->button[0] == 1 && this->button[1] == 0)
	{
		this->Niroo_Pishran.x = Tanks::pishran * cos(alfa * PI / 180);
		this->Niroo_Pishran.y = Tanks::pishran * sin(alfa * PI / 180);
	}
	else
	{
		this->Niroo_Pishran.x = 0;
		this->Niroo_Pishran.y = 0;
	}
	//charkheshe badane
	if (this->button[2] == 1 && this->button[3] == 0)
		this->alfa += Tanks::alfa_velocity;
	else if (this->button[2] == 0 && this->button[3] == 1)
		this->alfa -= Tanks::alfa_velocity;
	//charkheshe loole
	if (this->button[4] == 1 && this->button[5] == 0)
		this->beta += Tanks::beta_velocity;
	else if (this->button[4] == 0 && this->button[5] == 1)
		this->beta -= Tanks::beta_velocity;
	//shellike toop
	if (this->button[6] == 1)
		if (mana >= mana_bullet)
		{
			//shellik
			//part shodan aqab
		}

}