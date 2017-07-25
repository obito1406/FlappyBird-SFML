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
			//https://gafferongames.com/post/fix_your_timestep/ ->Explanation of the framerate that comes next. INDEPENDANT FRAMERAE GAMEPLAY

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

			//2.Update our game based on our framerate
			while (accumulator >= dt)
			{
				mData->machine.GetActiveState()->HandleInput();
				mData->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			//3. Draw evrything (This doesnt take time the only thing that can take a big amount of time its the rendering of the physics in our game the "update")
			interpolation = accumulator / dt;  //The time left in accumulator its less than our dt (60fps). So interpolation its the percentage of the frame thats left to render
			mData->machine.GetActiveState()->Draw(interpolation);
		}
	}
}