#include <iostream>
#include <string>
#include "Die.h"
#include "Player.h"


static int userRollCount;
static int computerRollCount;
static Die computerDie;
static Die userDie;
static Player computer;
static Player user;

std::string getInput(){
    std::string userInput;
    std::getline(std::cin,userInput);
    return userInput;
}

void newGame(){
    computer = Player();
    user = Player();

    userRollCount = 0;
    computerRollCount = 0;

    std::cout << "\nYou are playing a Game of 21 against the computer\n"
            "Each of you has a dice that will be rolled. The value\n"
            "of the roll will be added to your score for the game.\n"
            "Once the computer has rolled it's die, you can choose \n"
            "to either roll your die or end the game. Game will also\n"
            "end once a player's score has surpassed 21. Once the game\n"
            "is over, the player with the highest score without exceeding 21 wins.\n" << std::endl;
}

void winner(int userScore, int computerScore){

    std::cout << "\nGAME OVER\n" << std::endl;
    std::cout << "User Score: " << userScore << std::endl;
    std::cout << "Computer Score: " << computerScore << std::endl;

    if(userScore <= 21 && computerScore <= 21) {
        if (userScore > computerScore)
            std::cout << "\nYOU WIN" << std::endl;
        else if (computerScore > userScore)
            std::cout << "\nCOMPUTER WINS" << std::endl;
        else if (userScore == computerScore)
            std::cout << "\nTIE" << std::endl;
    }
    else{
        if(userScore <= 21 && computerScore > 21)
            std::cout << "\nYOU WIN" << std::endl;
        else if (computerScore <= 21 && userScore > 21)
            std::cout << "\nCOMPUTER WINS" << std::endl;
        else if (userScore > 21 && computerScore > 21)
            std::cout << "\nBoth are over 21\nNO WINNER" << std::endl;
    }
}

void runGame(){

    std::string userChoice;
    bool initialTurnTaken = false;
    while(user.getScore() <= 21 || computer.getScore() <= 21){

        if(userChoice == "1" || !initialTurnTaken) {
            computerDie.roll();
            computer.increaseScore(computerDie.getValue());
            computerRollCount++;
            std::cout << "Computer has rolled it's die " << computerRollCount << " time(s)" << std::endl;

            if(!initialTurnTaken)
                initialTurnTaken = true;
        }

        std::cout << "\nChoose from one of the two choices:\n"
                "   1. Roll Dice\n"
                "   2. End Game\n" << std::endl;
        std::cout << "Enter Choice: ";
        userChoice = getInput();

        if(userChoice == "1"){
            userDie.roll();
            user.increaseScore(userDie.getValue());
            userRollCount++;
            std::cout << "\nYou have rolled your die " << userRollCount << " time(s)" << std::endl;
        }
        else if(userChoice == "2")
            break;
        else
            std::cout << "Invalid Input.\nPlease try again\n" << std::endl;
    }

    winner(user.getScore(), computer.getScore());

}

int main(int argc, char *argv[]) {

    computerDie = Die();
    userDie = Die();

    std::cout << "\nGame Of 21\n"
         << "----------" << std::endl;

    std::string userInput;
    while(userInput != "no"){
        std::cout << "\nWould you like to start a new game? (yes/no)" << std::endl;
        userInput = getInput();

        if(userInput == "yes"){
            newGame();
            runGame();
        }
        else if(userInput == "no"){
            std::cout << "\nThank you for playing!" << std::endl;
        }
        else
            std::cout << "Invalid Input.\nPlease Try Again.\n" << std::endl;

    }

    return 0;
}