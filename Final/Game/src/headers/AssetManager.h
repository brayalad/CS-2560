//AssetManager.h
#pragma once

#include <map>
#include <SFML/Graphics.hpp>


class AssetManager
{
private:
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Font> fonts;

public:
    AssetManager() = default;
    ~AssetManager() = default;

    void loadTexture(const std::string& textureName, const std::string& textureFileName);
    void loadFont(const std::string& fontName, const std::string& fontFileName);

    const sf::Texture& getTexture(const std::string& textureName) const;
    const sf::Font& getFont(const std::string& fileName) const;
};

