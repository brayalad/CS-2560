/**
 * MainMenu.cpp
 */
#include "GlobalVariables.h"
#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu(GameData _gameData)
{
    this->gameData = std::move(_gameData);
}

void MainMenu::initialize()
{
    //Sets button an background textures
    background.setTexture(this->gameData->assets.getTexture("Game Background"));
    playButton.setTexture(this->gameData->assets.getTexture("Play Button"));

    //Sets up the score displaying text
    title.setFont(this->gameData->assets.getFont("Score Font"));
    title.setString("SPACE RACE");
    title.setCharacterSize(128);
    title.setFillColor(sf::Color::White);
    title.setOrigin(sf::Vector2f(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2));
    title.setPosition(sf::Vector2f(gameData->window.getSize().x / 2, gameData->window.getSize().y / 5));


    playButton.setPosition((SCREEN_WIDTH / 2) - (playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (playButton.getGlobalBounds().height / 2));
}

void MainMenu::handleInput()
{
    sf::Event event{};

    //Listening for events while in main menu
    while (this->gameData->window.pollEvent(event))
    {
        //Checks if window is closed
        if (event.type == sf::Event::Closed)
        {
            this->gameData->window.close();
        }

        //Checks if user left clicks on the play button
        if (UserInput::isSpriteClicked(this->playButton, sf::Mouse::Left, this->gameData->window))
        {
            this->gameData->gameManager.addState(State(new Game(gameData)), true);//Adds a new game state when button is clicked
        }
    }
}

void MainMenu::draw()
{
    //Redraws the main menu to the screen
    this->gameData->window.clear(sf::Color::Black);
    this->gameData->window.draw(this->background);
    this->gameData->window.draw(this->title);
    this->gameData->window.draw(this->playButton);

    this->gameData->window.display();
}
