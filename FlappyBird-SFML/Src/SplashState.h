#pragma once

#include <SFML\Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace FlappyBird 
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);
		~SplashState();

		void Init() override;

		void HandleInput() override;
		void Update(float dt) override;
		void Draw(float dt) override;

	private:
		GameDataRef mData;
		sf::Clock mClock;
		sf::Sprite mBackground;

	};

}

