//UserInput.h
#pragma once

#include <SFML/Graphics.hpp>

/**
 * UserInput is repsponsible for checking for user input
 * Checks for either mouse clicks or keyboard clicks. Is used
 * to check if their has been user input and if so respond to that
 * certain kind of event
 */
class UserInput
{
public:
    /**
     * Default constructor
     */
    UserInput() = default;
    /**
     * Default deconstructor
     */
    ~UserInput() = default;

    /**
     * Static method that checks if a sprite has been clicked on
     * @param object The sprite being checked if has been clicked
     * @param button The botton pressed on the mouse
     * @param window The games window
     * @return If the object sprite passed in has been clicked by the mouse button passed in, in the window passed in
     */
    static bool isSpriteClicked(const sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow &window);
    /**
     * Static method that checks if a certain key has been pressed
     * @param key Key being checked
     * @return If the key passed in was pressed.
     */
    static bool isKeyboardClicked(sf::Keyboard::Key key);
};
