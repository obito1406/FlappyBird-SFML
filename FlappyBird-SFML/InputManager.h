#pragma once

#include <SFML/Graphics.hpp>

namespace FlappyBird 
{
	/*
	* Probably a good idea to do a Singleton
	*/
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}
			
		bool IsSpriteClick(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

		sf::Vector2i GetMousePosition(sf::RenderWindow &window); //Vector2 its a 2d vector (x,y). Template that have special typedefs for int vector2i, float vector2f...
	};
}


