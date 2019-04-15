// SFML_Test.cpp : snake game
//#include "pch.h"
#include <SFML/Graphics.hpp>   //using namespace sf
#include <time.h>

//dimensions for window size and background
int num_vertBox = 30, num_horzBox = 20;
int size = 16; //number of pixels
int w = size * num_horzBox;  //background number of pixels in width
int h = size * num_vertBox;    //background number of pixels in height


//Snake initial speed Delay
float delay = 0.1f;

//Actual Snake in game is an array of x,y coordinates of sprite2
struct Snake
{
	int x, y;        //each sprite of snake needs an x,y coordinate
};

//***NEW*** this is the fruit or food that the snake will eat
struct Fruit
{
	int x, y;    // only need one sprite needed for one food item
}food;

//move snake head based on user input and body by incrementing 
//forward by iterating through arrays previous position
//Takes the player snake, its length, and current direction as parameters
void move(Snake *s, int *snake_length, int direction) {

	//1st update body so everything updates in proper order
	//move the body only!  s[0] = head will not be changed here
	for (int i = *snake_length; i > 0; i--)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}
	//2nd update the head
	//Head of snake, s[0] depends on direction user inputs 
	//if user presses up
	if (direction == 0)
		s[0].y -= 1;

	//if user presses down
	if (direction == 1)
		s[0].y += 1;

	//if user presses left
	if (direction == 2)
		s[0].x -= 1;

	//if user presses right
	if (direction == 3)
		s[0].x += 1;


	//***NEW*** If Snake eats food it should grow
	//check if snake head = food location
	if (((s[0].x) == food.x) && ((s[0].y) == food.y))
	{
		//increment snake
		*snake_length=*snake_length+1;

		//Speed up the game
		delay /= 1.05f;

		//Randomly place food somewhere else
		food.x = rand() % num_horzBox;
		food.y = rand() % num_vertBox;
	}

	//***NEW*** Boundary Checking snake as is hits screen end
	//loop snake back on other side
	//LEFT and RIGHT
	if (s[0].x > num_horzBox)
		s[0].x = 0;
	if (s[0].x < 0)
		s[0].x = num_horzBox;
	//TOP and BOTTOM
	if (s[0].y > num_vertBox)
		s[0].y = 0;
	if (s[0].y < 0)
		s[0].y = num_vertBox;

	//***NEW*** Check if you eat body of snake
	for (int i = 1; i < *snake_length; i++)
	{
		//Cut Snake body from place eaten
		if (s[0].x == s[i].x && s[0].y == s[i].y)
			*snake_length = i;
	}
}

int main(int argc, char** argv)
{
	//Setting pseudorandom time, TODO:discuss true random vs pseudorandom 
	srand(time(0));

	//Snake variables to dertermine length and direction
	int direction_player_one = 0,   //direction snake 1 is moving 
	    direction_player_two = 0,	//direction snake 2 is moving
	   *snake_length_player_one = new int(4), //initial size is 4 
	   *snake_length_player_two = new int(4); 

	Snake *s1 = new Snake[100]; //Snake for player one
	Snake *s2 = new Snake[100];	//Snake for player two

	//Window that we can play the game in 
	sf::RenderWindow window(sf::VideoMode(w, h), "Snake Game");

	//Textures load an image into the GPU Memory
	sf::Texture t1, t2, t3, t4;
	t1.loadFromFile("image/white.png"); //Background color
	t2.loadFromFile("image/red.png"); //Player one color
	t3.loadFromFile("image/fruit.png"); //Changed fruit color to PNG of a watermelon
	t4.loadFromFile("image/green.png"); // Player two color

	//Sprite has physical dimmensions that can be set in 
	//coordinate system, setPosition(x,y), and drawn on screen
	sf::Sprite sprite1(t1); //Background
	sf::Sprite sprite2(t2); // Player One
	sf::Sprite sprite3(t3);	//Fruit
	sf::Sprite sprite4(t4);	//Player Two

	//***NEW*** initially place food somewhere on screen
	food.x = 10;
	food.y = 10;

	sf::Clock clock;
	float timer = 0.0f;
	while (window.isOpen())
	{
		
		//Error in class I placed this before the while loop
		//Should be placed in while loop as shown here to update
		//timer 
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		//Allow us to check when a user does something
		sf::Event e;

		//Check when the window is closed
		while (window.pollEvent(e))
		{
			//If user presses x in the top right, Windows, top left, Mac,  close the window
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//Control for Snake 1 by User
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) direction_player_one = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) direction_player_one = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) direction_player_one = 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) direction_player_one = 3;

		//Control for Snake 2 by User
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction_player_two = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction_player_two = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) direction_player_two = 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction_player_two = 3;

		if (timer > delay)
		{
			timer = 0; //reset timer
			move(s1, snake_length_player_one, direction_player_one);//move Snake one sprite forward
			move(s2, snake_length_player_two, direction_player_two);//move Snake two sprite forward
			
		}
		/*****************
		//Draw in window
		*****************/
		window.clear();    //clear the window so new frame can be drawn in

		//NOTE: Order matters as we will draw over items listed first. 
		//Hence the background should be the first thing you will always do
		//1st: Draw Background first
		for (int i = 0; i < num_horzBox; i++)
		{
			for (int j = 0; j < num_vertBox; j++)
			{
				//Set position of sprite1 one at a time
				sprite1.setPosition(i*size, j*size);
				//Draw sprite1 but, do not show it on screen. 
				window.draw(sprite1);
			}
		}

		//2nd: Then Draw snake otherwise background will be drawn over snake if order was reversed with background
		for (int i = 0; i < *snake_length_player_one; i++)
		{
			//position sprite2 one at a time
			sprite2.setPosition(s1[i].x*size, s1[i].y*size);
			//Draw sprite2 one at a time by drawing over background
			window.draw(sprite2);
		}
		for (int i = 0; i < *snake_length_player_two; i++)
		{
			//position sprite2 one at a time
			sprite4.setPosition(s2[i].x*size, s2[i].y*size);
			//Draw sprite2 one at a time by drawing over background
			window.draw(sprite4);
		}

		//***NEW*** 3rd: Draw Fruit
		sprite3.setPosition(food.x*size, food.y*size);
		window.draw(sprite3);

		//Show everything we have drawn on the screen
		window.display();
	}
	return 0;
}
