#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>

using namespace std;

//tank body
float r = 60 ;
float s = 740 ;

//tank pipe 
float p ;
float q ;



int main()
{
	
	sf::Texture texture;
	if (!texture.loadFromFile("0.jpg"))
	{
		// error...
	}
	
	//key pushes
	bool ka = false;//pipe to left
	bool kd = false;//pipe to right
	bool kU = false;//Up arrow tank move forward
	bool kR = false;//Right arrow tank move right
	bool kL = false;//Left arrow tank move left
	bool kD = false;//Down arrow tank move backward
	bool ks = false;//shooting
	
	
    sf::Window window(sf::VideoMode(800, 600), "tanksGod"  );

   // run the program as long as the window is open
   while (window.isOpen())
   {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
           // if (event.type == sf::Event::Closed)
              //  window.close();
            
            /* 
            if (event.type == sf::Event::LostFocus)
				myGame.pause();

			if (event.type == sf::Event::GainedFocus)
				myGame.resume();
				*/
            
           if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					return 0;
				}
				
				if (event.key.code == sf::Keyboard::A)
				{
					ka == true;
					//rotate pipe to left
				}
				
				if (event.key.code == sf::Keyboard::D)
				{
					kd == true;
					//rotate pipe to right
				}
				
				if (event.key.code == sf::Keyboard::Up)
				{
					kU == true;
					//move forward
				}
				
				if (event.key.code == sf::Keyboard::Down)
				{
					kD == true;
					//move backward
				}
				
				if (event.key.code == sf::Keyboard::Right)
				{
					kR == true;
					//move to right
				}
				
				if (event.key.code == sf::Keyboard::Left)
				{
					kL == true;
					//move to left
				}
				
			}
            
             if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::A)
				{
					ka == false;
					//rotate pipe to left
				}
				
				if (event.key.code == sf::Keyboard::D)
				{
					kd == false;
					//rotate pipe to right
				}
				
				if (event.key.code == sf::Keyboard::Up)
				{
					kU == false;
					//move forward
				}
				
				if (event.key.code == sf::Keyboard::Down)
				{
					kD == false;
					//move backward
				}
				
				if (event.key.code == sf::Keyboard::Right)
				{
					kR == false;
					//move to right
				}
				
				if (event.key.code == sf::Keyboard::Left)
				{
					kL == false;
					//move to left
				}
				
				if (event.key.code == sf::Keyboard::Space)
				{
					ks == false;
					//shoot
				}
			}
        }
       
       //tank body
				
		if ( kL == true )
		{
			r += -13;
		}
				
		if ( kR == true )
		{
			r += 13;
		}
				
		if ( kD == true )
		{
			s += 13;
		}
				
		if ( kU == true )
		{
			s -= 13;
		}
				
		if ( kU == true && kR == true )
		{
			//rotate the tank body to front right
		}
				
		if ( kU == true && kL == true )
		{
			//rotate the tank body to front left
		}
				
		if ( kD == true && kR == true )
		{
			//rotate the tank body to back right
		}
				
				
		if ( kD == true && kL == true )
		{
			//rotate the tank body to back left
		}
				
				
				
		//tank pipe
				
		if ( kd == true )
		{	   
			//rotate tank pipe to right
		}
				
		if ( ka == true )
		{
			//rotate tank pipe to left
		}
				
				
				
		//controls for not leaving window
				
		if ( r>1140 )
			r = 1140;

		if ( p<60 )
			p = 60;


		if ( p> 530 )
			p = 530;


		if ( q>740 )
			q = 740;
				
				
		if ( s<60 )
			s = 60;
				
					
		if ( q > 740 )
			q = 740;
				
				
		if ( s > 740 )
			s = 740;
		if ( s < 60 )
			s = 60;
					
					
		if ( p> 530 )
			p = 530;
		if ( p<60 )
			p = 60;
						
						
		if ( r>1140 )
			r = 1140;
		if ( r<670 )
			r = 670;
				
        
    }
	
    return 0;
}
