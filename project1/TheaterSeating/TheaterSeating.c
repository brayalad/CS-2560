/*
	TheaterSeating.c
	
	Here is the assignment: Write a program that can be used by a small theater to sell
	tickets for perfromances. The theater's auditorium has 15 rows of seats, with 30 seats
	in each row. The program should display a screen that shows which seats are available
	and which are taken. For example, the following screen shows a chart depicting each 
	seat in the theater. Seats that are taken are represented by an * symbol, and seats that
	are available are represented by a # symbol.

						Seats
	        123456789012345678901234567890
	Row 1   ***###***###*########*****####
	Row 2   ####*************####*******##
	Row 3   **###**********########****###
	Row 4   **######***************##*****
	Row 5   ************####***######*****
	Row 6   ***###***###*########*****####
	Row 7   ####*************####*******##
	Row 8   **###**********########****###
	Row 9   **######***************##*****
	Row 10  ************####***######*****
	Row 11  ***###***###*########*****####
	Row 12  ####*************####*******##
	Row 13  **###**********########****###
	Row 14  **######***************##*****
	Row 15  ************####***######*****

	Here is a list of tasks ths program must perform:
		* When the program begins, it should ask the user to enter the seat prices for each
		  row. The prices can be stored in a separate array. (Alternatively, the prices may be 
		  read from a file).
		* Once the prices are entered, the program should display a seating chart similar to 
		  one should above. The user may enter the row and seat numbers for tickets being 
		  sold. Every time a ticket or group of tickets is purchased, the program should display
		  the total ticket prices and update the seating chart.
		* The program should keep a total of all ticket sales. The user should be given an 
		  option of viewing this ammount.
		* The program should also give the user an option to see a list of how many seats 
		  have been sold, how many seats are available in each row, and how many seats are 
		  available in the entire auditorium

	Input Validation: When tickets are being sold, do not accept row or seat numbers that 
	do not exist. When someone requests a particular seat, the program should make sure 
	that seat is available before it sold.

	Created on: Feb 17, 2019
		Author: bryanayala
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
	for(int rowIndex=0; rowIndex<amountOfRows; ++rowIndex){
		if(rowIndex>8)
			printf("Row %d   ", (rowIndex+1));
		else
			printf("Row %d    ", (rowIndex+1));
		for(int columnIndex=0; columnIndex<amountOfColumns; ++columnIndex)
			printf("%c ", theaterSeats[rowIndex][columnIndex]);
		printf("\n");
	}
}

void initailizeGrid(){
	for(int rowIndex=0; rowIndex<amountOfRows; ++rowIndex)
		for(int columnIndex=0; columnIndex<amountOfColumns; ++columnIndex)
			theaterSeats[rowIndex][columnIndex] = '*';
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

			for(int pointerIndex=0; pointerIndex<seatsSold;++pointerIndex)
				printf("Seat at Row %d and Column %d is sold.\n", (*(ssp + pointerIndex)).row, (*(ssp + pointerIndex)).column);

			free(ssp);
		}
	}
}

void calcualteAvailableRows(){

	int availableSeats = 0;
	printf("\nAvailable Seats by row\n");
	printf("----------------------\n");
	for(int rowIndex=0; rowIndex<amountOfRows; ++rowIndex){
		for(int columnIndex=0; columnIndex<amountOfColumns; ++columnIndex){
			if(theaterSeats[rowIndex][columnIndex] == '*')
				availableSeats++;
		}
		printf("Row %d: %d\n", (rowIndex+1), availableSeats);
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

				for(int pointerIndex=0; pointerIndex<(totalSeats - seatsSold);++pointerIndex)
					printf("Seat at Row %d and Column %d is available.\n", (*(asp + pointerIndex)).row, (*(asp + pointerIndex)).column);

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
