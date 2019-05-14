//UserInput.h
#pragma once

#include <SFML/Graphics.hpp>

class UserInput
{
public:
    UserInput() = default;
    ~UserInput() = default;

    static bool isSpriteClicked(const sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow &window);
    static bool isKeyboardClicked(sf::Keyboard::Key key);
};
