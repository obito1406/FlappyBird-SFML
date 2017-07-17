#pragma once

#include "State.h"
#include "Game.h"
#include <SFML\Graphics.hpp>

namespace FlappyBird
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);
		~MainMenuState();

		void Init() override ;

		void HandleInput() override;
		void Update(float dt) override;
		void Draw(float dt) override;

	private:
		GameDataRef mData;
		
		sf::Sprite mBackground;
		sf::Sprite mTitle;
		sf::Sprite mPlayButton;

	};
}



