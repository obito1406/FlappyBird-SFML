#include "GameOverState.h"
#include "DEFINITIONS.h"

#include <sstream>
#include <iostream>

namespace FlappyBird
{
	GameOverState::GameOverState(GameDataRef data) : mData(data)
	{
		//Same as
		//mData = data;
	}

	//Load the texture of the background
	void GameOverState::Init()
	{
		mData->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		mBackground.setTexture(mData->assets.GetTexture("Game Over Background"));
	}

	void GameOverState::HandleInput()
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
	void GameOverState::Update(float dt)
	{

	}

	//Clear what is on the window, draw allows to render all the stuff in our screen, and finally we display the renderer objects on the screen
	void GameOverState::Draw(float dt)
	{
		mData->window.clear();

		mData->window.draw(mBackground);

		mData->window.display();
	}


	GameOverState::~GameOverState()
	{
	}
}

