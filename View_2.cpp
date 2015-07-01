#include "SFML/Graphics.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");

	sf::View view(sf::FloatRect(0, 0, 300, 300));

	window.setView(view);

	/*view.zoom(4.0);
	view.zoom(1.5);*/

	view.setSize(sf::Vector2f(4000, 4000));
	view.setSize(sf::Vector2f(4000, 4000));
	view.setSize(sf::Vector2f(4000, 4000));
	view.setSize(sf::Vector2f(4000, 4000));

	window.setView(view);

	sf::Sprite background;

	sf::Texture texture;

	if (!texture.loadFromFile("Vertex Example.png"))
	{
		std::cout << "ERROR" << std::endl;
	}

	background.setTexture(texture);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();

		window.draw(background);

		window.display();
	}
}