/*
 * population.c
 *
 *  Created on: Feb 17, 2019
 *      Author: BRYAN
 */
#include <stdio.h>
#include <stdbool.h>




void calculatePopulationSize(int startingSize, double birthRate, double deathRate, int years){

	int populationSize;
	printf("\nInitial population size: %d\n", startingSize);

	for(int i=1; i<=years; ++i){

		populationSize = startingSize + (birthRate * startingSize) - (deathRate * startingSize);
		printf("Population size after %d year(s): %d\n", i, populationSize);
		startingSize = populationSize;

	}

	printf("\n\n");

}

int main(){

	int startingSize;
	double birthRate;
	double deathRate;
	int years;

	while(true){
		printf("Enter the starting size of the population: ");
		scanf("%d", &startingSize);

		printf("Enter the annual birth rate: ");
		scanf("%lf", &birthRate);

		printf("Enter the annual death rate: ");
		scanf("%lf", &deathRate);

		printf("Enter the amount of years to display: ");
		scanf("%d", &years);


		if(startingSize >= 2 && birthRate >= 0 && deathRate >= 0 && years >= 1){

			calculatePopulationSize(startingSize, (birthRate / 100), (deathRate / 100), years);

		}
		else{

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
