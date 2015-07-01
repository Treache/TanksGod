#include "SFML/Graphics.hpp"
#include <iostream>

sf::View view(sf::FloatRect(0, 0, 4000, 4000));

//rectangle.setFillColor(sf::Color(170, 180, 190));
//rectangle.setSize(sf::Vector2f(50, 50));

int main()
{
	sf::RenderWindow window( sf::VideoMode( 600, 600), "TanksGod" );


	sf::RectangleShape wall1(sf::Vector2f(1000, 250));
    wall1.setPosition(sf::Vector2f(1000,0));

    sf::RectangleShape wall2(sf::Vector2f(200, 200));
    wall2.setPosition(sf::Vector2f(0,500));

    sf::RectangleShape wall3(sf::Vector2f(1500, 100));
    wall3.setPosition(sf::Vector2f(500,900));

    sf::RectangleShape wall4(sf::Vector2f(200, 1750));
    wall4.setPosition(sf::Vector2f(2500,500));

    sf::RectangleShape wall5(sf::Vector2f(200, 200));
    wall5.setPosition(sf::Vector2f(3500,500));

    sf::RectangleShape wall6(sf::Vector2f(500, 250));
    wall6.setPosition(sf::Vector2f(500,1000));


    sf::RectangleShape wall7(sf::Vector2f(250, 250));
    wall7.setPosition(sf::Vector2f(1000,1750));

    sf::RectangleShape wall8(sf::Vector2f(750, 100));
    wall8.setPosition(sf::Vector2f(3250,1500));

    sf::RectangleShape wall9(sf::Vector2f(750, 250));
    wall9.setPosition(sf::Vector2f(2000,2000));

    sf::RectangleShape wall10(sf::Vector2f(250, 500));
    wall10.setPosition(sf::Vector2f(0,2000));

    sf::RectangleShape wall11(sf::Vector2f(500, 250));
    wall11.setPosition(sf::Vector2f(500,2500));

    sf::RectangleShape wall12(sf::Vector2f(100, 1000));
    wall12.setPosition(sf::Vector2f(900,2750));

    sf::RectangleShape wall13(sf::Vector2f(750, 200));
    wall13.setPosition(sf::Vector2f(1000,3500));

    sf::RectangleShape wall14(sf::Vector2f(250, 500));
    wall14.setPosition(sf::Vector2f(1500,3000));

    sf::RectangleShape wall15(sf::Vector2f(500, 250));
    wall15.setPosition(sf::Vector2f(1500,2750));

    sf::RectangleShape wall16(sf::Vector2f(50, 50));
    wall16.setPosition(sf::Vector2f(0,3250));

    sf::RectangleShape wall17(sf::Vector2f(500, 100));
    wall17.setPosition(sf::Vector2f(2750,2900));

    sf::RectangleShape wall18(sf::Vector2f(250, 500));
    wall18.setPosition(sf::Vector2f(3250,2500));

    sf::RectangleShape wall19(sf::Vector2f(750, 200));
    wall19.setPosition(sf::Vector2f(2750,3500));

    sf::RectangleShape wall20(sf::Vector2f(250, 250));
    wall20.setPosition(sf::Vector2f(2000,3750));

    sf::RectangleShape wallup(sf::Vector2f(4000, 50));
    wallup.setPosition(sf::Vector2f(0,0));
    wallup.setFillColor(sf::Color(255, 0, 0));

    sf::RectangleShape walldown(sf::Vector2f(4000, 50));
    walldown.setPosition(sf::Vector2f(0,3950));
    walldown.setFillColor(sf::Color(255, 0, 0));

    sf::RectangleShape wallleft(sf::Vector2f(50,4000));
    wallleft.setPosition(sf::Vector2f(0,0));
    wallleft.setFillColor(sf::Color(255, 0, 0));

    sf::RectangleShape wallright(sf::Vector2f(50, 4000));
    wallright.setPosition(sf::Vector2f(3950,0));
    wallright.setFillColor(sf::Color(255, 0, 0));


    window.setView(view);
	while ( window.isOpen( ) )
	{
		sf::Event event;

		while ( window.pollEvent( event ) )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear( );

		window.draw(wall1);
		window.draw(wall2);
		window.draw(wall3);
		window.draw(wall4);
		window.draw(wall5);
		window.draw(wall6);
		window.draw(wall7);
		window.draw(wall8);
		window.draw(wall9);
		window.draw(wall10);
		window.draw(wall11);
		window.draw(wall12);
		window.draw(wall13);
		window.draw(wall14);
		window.draw(wall15);
		window.draw(wall16);
		window.draw(wall17);
		window.draw(wall18);
		window.draw(wall19);
		window.draw(wall20);
        window.draw(wallup);
        window.draw(walldown);
        window.draw(wallleft);
        window.draw(wallright);


		window.display( );
	}

}
