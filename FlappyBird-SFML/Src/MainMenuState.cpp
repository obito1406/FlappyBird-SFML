#include "MainMenuState.h"

#include "DEFINITIONS.h"

#include <sstream>
#include <iostream>

namespace FlappyBird
{
	MainMenuState::MainMenuState(GameDataRef data) : mData(data)
	{
		//Same as
		//mData = data;
	}

	//Load the texture of the background
	void MainMenuState::Init()
	{
		mData->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		mData->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		mData->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		mBackground.setTexture(mData->assets.GetTexture("Main Menu Background"));
		mTitle.setTexture(mData->assets.GetTexture("Game Title"));
		mPlayButton.setTexture(mData->assets.GetTexture("Play Button"));

		//Remenber the origin of the coordinates system in SFML its the top-left corner. "+x" right and "+y" down
		mTitle.setPosition((SCREEN_WIDTH / 2) - (mTitle.getGlobalBounds().width / 2),   //Center it on the X axys. Remenber that the start of the objects its its own top-left origin
							mTitle.getGlobalBounds().height / 2);
		mPlayButton.setPosition((SCREEN_WIDTH / 2) - (mPlayButton.getGlobalBounds().width / 2),
							(SCREEN_HEIGHT / 2) - (mPlayButton.getGlobalBounds().height / 2));
		//NOTE: This could be the work of the assetManager too. Even Changing the coordinates of the objects to work with the bottom-left as the origin and the center
		//of the objects as their origin... but only if its really needed


	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (mData->window.pollEvent(event)) //PollEvent its an event queue. So we will handle all the events on it
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				mData->window.close();
			}
			if (mData->input.IsSpriteClick(mPlayButton, sf::Mouse::Left, mData->window))
			{
				std::cout << "Go to Game Screen";
			}
		}
	}
	
	void MainMenuState::Update(float dt)
	{
		//Not needed
	}

	//Clear what is on the window, draw allows to render all the stuff in our screen, and finally we display the renderer objects on the screen
	void MainMenuState::Draw(float dt)
	{
		mData->window.clear();

		mData->window.draw(mBackground);
		mData->window.draw(mTitle);
		mData->window.draw(mPlayButton);

		mData->window.display();
	}

	MainMenuState::~MainMenuState()
	{
	}
}
