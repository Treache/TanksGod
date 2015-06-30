#define PI 3.14159265


class Vector2D
{
public:

	int x;
	int y;
};

class Walls
{
public:
	static const int tedade_vijegi = 6;
	int ID;

	Vector2D centerPoint;
	int width;
	int lenght;
	int alfa;//zavie

	Vector2D point[4];
	Vector2D variable;
	int equation[4];

};


class Bullets
{
public:
	static const int tedade_vijegi = 4;
	static const int explode_time = 2;
	static int tedade_bullet;

	int ID;

	Vector2D centerPoint;
	static int radius;

	static const int mass = 15;
	Vector2D velocity;

	double time_left;
	////////COLLISION
	Vector2D collision_Point_bullet;
	int other_obj_id;//id e oon1ki obj k behesh barkhord karde
	int collision_Point_other_obj;//moadele masire oon1ki obj k be in barkhord karde
	int equation;//x^2+y^2=r^2

	////////////////
	Bullets(int ID, Vector2D centerPoint);
	////////////////
	
	bool check_Collision(Walls);
	bool check_Collision(Bullets);

	void update();

};


class Tanks
{
public:
	static const int tedade_vijegi = 12;
	static int tedade_tank; 
	int ID; 

	Vector2D centerPoint; 
	static const int width = 10;
	static const int length = 10;

	static const int mass0 = 100;
	int mass; 
	int mana; 
	static const int mana_bullet = -30;
	int health; 
	static const int health_bullet = -30;

	static const int mana_plus = 2;
	static const int health_plus = 3;


	double alfa;//zavie badane 
    static const int alfa_velocity = 10;
	double beta;//zavie loole 
	static const int beta_velocity = 10;


	static const int pishran = 10;//meqdar adadie niroo vase jlo raftan
	static const int pasran = -5;//meqdar adadie niroo vase dande aqab!
	Vector2D Niroo_Pishran;//meqdare niroo dar rastaye x o y
	//int friction;//meqdar adadie friction
	const double friction_Const = 0.1;//adad sabete fk vase estekak
	Vector2D Niroo_Friction;//nirooye estekak dar rastaye x o y    
	Vector2D final_Force;
	Vector2D acceleration;
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


	void update();
	////////COLLISION
	Vector2D point[4];
	Vector2D variable;
	int equation[4];

	bool check_Collision(Walls);
	bool check_Collision(Tanks);
	bool check_Collision(Bullets);
};
