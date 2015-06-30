class Vector2D
{
public:

	int x;
	int y;
};

class Walls
{
public:
	static const int tedade_vijegi = 10;
	int ID;

	Vector2D centerPoint;
	int width;
	int lenght;
};


class Bullets
{
public:
	static const int tedade_vijegi = 10;
	static int tedade_bullet;

	int ID;

	Vector2D centerPoint;
	static int radius;

	Vector2D velocity;

	////////////////////
	Bullets(int ID, Vector2D centerPoint);
	/////////////
};


class Tanks
{
public:
	static const int tedade_vijegi = 10;
	static int tedade_tank; 
	int ID; 

	Vector2D centerPoint; 
	static const int width = 10;
	static const int length = 10;

	Vector2D velocity;

	///////player buttons
	bool button[7];
	//button[0]::jlo
	//button[1]::aqab
	//button[2]::gardesh be chap
	//button[3]::gardesh be rast
	//button[4]::pipe be chap
	//button[5]::pipe be rast
	//button[6]::shellik

};

