#include "SplashState.h"

#include"SplashState.h"
#include "MainMenuState.h"
#include "DEFINITIONS.h"

#include <sstream>
#include <iostream>

namespace FlappyBird
{
	SplashState::SplashState(GameDataRef data) : mData(data)
	{
		//Same as
		//mData = data;
	}

	//Load the texture of the background
	void SplashState::Init()
	{
		mData->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		mBackground.setTexture(mData->assets.GetTexture("Splash State Background"));
	}

	void SplashState::HandleInput()
	{
		sf::Event event;

		while (mData->window.pollEvent(event)) //PollEvent its an event queue. So we will handle all the events on it
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				mData->window.close(); 
			}
		}
	}
	//Check how many seconds have past
	void SplashState::Update(float dt)
	{
		if (mClock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			mData->machine.AddState(StateRef(new MainMenuState(mData)), true);
		}
	}

	//Clear what is on the window, draw allows to render all the stuff in our screen, and finally we display the renderer objects on the screen
	void SplashState::Draw(float dt)
	{
		mData->window.clear();

		mData->window.draw(mBackground);

		mData->window.display();
	}
	
	
	SplashState::~SplashState()
	{
	}
}
