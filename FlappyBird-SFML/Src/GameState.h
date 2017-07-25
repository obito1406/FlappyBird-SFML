#pragma once
#include "State.h"
#include "Game.h"
#include "Pipe.h"

namespace FlappyBird
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);
		~GameState();

		void Init() override;

		void HandleInput() override;
		void Update(float dt) override;
		void Draw(float dt) override;

	private:
		GameDataRef mData;
		sf::Sprite mBackground;
		Pipe* pipe;

	};
}

