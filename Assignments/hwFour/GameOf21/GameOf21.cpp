#include <iostream>
#include <string>
#include "Die.h"
#include "Player.h"

using namespace std;

static int userRollCount;
static int computerRollCount;
static Die computerDie;
static Die userDie;
static Player computer;
static Player user;

string getInput(){
    string userInput;
    getline(cin,userInput);
    return userInput;
}

void newGame(){
    computer = Player();
    user = Player();

    userRollCount = 0;
    computerRollCount = 0;

    cout << "\nYou are playing a Game of 21 against the computer\n"
            "Each of you has a dice that will be rolled. The value\n"
            "of the roll will be added to your score for the game.\n"
            "Once the computer has rolled it's die, you can choose \n"
            "to either roll your die or end the game. Game will also\n"
            "end once a player's score has surpassed 21. Once the game\n"
            "is over, the player with the highest score without exceeding 21 wins.\n" << endl;
}

void winner(int userScore, int computerScore){

    cout << "\nGAME OVER\n" << endl;
    cout << "User Score: " << userScore << endl;
    cout << "Computer Score: " << computerScore << endl;

    if(userScore <= 21 && computerScore <= 21) {
        if (userScore > computerScore)
            cout << "\nYOU WIN" << endl;
        else if (computerScore > userScore)
            cout << "\nCOMPUTER WINS" << endl;
        else if (userScore == computerScore)
            cout << "\nTIE" << endl;
    }
    else{
        if(userScore <= 21 && computerScore > 21)
            cout << "\nYOU WIN" << endl;
        else if (computerScore <= 21 && userScore > 21)
            cout << "\nCOMPUTER WINS" << endl;
        else if (userScore > 21 && computerScore > 21)
            cout << "\nBoth are over 21\nNO WINNER" << endl;
    }
}

void runGame(){

    string userChoice;
    bool initialTurnTaken = false;
    while(user.getScore() <= 21 || computer.getScore() <= 21){

        if(userChoice == "1" || !initialTurnTaken) {
            computerDie.roll();
            computer.increaseScore(computerDie.getValue());
            computerRollCount++;
            cout << "Computer has rolled it's die " << computerRollCount << " time(s)" << endl;

            if(!initialTurnTaken)
                initialTurnTaken = true;
        }

        cout << "\nChoose from one of the two choices:\n"
                "   1. Roll Dice\n"
                "   2. End Game\n" << endl;
        cout << "Enter Choice: ";
        userChoice = getInput();

        if(userChoice == "1"){
            userDie.roll();
            user.increaseScore(userDie.getValue());
            userRollCount++;
            cout << "\nYou have rolled your die " << userRollCount << " time(s)" << endl;
        }
        else if(userChoice == "2")
            break;
        else
            cout << "Invalid Input.\nPlease try again\n" << endl;
    }

    winner(user.getScore(), computer.getScore());

}

int main() {

    computerDie = Die();
    userDie = Die();

    cout << "\nGame Of 21\n"
         << "----------" << endl;

    string userInput;
    while(true){
        cout << "\nWould you like to start a new game? (yes/no)" << endl;
        userInput = getInput();

        if(userInput == "yes"){
            newGame();
            runGame();
        }
        else if(userInput == "no"){
            cout << "\nThank you for playing!" << endl;
            break;
        }
        else
            cout << "Invalid Input.\nPlease Try Again.\n" << endl;

    }

    return 0;
}