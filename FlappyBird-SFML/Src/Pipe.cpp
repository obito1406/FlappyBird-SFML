#include "Pipe.h"

namespace FlappyBird
{
	Pipe::Pipe(GameDataRef data) : mData(data)
	{

	}

	Pipe::~Pipe()
	{

	}

	void Pipe::DrawPipes()
	{
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			mData->window.draw(pipeSprites.at(i));
		}
	}

}