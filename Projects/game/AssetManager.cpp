#include "AssetManager.h"
#include <iostream>

namespace gameEngine {

	void AssetManager::loadTexture(std::string textureName, std::string fileName) {
		sf::Texture texture;

		if (texture.loadFromFile(fileName)) {
			std::cout << "test\n";
			this->textures[textureName] = texture;
		}
	}

	void AssetManager::loadFont(std::string fontName, std::string fileName) {
		sf::Font font;

		if (font.loadFromFile(fileName)) {
			this->fonts[fontName] = font;
		}
	}

}
