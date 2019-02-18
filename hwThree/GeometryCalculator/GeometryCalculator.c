/*
 * GeometryCalculator.c
 *
 *  Created on: Feb 16, 2019
 *      Author: BRYAN
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


static double pi = 3.14159;


void areaOfCircle(int radius){

	 printf("\nRadius: %d\nArea of Circle: %f\n\n",radius, (pi * (radius * radius)));
	 
}

void areaOfRectangle(int length, int width){

	printf("\nLength: %d\nWidth: %d\nArea of Rectangle: %d\n\n", length, width, (length * width));

}

void areaOfTriangle(int base, int height){

	printf("\nBase: %d\nHeight: %d\nArea of Triangle: %d\n\n", base, height, ((base * height) / 2));
	
}

void printMenu(){

	printf("Geometry Calculator\n\n"
			"1. Calculate the Area of a Circle\n"
			"2. Calculate the Area of a Rectangle\n"
			"3. Calculate the Area of a Triangle\n"
			"4. Quit\n\n"
			"Enter your choice (1-4): ");

}

void runProgram(){

	bool runProgram = true;
	
	int userInput;
	int radius;
	int length;
	int width;
	int base;
	int height;


	while(runProgram){

		printMenu();
		scanf("%d",&userInput);

		if(userInput == 1){
			
			printf("\nEnter radius: ");
			scanf("%d", &radius);

			if(radius > 0)
				areaOfCircle(radius);
			else
				printf("Radius can not be negative.\n"
					   "Please try again.\n\n");

		}
		else if(userInput == 2){

			printf("\nEnter length: ");
			scanf("%d", &length);
			printf("\nEnter width: ");
			scanf("%d", &width);

			if(length > 0 && width > 0)
				areaOfRectangle(length, width);
			else
			printf("Length and width must both be positive.\n"
					"Please try again\n\n");
			
		}
		else if(userInput == 3){

			printf("\nEnter base: ");
			scanf("%d", &base);
			printf("\nEnter heigth: ");
			scanf("%d", &height);

			if(base >  0 && height > 0)
				areaOfTriangle(base, height);
			else 
				printf("Base and height must both be positive.\n"
					   "Please try again\n\n");
		}
		else if(userInput == 4){
			printf("\nThank your for using this program\n");
			exit(0);
		} 
		else{
			printf("\nInput not valid.\n"
				   "Please choose a valid menu option.\n\n");
		}
	}

}

int main(){

 runProgram();

	return 0;
}
