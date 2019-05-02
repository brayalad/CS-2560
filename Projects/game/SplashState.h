#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace gameEngine {

	class SplashState : public State {

	private:
		GameDataRef data;
		sf::Clock clock;
		sf::Texture backgroundTexture;
		sf::Sprite background;

	public: 
		SplashState(GameDataRef data);

		void init();

		void handleInput();
		void update(float dt);
		void draw(float dt);

	};

}