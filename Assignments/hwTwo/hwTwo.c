/**
 * 
 * @file hwTwo.c
 * @author bryanayala
 * @date 5 Feb 2019
 * @brief HW 2 for CS 2560.
 * 
 *
 * CALIFORNIA STATE POLYTECHNIC UNIVERSITY
 *
 *  Department of Computer Science
 *
 *  CS 2560
 *  N.D.
 *  HWK2
 *
 *						C Programming Assignments
 *
 *  1)8th Chapter 2 Programming Challenge #4  Restaurant Bill Pg 80
 *    9th Chapter 2 Programming Challenge #4  Restaurant Bill Pg 81
 *
 *  2)8th Chapter 2 Programming Challenge #7  Ocean Levels Pg 80
 *    9th Chapter 2 Programming Challenge #7  Ocean Levels Pg 82
 *
 *  3)8th Chapter 3 Programming Challenge #23  Stock Trading Program Bill Pg 146
 *    9th Chapter 3 Programming Challenge #23  Stock Transaction Program Pg 148
 *
 *  4)8th Chapter 5 Programming Challenge #23  Pattern Displays Pg 298
 *    9th Chapter 5 Programming Challenge #23  Pattern Displays Pg 302
 *
 *
 *  Created on: Feb 5, 2019
 *      Author: bryanayala
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * 	@brief Program Assignment #1:
 * 
 *	Write a program that computes the tax and tip on a restaurant bill for a patron with
 *	a $88.67 meal charge. The tax should be 6.75 percent of the meal cost. The tip should
 *	be 20 percent of the total after adding the tax. Display the meal cost, tax amount, tip
 *	amount, and coral bill on the screen.
 */
void restaurantBill(){

	printf("\nRestaurant Bill\n-------------------------------------------------------------------------------------------------------------\n");

	double mealCost = 88.67; /**< Cost of the meal */
	double tax = mealCost * 0.0675; /**< The calculated tax */
	double tip = (mealCost + tax) * 0.2; /**< The talculated tip */
	double totalCost = mealCost + tax + tip; /**<  The calulated total cost of the meal */

	printf("Meal Cost is $%.2f \n", mealCost);
	printf("Tax is $%.2f \n", tax);
	printf("Tip is $%.2f \n", tip);
	printf("Total bill is $%.2f \n", totalCost);

	printf("-------------------------------------------------------------------------------------------------------------\n\n");

}

/**
 * 	@brief Program Assignment #2:
 *
 *	Assuming the ocean's level is currently rising at about 1.5 millimeters per year, write
 *	a program that displays:
 *
 *		• The number of millimeters higher than the current level that the ocean 's level will
 *		be in 5 years.
 *
 *		• The number of millimeters higher than the current level that the ocean's level will
 *		be in 7 year s.
 *
 *		• The number of millimeters higher than the current level that t he ocean's level will
 *		be in 10 years.
 */
void oceanLevels(){

	printf("\nOcean Levels\n-------------------------------------------------------------------------------------------------------------\n");

	double currentRisingRate = 1.5; //!< Rate of the rising tide

	printf("In 5 years, the ocean level will be %.2f millimeters higher than the current level.\n",(currentRisingRate * 5));
	printf("In 7 years, the ocean level will be %.2f millimeters higher than the current level.\n",(currentRisingRate * 7));
	printf("In 10 years, the ocean level will be %.2f millimeters higher than the current level.\n",(currentRisingRate * 10));

	printf("-------------------------------------------------------------------------------------------------------------\n\n");

}

/**	
 *	@brief Program Assignment #3
 *
 *	Last month Joe purchased some stock in Acme Software, Inc. He re are the details of
 *	the purchase:
 *		• The number of shares that Joe purchased was 1,000.
 *		• When Joe purchased t he stock, he paid $45.50 per share.
 *		• Joe paid his stock broker a commission that amounted to 2 percent of the amount
 *		  he paid for the stock.
 *
 *	Two weeks later, Joe sold the stock. Here are the derails of the sale:
 *		• The number of shares that Joe sold was 1,000.
 *		• He sold the stock for $56.90 per share.
 *		• He paid his stock broker another commission that amounted to 2 percent of the
 *		  amount he received for the stock.
 *
 *	Write a program that displays the following information:
 *		• The amount of money Joe paid for the stock.
 *		• The amount of commission Joe paid his broker when he bought the stock.
 *		• The amount that Joe sold the stock for.
 *		• T he amount of commission Joe paid his broker when be sold the stock.
 *		• Display the amount of profit that Joe made after selling his stock and paying the
 *		  two commissions to his broker. (If the amount of profit that your program displays
 *		  is a negative number, then Joe lost money on the transaction.)
 */
void stockTransaction(){

	printf("\nStock Transaction\n-------------------------------------------------------------------------------------------------------------\n");

	int amountOfShares = 1000; /**< The amount of shares */
	double purchasedStockPrice = 45.50; /**< The price the stock was purchased at */
	double soldStockPrice = 56.90; /**< The price the stock was sold at */
	double purchaseCommission = (amountOfShares * purchasedStockPrice) * 0.02; /**< The commision made from the purchase */
	double soldCommission = (amountOfShares * soldStockPrice) * 0.02; /**< The commision made from the sale */
	double totalProfit = (amountOfShares * soldStockPrice) - (amountOfShares * purchasedStockPrice) - purchaseCommission - soldCommission; /**< The total profit of the transation */

	printf("The amount of money Joe paid for the stock is $%.2f\n", amountOfShares * purchasedStockPrice);
	printf("The amount of commission Joe paid his broker when he bought the stock is $%.2f\n", purchaseCommission);
	printf("The amount of money Joe sold the stock for is $%.2f\n", amountOfShares * soldStockPrice);
	printf("The amount of commission Joe paid his broker when he sold the stock is $%.2f\n", soldCommission);
	printf("Total profit that Joe made after selling his stock and paying the two commissions to his broker is $%.2f\n", totalProfit);

	printf("-------------------------------------------------------------------------------------------------------------\n\n");

}

/**	
 * 	@brief Program Assignment #4
 *
 *	Write a program that uses a loop to display Pattern A bellow, followed by another loop
 *	that displays pattern B.
 */
void patternDisplays(){

	printf("\nPattern Displays\n-------------------------------------------------------------------------------------------------------------\n");

	printf("Pattern A:");
		for(int i=10; i>=0; --i){

			for(int j=i;j<10;++j)
				printf("+");

		printf("\n");

	}


	printf("\nPattern B: \n");
		for(int i=0; i<10; ++i){

			for(int j=i;j<10;++j)
				printf("+");

		printf("\n");

	}

	printf("-------------------------------------------------------------------------------------------------------------\n\n");

}

/**
 * @brief Program main method
 * 
 * The main method that begins the program. The program runs on a while loop
 * until the user decides to end the program by choosing the "End Program" option.
 * The user is given a menu of options and each option runs its respective programming
 * assignment that was assigned. User input is also validated. The program checks if
 * the input is an integer and if so then checks if it is a valid option.
 * @return ending execution code
 */
int main(){

	int booleanControl = -1; /**< variable used to keep the program while loop running */
	int userInput; /**< The users input into the console */
	char inputValidation; /**< variable where input is sent if it is not an integer */

	while(booleanControl == -1){

		printf("These are the available options:\n"
				" 1. Restaurant Bill\n"
				" 2. Ocean Level\n"
				" 3. Stock Transaction\n"
				" 4. Pattern Displays\n"
				" 5. End Program\n");
		printf("\nPlease choose an option to run: ");

		/**
		 * Checks to see if user input is of the int type
		 */
		if(scanf("%d",&userInput) == 1){ 


			if(userInput == 1)
				restaurantBill();

			else if(userInput == 2)
				oceanLevels();

			else if (userInput == 3)
				stockTransaction();

			else if (userInput == 4)
				patternDisplays();

			else if (userInput == 5){
				printf("\nThank you for using this program!\n");
				exit(0);
			}

			else
				printf("\n%d is not a valid input!\nPlease try again\n\n", userInput);

		}
		/**
		 * If input is not an integer, it is then disposed of
		 */ 
		else{ 
			while((inputValidation = getchar()) != '\n')
				putchar(inputValidation);

			printf(" is not valid. Input must be a number!\nPlease try again\n\n");
		}
	}

	return 0;

}
