/**
 * Main.cpp
 */
#include "Engine.h"
#include "GlobalVariables.h"

//Start of the program. Program starts from this method
int main(int argc, char *argv[])
{
    /*
     * Instance of the Engine class is created. This class is responsible
     * for running the whole game in a loop.
     */
	Engine gameEngine = Engine(SCREEN_WIDTH, SCREEN_HEIGHT, "SPACE RACE");
	gameEngine.run(); //Starts the game loop

	return 0;
}