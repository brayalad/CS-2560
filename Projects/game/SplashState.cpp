#include "SplashState.h"

#include <sstream>
#include "SplashState.h"
#include "DEFINITIONS.h"
#include <iostream>

namespace gameEngine {

	SplashState::SplashState(GameDataRef gameData) : data(gameData) {

	}

	void SplashState::init() {

		data->assets.loadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		background.setTexture(this->data->assets.getTexture("Splash State Background"));

	}

	void SplashState::handleInput() {

		sf::Event event;

		while (data->window.pollEvent(event)) {

			if (sf::Event::Closed == event.type) {
				data->window.close();
			}

		}

	}

	void SplashState::update(float dt) {

		if (clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
			std::cout << "Go To Main Menu" << std::endl;
		}

	}

	void SplashState::draw(float dt) {

		data->window.clear();

		data->window.draw(background);
		data->window.display();
	}

}