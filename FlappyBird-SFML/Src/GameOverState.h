#pragma once

#include "State.h"
#include "Game.h"

namespace FlappyBird
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data);
		~GameOverState();

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

