//Main.cpp
#include "Engine.h"
#include "GlobalVariables.h"


int main(int argc, char *argv[])
{
	Engine gameEngine = Engine(SCREEN_WIDTH, SCREEN_HEIGHT, "SPACE RACE");
	gameEngine.run();

	return 0;
}