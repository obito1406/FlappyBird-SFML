#include "AssetManager.h"
#include "Log.h"

namespace FlappyBird 
{
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture texture;

		if (texture.loadFromFile(fileName)) //There are more options for loadFromFile and more interesting methods that starts with load
		{
			mTextures[name] = texture;  //insert() and emplace() can be used to push mapa into a map too. The last one construct the data in the map doesnt copy or move.
		}
		else
		{
			WRITELOG("Couldnt load the texture")
		}
	}

	sf::Texture& AssetManager::GetTexture(std::string name)
	{
		return mTextures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;

		if (font.loadFromFile(fileName)) //There are more options for loadFromFile and more interesting methods that starts with load
		{
			mFonts[name] = font;  //insert() and emplace() can be used to push mapa into a map too. The last one construct the data in the map doesnt copy or move.
		}
		else
		{
			WRITELOG("Couldnt load the font")
		}
	}

	sf::Font& AssetManager::GetFont(std::string name)
	{
		return mFonts.at(name);
	}

}