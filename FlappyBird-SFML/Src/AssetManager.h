#pragma once

#include <map>

#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp> todo later

namespace FlappyBird
{	
	/*
	* Probably a good idea to do a Singleton
	*/
	class AssetManager
	{
	public:
		AssetManager() {}
		~AssetManager() {}

		void LoadTexture(std::string name, std::string fileName);
		sf::Texture& GetTexture(std::string name);


		void LoadFont(std::string name, std::string fileName);
		sf::Font& GetFont(std::string name);

	private:
		std::map<std::string, sf::Texture> mTextures;
		std::map<std::string, sf::Font> mFonts;
	};
}


