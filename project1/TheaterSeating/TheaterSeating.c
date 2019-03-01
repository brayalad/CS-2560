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

/*Constant integer to hold the amount of rows*/
const static int amountOfRows = 15;
/*Constant integer to hold the amount of columns*/
const static int amountOfColumns = 30;
/*Constant integer to hold the total amount of seats*/
const static int totalSeats = 450;

/*Two-Dimensional array to represent the auditorium and its seats*/
static char theaterSeats[15][30];
/*Array holding the prices of seats by row*/
static double seatPrices[15];

/*Variable that keeps count of amount of money in ticket sales*/
static double ticketSales = 0;
/*Variable that keeps count of the amount of tickets sold*/
static int seatsSold = 0;

/*Structure that represents a seat in the auditorium and stores the row and column it is in*/
typedef struct seat{
	int row, column;
}SEAT;

/*
	This method reads the ticket prices for each row from the text file called "SeatPrices.txt"
*/
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

/*
	Prints out the two-dimensional array representing the auditorium seating chart.
	It uses a nested for loop to print all the rows and seats.
	It also is updated as seats are sold.
*/
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

/*
	Initializes the two-dimensional array with the astrisk (*)
*/
void initailizeGrid(){
	for(int rowIndex=0; rowIndex<amountOfRows; ++rowIndex)
		for(int columnIndex=0; columnIndex<amountOfColumns; ++columnIndex)
			theaterSeats[rowIndex][columnIndex] = '*';
}

/*
	Determines what seats have already been sold and prints the information
	out to the user.
*/
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
				printf("Seat %d at Row %d is sold.\n", (*(ssp + pointerIndex)).column, (*(ssp + pointerIndex)).row);

			free(ssp);
		}
	}
}

/*
	Calculates the ammount of seats available by row and displays that information to the user
*/
void calcualteAvailableRows(){

	int availableSeats = 0;
	printf("\nAvailable Seats by row\n");
	printf("----------------------\n");
	for(int rowIndex=0; rowIndex<amountOfRows; ++rowIndex){
		for(int columnIndex=0; columnIndex<amountOfColumns; ++columnIndex){
			if(theaterSeats[rowIndex][columnIndex] == '*')
				availableSeats++;
		}
		if(rowIndex < 9){
			if(availableSeats < 10){
				printf("Row %d: %d\n", (rowIndex+1), availableSeats);
			}
			else{
				printf("Row %d:  %d\n", (rowIndex+1), availableSeats);
			}
		}
		else{
			if(availableSeats < 10){
					printf("Row %d:  %d\n", (rowIndex+1), availableSeats);
				}
				else{
					printf("Row %d: %d\n", (rowIndex+1), availableSeats);
				}
		}


		availableSeats = 0;
	}

}

/*
	Determines what seats available for purchase and prints the information
	out to the user.
*/
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
					printf("Seat %d at Row %d is available.\n", (*(asp + pointerIndex)).column, (*(asp + pointerIndex)).row);

				free(asp);
			}
		}

	}

}


/*
	Method ask user to choose a row and seat number. If the seat is 
	available, the user is shown the price of the ticket.
	The user then decides if they want to purchase the ticket or not. 
	If they do buy the ticket, the ticket is sold and the auditorium is updated.
*/
void chooseSeat(){

	int row;
	int column;

	printf("Enter the row number: ");
	scanf("%d", &row);

	printf("Enter the seat number: ");
	scanf("%d", &column);

	row--;
	column--;

	if(row >= 0 && row < amountOfRows && column >= 0 && column < amountOfColumns){
		if(theaterSeats[row][column] == '*'){

			int purchaseDecision;
			do {
				printf("\nPrice of seat chosen is $%.2lf\n", seatPrices[row]);
				printf("Would you like to purchase?\n"
						"1. Yes\n"
						"2. No\n"
						"Enter decision: ");
				scanf("%d", &purchaseDecision);

				if(purchaseDecision == 1){
					theaterSeats[row][column] = '#';
					ticketSales = ticketSales + seatPrices[row];
					seatsSold++;
					printf("You have purchased seat %d at row %d for $%.2lf\n\n", column, row, seatPrices[row]);
				}
				else if(purchaseDecision < 0 || purchaseDecision > 2){
					printf("\nInvalid Input.\nPlease try again\n");

				}
			} while(purchaseDecision < 0 || purchaseDecision > 2);

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

/*
	Method holds the while loop that runs the program.
*/
void runProgram(){

	int userInput;

	while(true){

		printf("\n1. Display current seating\n"
			   "2. Choose a seat\n"
			   "3. View ticket sales\n"
			   "4. See seats sold\n"
			   "5. See seats available by row\n"
			   "6. See seats available for purchase\n"
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

/*
	Main method of the program and start of the program.
	It calls methods repsonsible for reading seat prices, 
	initalizes the grid, and starts to run the program.
*/
int main(){

	readSeatPrices();
	initailizeGrid();
	printGrid();
	runProgram();

	return 0;
}
