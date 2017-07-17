#pragma once


#include <memory>
#include <SFML/Graphics.hpp>

#include "StateMachine.h"
#include "InputManager.h"
#include "AssetManager.h"

namespace FlappyBird
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game 
	{
	public:
		Game(int width, int height, std::string title);
	
	private:
		// Updates run at 60 per second.
		const float dt = 1.0f / 60.0f;
		sf::Clock mClock;
		GameDataRef mData = std::make_shared<GameData>(); //Constructs an object of type T and wraps it in a std::shared_ptr using args as the parameter list for the constructor of T. http://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared

		void Run();
	};
}


