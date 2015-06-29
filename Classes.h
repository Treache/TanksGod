class Vector2D
{
public:

	int x;
	int y;
};

class Walls
{
public:
	int ID;

	Vector2D centerPoint;
	int width;
	int lenght;
};


class Bullets
{
public:
	int ID;

	Vector2D centerPoint;
	
};


class Tanks
{
public:
	int ID;

	Vector2D centerPoint;
	int width;
	int length;

	Vector2D velocity;

};
