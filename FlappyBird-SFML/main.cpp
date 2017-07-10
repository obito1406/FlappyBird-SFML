#include <SFML/Graphics.hpp>	//NOTA: Windows de forma predeterminada usa "\" sin embargo el resto de sistemas usa "/" poner directorios de esta forma asegura poder tener compatibilidad con otros sistemas

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "MyWindow");

	while (window.isOpen())
	{
		//handle events

		//update game logic

		//draw
		window.clear();

		//draw SMFL objects
		window.display();
	}

	return EXIT_SUCCESS;
}