#pragma once

#include <SFML/Graphics.hpp>

#include "Game.h"

#include <vector>

namespace FlappyBird
{
	class Pipe
	{
	public:
		Pipe(GameDataRef data);
		~Pipe();

		void DrawPipes();

	private:
		GameDataRef mData;
		std::vector<sf::Sprite> pipeSprites;
		
	};
}