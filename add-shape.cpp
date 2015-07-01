#include "SFML/Graphics.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window( sf::VideoMode( 600, 600 ), "SFML WORK!" );

	sf::RectangleShape rectangle(sf::Vector2f(200, 40));

	rectangle.setSize(sf::Vector2f(67, 400));

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

		window.draw(rectangle);

		window.display( );
	}
}