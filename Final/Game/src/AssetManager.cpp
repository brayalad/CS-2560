/**
 * AssetManager.cpp
 */

#include "AssetManager.h"
#include <iostream>


void AssetManager::loadTexture(const std::string& textureName, const std::string& textureFileName)
{
    sf::Texture textureAsset;

    //Loads texture to texture map if found
    if (textureAsset.loadFromFile(textureFileName))
    {
        this->textures.insert(this->textures.begin(), std::pair<std::string, sf::Texture>(textureName, textureAsset));
    }
    else
    {
        std::cout << "TEXTURE FILE NOT FOUND" << std::endl;
    }
}

void AssetManager::loadFont(const std::string& fontName, const std::string& fontFileName)
{
    sf::Font fontAsset;

    //Loads font to font map if found
    if (fontAsset.loadFromFile(fontFileName))
    {
        this->fonts.insert(this->fonts.begin(), std::pair<std::string, sf::Font>(fontName, fontAsset));
    }
    else
    {
        std::cout << "FONT FILE NOT FOUND" << std::endl;
    }
}

//Returns requested texture
const sf::Texture& AssetManager::getTexture(const std::string& textureName) const
{
    return this->textures.at(textureName);
}

//Returns requested font
const sf::Font& AssetManager::getFont(const std::string& fontName) const
{
    return this->fonts.at(fontName);
}
