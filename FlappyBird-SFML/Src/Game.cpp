#include "Game.h"
#include "SplashState.h"

namespace FlappyBird
{
	Game::Game(int width, int height, std::string title)
	{
		mData->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		mData->machine.AddState(StateRef(new SplashState(mData)));
		Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation; //frameTime
		float currentTime = mClock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (mData->window.isOpen())
		{
			//1.handle events and changes
			mData->machine.ProcessStateChanges();

			newTime = mClock.getElapsedTime().asSeconds();

			frameTime = newTime - currentTime; //The time that took a frame to be executed

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				mData->machine.GetActiveState()->HandleInput();
				mData->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			mData->machine.GetActiveState()->Draw(interpolation);
		}
	}
}