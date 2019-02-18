/*
GeometryCalculator.c
 
Write a program that displays the following menu:

Geometry Calculator
	1. Calculate the Area of a circle
	2. Calculate the Area of a Rectangle
	3. Calculate the Area of a Triangle
	4. Quit

	Enter your choice (1-4): 

If the user enters1, the program should ask for the radius of the circle then display its
area. Use the following formula:
	area = (pi)(r^2)
Use 3.14159 for pi and the radius of the circle for r. If the user enters 2, the program
should ask for the length and width of the rectangle, then display the rectangle's area.
Use the following formula:
	area = length * width
If the user enters 3, then the program should ask for the length of the triangle's base and its 
height, then display its area. Use the following formula:
	area = base * height * .5
If the user enters 4, the program should end.

Input Validation: Display an error message if the user enters a number outside the range 
of 1 through 4 when selecting an item from the menu. Do not accept negative values
for the circles radius, the rectangle's length or width, or the triangle's base or height. 

 
   Created on: Feb 16, 2019
       Author: bryanayala
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*constant variable to represent pi*/
static const double pi = 3.14159;

/*
	Function takes radius as parameter and calulates the area 
	of the circle. 
*/
void areaOfCircle(int radius){

	 printf("\nRadius: %d\nArea of Circle: %f\n\n",radius, (pi * (radius * radius)));

}

/*
	Function takes length and width as parameters and calulates the area 
	of the rectangle. 
*/
void areaOfRectangle(int length, int width){

	printf("\nLength: %d\nWidth: %d\nArea of Rectangle: %d\n\n", length, width, (length * width));

}

/*
	Function takes base and height as parameters and calulates the area 
	of the triangle. 
*/
void areaOfTriangle(int base, int height){

	printf("\nBase: %d\nHeight: %d\nArea of Triangle: %d\n\n", base, height, ((base * height) / 2));

}

/*
	Function displays menu to the console
*/
void printMenu(){

	printf("Geometry Calculator\n\n"
			"1. Calculate the Area of a Circle\n"
			"2. Calculate the Area of a Rectangle\n"
			"3. Calculate the Area of a Triangle\n"
			"4. Quit\n\n"
			"Enter your choice (1-4): ");

}

/*
	Function responsible for runing the program.
	Program runs on a while loop until user decides
	to end the program.
*/
void runProgram(){

	bool runProgram = true;

	int userInput;
	int radius;
	int length;
	int width;
	int base;
	int height;

	/*While loop that runs the program*/
	while(runProgram){

		printMenu();
		scanf("%d",&userInput);

		if(userInput == 1){ //Ask user for radius and calculates area of the circle

			printf("\nEnter radius: ");
			scanf("%d", &radius);

			if(radius > 0)
				areaOfCircle(radius);
			else
				printf("Radius can not be negative.\n"
					   "Please try again.\n\n");

		}
		else if(userInput == 2){ //Ask user for length and width and calculates area of the rectangle

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
		else if(userInput == 3){ //Ask user for base and height and calculates area of the triangle

			printf("\nEnter base: ");
			scanf("%d", &base);
			printf("\nEnter heigt: ");
			scanf("%d", &height);

			if(base >  0 && height > 0)
				areaOfTriangle(base, height);
			else
				printf("Base and height must both be positive.\n"
					   "Please try again\n\n");
		}
		else if(userInput == 4){ //Ends program
			printf("\nThank your for using this program\n");
			exit(0);
		}
		else{ //Error is detected. User is asked to input again.
			printf("\nInput not valid.\n"
				   "Please choose a valid menu option.\n\n");
		}
	}

}
/*
	Main funtion of the program. Program starts running
	from this method. This method calls on the runProgram 
	method in order to begin the program
*/
int main(){

 runProgram();

	return 0;
}


