#include "InputManager.h"

namespace FlappyBird
{
	bool InputManager::IsSpriteClick(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			// IntRect = Rectangle. A temporarry rectangle that we used to keep the sprite position.
			sf::IntRect tempRect(object.getPosition().x , object.getPosition().y,
								 object.getGlobalBounds().width, object.getGlobalBounds().height); 		

			if (tempRect.contains(sf::Mouse::getPosition(window))) //Check if the mouse was click on the sprite, the window its needed to calculate the position of the mouse relative to the window coordinates
			{
				return true;
			}			
		}

		return false;
	}

	//Bit useless method since sf::Mouse::getPosition(window) does exactly the same...
	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window)
	{
		return sf::Mouse::getPosition(window);
	}

}
