#pragma once

#include <SFML/Graphics.hpp>

namespace gameEngine {

	class InputManager {

	public:
		InputManager(){}
		~InputManager(){}

		bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

		sf::Vector2i getMousePosition(sf::RenderWindow &window) const{ return sf::Mouse::getPosition(window); }

	};

}
