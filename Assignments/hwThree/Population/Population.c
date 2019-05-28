/*
	population.c
	
	In a population, the birth rate is the percentage incrase of the population due to births,
	and the death rate is the percentage decrease of the population due to deaths. Write a 
	program that displays the size of a population for any number of years. The program 
	should ask for the following data:

	* The starting size of a population
	* The annual birth rate
	* The annual death rate 
	* The number of years to display

	Write a function that calcualtes the size of the population for a year. The formula is

	N = P + BP - DP

	where N is the new population size, P is the previous population size, B is the birth rate,
	and D is the death rate.

	Created on: Feb 17, 2019
    	Author: bryanayala
 */
#include <stdio.h>
#include <stdbool.h>

/*
	This function calculates the new population year for every year that the user chooses.
	It takes in the starting size, birth rate, death rate, and ammount of years as parameters
	and uses the formula provided to calculate the new population size
*/
void calculatePopulationSize(int startingSize, double birthRate, double deathRate, int years){

	int populationSize; //declare new population size
	printf("\nInitial population size: %d\n", startingSize);

	for(int i=1; i<=years; ++i){

		populationSize = startingSize + (birthRate * startingSize) - (deathRate * startingSize); //Calcualte using the formula
		printf("Population size after %d year(s): %d\n", i, populationSize);
		startingSize = populationSize; //Set starting size to current size to calculate the next year population

	}

	printf("\n\n");

}
/*
	Main function of the program responsible for starting the loop that 
	will run the program until the user decides to terminate it
*/
int main(int argc, char *argv[]){

	int startingSize;
	double birthRate;
	double deathRate;
	int years;

	while(true){

		/*Asks user to input all information needed*/
		printf("Enter the starting size of the population: ");
		scanf("%d", &startingSize);

		printf("Enter the annual birth rate: ");
		scanf("%lf", &birthRate);

		printf("Enter the annual death rate: ");
		scanf("%lf", &deathRate);

		printf("Enter the amount of years to display: ");
		scanf("%d", &years);

		/*Checks if user inputed data is valid*/
		if(startingSize >= 2 && birthRate >= 0 && deathRate >= 0 && years >= 1){

			calculatePopulationSize(startingSize, (birthRate / 100), (deathRate / 100), years);

		}
		else{
			/*If not, the user is explained the error detected*/
			printf("\nInvalid input detected.\n");

			if(startingSize < 2)
				printf("The starting size of the population can not be less than 2.\n");
			if(birthRate < 0)
				printf("The birth rate can not be negative.\n");
			if(deathRate < 0)
				printf("The death rate can not be negative.\n");
			if(years < 1)
				printf("The number of years to display can not be less than 1.\n");

			printf("Please try again with valid inputs.\n\n");

		}
	}
	return 0;
}
