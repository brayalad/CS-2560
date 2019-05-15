//AssetManager.h
#pragma once

#include <map>
#include <SFML/Graphics.hpp>

/**
 * The AssetManager class is in charge of managing the
 * the assets that the game will need. It does this by
 * storing the game's assets in a map that can be accessed
 * throughout the game. It is instantiated at the begining
 * when when the game runs
 */
class AssetManager
{
private:
    /**
     * Map that holds the game's textures
     * Maps a string to a certain texture
     */
    std::map<std::string, sf::Texture> textures;
    /**
     * Map that holds the game's fonts
     * Maps a string to a certain font
     */
    std::map<std::string, sf::Font> fonts;

public:
    /**
     * Default constructor
     */
    AssetManager() = default;
    /**
     * Default deconstructor
     */
    ~AssetManager() = default;

    /**
     * Loads a texture into the texture map contained in the AssetManager
     * @param textureName The String that will act as a key for the texture
     * @param textureFileName The texture itself
     */
    void loadTexture(const std::string& textureName, const std::string& textureFileName);
    /**
     * Loads a font into the font map contained in the AssetManager
     * @param fontName The string that will act as a key for the font
     * @param fontFileName The font itself
     */
    void loadFont(const std::string& fontName, const std::string& fontFileName);

    /**
     * Returns the texture which the string passed in is mapped to
     * @param textureName The string acting as a key
     * @return The texture mapped to textureName
     */
    const sf::Texture& getTexture(const std::string& textureName) const;
    /**
     * Returns the font which the string passed in is mapped to
     * @param fileName The string acting as a key
     * @return The font mapped to fileName
     */
    const sf::Font& getFont(const std::string& fileName) const;
};

