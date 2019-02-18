/*
 * ReverseArray.c
 *
 * Write a function that accepts an int array and the array's size as arguments. The function
 * should create a copy of the array, except that the element values should be revered in the
 * copy. The function should return a pointer to the new array. Demonstrate the function in a
 * complete program.
 *
 *  Created on: Feb 17, 2019
 *      Author: BRYAN
 */

#include <stdio.h>
/*
	Function takes an array and its size as a paramter and displays it to the console
*/
void displayArray(int array[], int size){
	for(int i=0; i<size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

/*
	This method is responsible for reversing the order of the original array. 
	It takes the original array and its size as a parameter and copies it 
	to a new array in the reverse order. The function returns a pointer to 
	the newly created reversed array.
*/
int *reverseArray(int originalArray[], int size){

	int *nap = NULL;
	int newArray[size];
	nap = newArray;

	for(int i=0, j=(size-1); i<10; ++i, --j)
		newArray[i] = originalArray[j];




	return nap;
}
/*
	Main function of the program. Program begins here and data needed
	for the program is collected from the user here.
*/
int main(){

	int *nap;
	int ARRAY_SIZE;

	printf("This program takes tests scores as input and reverses the order.\n\n");

	do{
		printf("Enter amount of tests: ");
		scanf("%d", &ARRAY_SIZE);

		if(ARRAY_SIZE <= 0)
			printf("\nSize must be greater than 0.\nPlease try gain.x\n\n");

	}while(ARRAY_SIZE <= 0);

	int orignalArray[ARRAY_SIZE];

	printf("\nThere are %d tests.\n", ARRAY_SIZE); //User decides the size of the array

	/* User enters values to fill out the array*/
	for(int i=0; i<ARRAY_SIZE; ++i){
		printf("Enter value of test #%d: ", (i+1));
		scanf("%d", &orignalArray[i]);
	}


	printf("\nOriginal Test Order: \n");
	displayArray(orignalArray, ARRAY_SIZE);

	printf("\nReversed Test Order: \n");
	nap = reverseArray(orignalArray, ARRAY_SIZE);
	displayArray(nap, ARRAY_SIZE);


	return 0;
}
