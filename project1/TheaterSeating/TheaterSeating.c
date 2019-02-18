/*
 * TheaterSeating.c
 *
 *  Created on: Feb 17, 2019
 *      Author: BRYAN
 */


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const static int amountOfRows = 15;
const static int amountOfColumns = 30;
const static int totalSeats = 450;

static char theaterSeats[15][30];
static double seatPrices[15];

static double ticketSales = 0;
static int seatsSold = 0;

typedef struct seat{
	int row, column;
}SEAT;

void readSeatPrices(){

	int index;
	int rowNumber;
	double seatPrice;


	FILE *fptr;
	fptr = fopen("SeatPrices.txt", "r");

	if(fptr == NULL){
		printf("File Not Found\n");
		exit(0);
	}

	index = fscanf(fptr, "%d %lf", &rowNumber, &seatPrice);
	while(index != EOF){

		seatPrices[rowNumber] = seatPrice;
		index = fscanf(fptr, "%d %lf", &rowNumber, &seatPrice);

	}

	fclose(fptr);

}

void printGrid(){
	printf("                                    Seats\n");
	printf("         0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3\n");
	printf("         1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0\n\n");
	for(int i=0; i<amountOfRows; ++i){
		if(i>8)
			printf("Row %d   ", (i+1));
		else
			printf("Row %d    ", (i+1));
		for(int j=0; j<amountOfRows; ++j)
			printf("%c ", theaterSeats[i][j]);
		printf("\n");
	}
}

void initailizeGrid(){
	for(int i=0; i<amountOfRows; ++i)
		for(int j=0; j<amountOfColumns; ++j)
			theaterSeats[i][j] = '*';
}

void calculateTicketsSold(){


	SEAT *ssp = NULL;

	printf("\n%d seat(s) have been sold.\n\n", seatsSold);

	if (seatsSold > 0){
		ssp = (SEAT *)malloc(seatsSold * sizeof(SEAT));

		if(ssp == 0){
			printf("\nERROR: System is out of memory.\n");
		}
		else{
			for(int rowIndex=0, pointerIndex=0; rowIndex<amountOfRows; ++rowIndex){
				for(int columnIndex=0; columnIndex<amountOfColumns; ++columnIndex){
					if(theaterSeats[rowIndex][columnIndex] == '#'){
						(*(ssp + pointerIndex)).row = (rowIndex + 1);
						(*(ssp + pointerIndex)).column = (columnIndex + 1);
						pointerIndex++;
					}
				}
			}

			for(int i=0; i<seatsSold;++i)
				printf("Seat at Row %d and Column %d is sold.\n", (*(ssp + i)).row, (*(ssp + i)).column);

			free(ssp);
		}
	}
}

void calcualteAvailableRows(){

	int availableSeats = 0;
	printf("\nAvailable Seats by row\n");
	printf("----------------------\n");
	for(int i=0; i<amountOfRows; ++i){
		for(int j=0; j<30; ++j){
			if(theaterSeats[i][j] == '*')
				availableSeats++;
		}
		printf("Row %d: %d\n", (i+1), availableSeats);
		availableSeats = 0;
	}

}

void calculateAvailableSeats(){

	if(seatsSold == 0){

		printf("\nAll %d seats are available.\n", totalSeats);

	}
	else{

		SEAT *asp = NULL;

		printf("\n%d seat(s) are available.\n\n", (totalSeats - seatsSold));

		if ((totalSeats - seatsSold) > 0){

			asp = (SEAT *)malloc((totalSeats - seatsSold) * sizeof(SEAT));

			if(asp == 0){
				printf("\nERROR: System is out of memory.\n");
			}
			else{
				for(int rowIndex=0, pointerIndex=0; rowIndex<amountOfRows; ++rowIndex){
					for(int columnIndex=0; columnIndex<amountOfColumns; ++columnIndex){
						if(theaterSeats[rowIndex][columnIndex] == '*'){
							(*(asp + pointerIndex)).row = (rowIndex + 1);
							(*(asp + pointerIndex)).column = (columnIndex + 1);
							pointerIndex++;
						}
					}
				}

				for(int i=0; i<(totalSeats - seatsSold);++i)
					printf("Seat at Row %d and Column %d is available.\n", (*(asp + i)).row, (*(asp + i)).column);

				free(asp);
			}
		}

	}

}

void chooseSeat(){

	int row;
	int column;

	printf("Enter the row number: ");
	scanf("%d", &row);

	printf("Enter the column number: ");
	scanf("%d", &column);

	row--;
	column--;

	if(row >= 0 && row < amountOfRows && column >= 0 && column < amountOfColumns){
		if(theaterSeats[row][column] == '*'){
			theaterSeats[row][column] = '#';
			printf("Price of seat chosen is $%.2lf\n", seatPrices[row]);
			ticketSales = ticketSales + seatPrices[row];
			seatsSold++;
		}
		else{
			printf("\nSeat chosen has already been sold.\n"
					"Please try again.\n\n");
			chooseSeat();
		}
	}
	else{
		printf("\nSeat chosen does not exist.\n"
				"Please try again.\n\n");
		chooseSeat();
	}
}

void runProgram(){

	int userInput;

	while(true){

		printf("\n1. Display current seating\n"
			   "2. Choose a seat\n"
			   "3. View ticket sales\n"
			   "4. See seats sold\n"
			   "5. See seats available by row\n"
			   "6. See amount of seats available\n"
			   "7. End Program\n");

		printf("\nEnter menu option: ");
		scanf("%d", &userInput);

		if(userInput == 1){
			printGrid();
		}
		else if(userInput == 2){
			chooseSeat();
		}
		else if(userInput == 3){
			printf("\nTotal ticket sales: $%.2lf\n", ticketSales);
		}
		else if(userInput == 4){
			calculateTicketsSold();
		}
		else if(userInput == 5){
			calcualteAvailableRows();
		}
		else if(userInput == 6){
			calculateAvailableSeats();
		}
		else if(userInput == 7){
			printf("\nThank you for using this program!\n");
			exit(0);
		}
		else{
			printf("\nInvalid Input.\nPlease try again.\n");
		}

	}

}

int main(){

	readSeatPrices();
	initailizeGrid();
	printGrid();
	runProgram();

	return 0;
}
