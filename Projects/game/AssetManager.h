#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace gameEngine{

	class AssetManager {

	private:
		std::map<std::string, sf::Texture> textures;
		std::map<std::string, sf::Font> fonts;

	public:
		AssetManager(){}
		~AssetManager(){}

		void loadTexture(std::string textureName, std::string fileName);
		const sf::Texture& getTexture(std::string textureName) const { return this->textures.at(textureName); }

		void loadFont(std::string fontName, std::string fileName);
		const sf::Font& getFont(std::string fontName) const { return this->fonts.at(fontName); }


	};

}