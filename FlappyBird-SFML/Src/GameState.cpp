#include "GameState.h"
#include "DEFINITIONS.h"

#include <sstream>
#include <iostream>

namespace FlappyBird
{
	GameState::GameState(GameDataRef data) : mData(data)
	{
		//Same as
		//mData = data;
	}

	//Load the texture of the background
	void GameState::Init()
	{
		mData->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		mBackground.setTexture(mData->assets.GetTexture("Game Background"));
		mData->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
		mBackground.setTexture(mData->assets.GetTexture("Pipe Up"));
		mData->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
		mBackground.setTexture(mData->assets.GetTexture("Pipe Down"));

		pipe = new Pipe(mData);
	}

	void GameState::HandleInput()
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
	void GameState::Update(float dt)
	{

	}

	//Clear what is on the window, draw allows to render all the stuff in our screen, and finally we display the renderer objects on the screen
	void GameState::Draw(float dt)
	{
		mData->window.clear();

		//While Drawing the order does matter. The pipes will be shown over the background since they where draw later
		mData->window.draw(mBackground);
		pipe->DrawPipes();

		mData->window.display();
	}


	GameState::~GameState()
	{
		delete pipe;
	}
}

