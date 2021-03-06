#ifndef HWFOUR_GAMEOF21_H
#define HWFOUR_GAMEOF21_H

#include <iostream>
#include <string>
#include "GameOf21.h"
#include "Die.h"
#include "Player.h"


static int userRollCount;
static int computerRollCount;
static Die computerDie;
static Die userDie;
static Player computer;
static Player user;

static string getInput();
void newGame();
void winner(int userScore, int computerScore);
void runGame();
int gameOf21();


#endif