/*
	TicTacToe.c
	
	Write a program that allows two players to play a game of tic-tac-toe. Use a two-
	dimensional char arry with three rows and three columns as the game board. Each
	element of array should be initialzed with an asterisk(*). The program should run a
	loop that does the following:
		* Displays the contents of the board array.
		* Allows player 1 to select a location on the board for an X. The program should ask
		  the user to enter the row and column numbers.
		* Allows player 2 to select a location on the board for an O. The program should ask
		  the user to enter the row and column numbers.
		* Determines whether a player has won, or a tie has occurred. If a player has won,
		  the prgram should declare the player the winner and end. If a tie has occurred, the 
		  program should display an appropriate message and end.
	Player 1 wins when there are three Xs in a row on the game board. The Xs can appear in a 
	row, in a column, or a diagonally across the board. Player 2 wins when there are three Os in
	a row on the game board. The Os can appear in a row, in a column, or diagnolly across 
	the board. A tie occurs when all of the location on the board are full, but there is no winner.

	Created on: Feb 16, 2019
		Author: bryanayala
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Two-dimentional array to represent the game board*/
char gameBoard [3][3];

/*
	Initializes the board with asteriks (*)
*/
void initializeBoard(){

	for(int i=0; i<3; ++i)
		for(int j=0; j<3;++j)
			gameBoard[i][j] = '*';

}

/*
	Prints the two-dimentional array representing the 
	game board to the console
*/
void printBoard(){

	printf("\n    1   2   3\n");
	printf("  -----------\n");
	for(int i=0; i<3; ++i){

		printf("%d|  ", (i+1));
		for(int j=0; j<3;++j){
			printf("%c   ", gameBoard[i][j]);
		}

		if(i != 2)
			printf("\n |\n");
		else
			printf("\n\n");
	}

}

/*
	Checks for an error in user input and informs the user of solutions
*/
void checkInputError(int row, int column){

	printf("\nInvalid input detected.\n");
	if(row < 0 || row > 2 || column < 0 || column > 2){
		if(row < 0 || row > 2)
			printf("The row chosen is out of bounds.\n");
		if(column < 0 || column > 2)
			printf("The column chosen is out of bounds.\n");
	}
	else{
		if(gameBoard[row][column] != '*')
			printf("The position you chose has already been picked\n");
	}
	printf("Please try again with a valid input.\n\n");
	printBoard();
}

/*
	Function that allows player 1 to take their turn in the game.
	Player 1 inputs both the row and column they wish to take their 
	turn on and adds an X
*/
void playerOne(){

	int playerOneRow;
	int playerOneColumn;

	printf("Player One's Turn\n");

	printf("Enter the row number: ");
	scanf("%d", &playerOneRow);

	printf("Enter the column number: ");
	scanf("%d", &playerOneColumn);

	playerOneRow--;
	playerOneColumn--;

	/*Checks if all user input is valid*/
	if(playerOneRow >= 0 && playerOneRow <= 2 && playerOneColumn >=0 && playerOneColumn <= 2){
		if(gameBoard[playerOneRow][playerOneColumn] == '*'){
			gameBoard[playerOneRow][playerOneColumn] = 'X';
		}
		else{
			checkInputError(playerOneRow, playerOneColumn);
			playerOne();
		}
	}
	else{
		checkInputError(playerOneRow, playerOneColumn);
		playerOne();
	}
}

/*
	Function that allows player 2 to take their turn in the game.
	Player 2 inputs both the row and column they wish to take their 
	turn on and adds an O
*/
void playerTwo(){

	int playerTwoRow;
	int playerTwoColumn;

	printf("Player Two's Turn\n");

	printf("Enter the row number: ");
	scanf("%d", &playerTwoRow);

	printf("Enter the column number: ");
	scanf("%d", &playerTwoColumn);

	playerTwoRow--;
	playerTwoColumn--;

	/*Checks if all user input is valid*/
	if(playerTwoRow >= 0 && playerTwoRow <= 2 && playerTwoColumn >=0 && playerTwoColumn <= 2){
		if(gameBoard[playerTwoRow][playerTwoColumn] == '*'){
			gameBoard[playerTwoRow][playerTwoColumn] = 'O';
		}
		else{
			checkInputError(playerTwoRow, playerTwoColumn);
			playerTwo();
		}
	}
	else{
		checkInputError(playerTwoRow, playerTwoColumn);
		playerTwo();
	}
}

/*
	Function checks after every turn if a player has won or if their is a tie
*/
void checkGameOver(){

	/* Checks if Player One Won */
	if(gameBoard[0][0] == 'X' && gameBoard[0][1] == 'X' && gameBoard[0][2] == 'X'){
		printf("\nGAME OVER\nPLAYER ONE WINS\n");
		exit(0);
	}
	else if(gameBoard[1][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[1][2] == 'X'){
		printf("\nGAME OVER\nPLAYER ONE WINS\n");
		exit(0);
	}
	else if(gameBoard[2][0] == 'X' && gameBoard[2][1] == 'X' && gameBoard[2][2] == 'X'){
		printf("\nGAME OVER\nPLAYER ONE WINS\n");
		exit(0);
	}
	else if(gameBoard[0][0] == 'X' && gameBoard[1][0] == 'X' && gameBoard[2][0] == 'X'){
		printf("\nGAME OVER\nPLAYER ONE WINS\n");
		exit(0);
	}
	else if(gameBoard[0][1] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][1] == 'X'){
		printf("\nGAME OVER\nPLAYER ONE WINS\n");
		exit(0);
	}
	else if(gameBoard[0][2] == 'X' && gameBoard[1][2] == 'X' && gameBoard[2][2] == 'X'){
		printf("\nGAME OVER\nPLAYER ONE WINS\n");
		exit(0);
	}
	else if(gameBoard[0][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][2] == 'X'){
		printf("\nGAME OVER\nPLAYER ONE WINS\n");
		exit(0);
	}
	else if(gameBoard[2][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[0][2] == 'X'){
		printf("\nGAME OVER\nPLAYER ONE WINS\n");
		exit(0);
	}

	/* Checks if Player Two Won */
	else if(gameBoard[0][0] == 'O' && gameBoard[0][1] == 'O' && gameBoard[0][2] == 'O'){
		printf("\nGAME OVER\nPLAYER TWO WINS\n");
		exit(0);
	}
	else if(gameBoard[1][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[1][2] == 'O'){
		printf("\nGAME OVER\nPLAYER TWO WINS\n");
		exit(0);
	}
	else if(gameBoard[2][0] == 'O' && gameBoard[2][1] == 'O' && gameBoard[2][2] == 'O'){
		printf("\nGAME OVER\nPLAYER TWO WINS\n");
		exit(0);
	}
	else if(gameBoard[0][0] == 'O' && gameBoard[1][0] == 'O' && gameBoard[2][0] == 'O'){
		printf("\nGAME OVER\nPLAYER TWO WINS\n");
		exit(0);
	}
	else if(gameBoard[0][1] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][1] == 'O'){
		printf("\nGAME OVER\nPLAYER TWO WINS\n");
		exit(0);
	}
	else if(gameBoard[0][2] == 'O' && gameBoard[1][2] == 'O' && gameBoard[2][2] == 'O'){
		printf("\nGAME OVER\nPLAYER TWO WINS\n");
		exit(0);
	}
	else if(gameBoard[0][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][2] == 'O'){
		printf("\nGAME OVER\nPLAYER TWO WINS\n");
		exit(0);
	}
	else if(gameBoard[2][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[0][2] == 'O'){
		printf("\nGAME OVER\nPLAYER TWO WINS\n");
		exit(0);
	}

	/*Checks for a tie*/
	else{
		bool tie = true;
		for(int i=0; i<3; ++i)
			for(int j=0; j<3; ++j)
				if(gameBoard[i][j] == '*')
					tie = false;
		if(tie){
			printf("\nGAME OVER\nTIE\n");
			exit(0);
		}
	}

}

/*
	Main function of the program. This is the begining point
	of the program. The main function uses a while loop that 
	that runs after the board is initialized. The loop allows 
	both users to take their respective turns and check if the 
	game is over after every player's turn is taken
*/
int main(){

	initializeBoard();
	printBoard();

	while(true){
		playerOne();
		printBoard();
		checkGameOver();
		playerTwo();
		printBoard();
		checkGameOver();
	}


	return 0;
}
