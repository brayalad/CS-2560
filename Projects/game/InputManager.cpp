#include "InputManager.h"

namespace gameEngine {

	bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window) {

		if (sf::Mouse::isButtonPressed(button)) {
			
			auto x_position = object.getPosition().x;
			auto y_position = object.getPosition().y;
			auto width_bounds = object.getGlobalBounds().width;
			auto height_bounds = object.getGlobalBounds().height;
			
			sf::IntRect tempRect(x_position, y_position, width_bounds, height_bounds);

			if (tempRect.contains(sf::Mouse::getPosition(window)))
				return true;
	
		}

		return false;
	}

}
