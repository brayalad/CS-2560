/**
 * UserInput.cpp
 */
#include "UserInput.h"

bool UserInput::isSpriteClicked(const sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow &window)
{
    //Checks if a button was pressed inside the window
    if (sf::Mouse::isButtonPressed(button))
    {
        sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

        if (playButtonRect.contains(sf::Mouse::getPosition(window)))
        {
            return true;
        }
    }

    return false;
}

//Checks if a certain key was pressed
bool UserInput::isKeyboardClicked(sf::Keyboard::Key key)
{
    return sf::Keyboard::isKeyPressed(key);
}
