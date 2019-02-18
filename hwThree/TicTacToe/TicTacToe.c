/*
 * TicTacToe.c
 *
 *  Created on: Feb 16, 2019
 *      Author: BRYAN
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char gameBoard [3][3];


void initializeBoard(){

	for(int i=0; i<3; ++i)
		for(int j=0; j<3;++j)
			gameBoard[i][j] = '*';

}

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
