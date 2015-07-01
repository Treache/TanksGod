#include "SFML/Graphics.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window( sf::VideoMode( 600, 600 ), "SFML WORK!" );

	sf::Texture texture;

	if (!texture.loadFromFile("Paddle Large.png"))
	{
		std::cout << "Error loading paddle texture :(" << std::endl;
	}

	//sf::Sprite sprite(texture);

	// or

	sf::Sprite sprite;
	sprite.setTexture(texture);

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

		window.draw(sprite);

		window.display( );
	}
}