/*
    employeeProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.

    Write a class named Employee that has the following member variables:
        *name - a string tha holds the employee's name
        *idNumber - an int variable that holds the employee's ID number
        *department - a string that holds the name of the department where the employee works
        *poistion - a string that holds the employee's job title
    
    The class should have the following constructors 
        *A constructor that accepts the following values as arguments and assigns them to 
        the appropriate member variables: employee's name, employee's ID number, deraprmentm
        and position.
        *A constructor that accepts the following values as arguments and assigns them to 
        the appropriate member variables: employee's name, employee's ID number. The department 
        and position fields should be assigned and empty string ("").
        *A default constructor that assings empty strings ("") to the name, department, and 
        position member variables, and 0 ti the idNumber member variable
    
    Write approprate mutator functions that store values in these member variables and 
    accesor functions that return the values in these member values. Once you have 
    written the class, write a sperate program that creates three Employee objects to hold 
    the following data:

    -----------------------------------------------------------------------------
    Name                ID Number           Department          Position       
    -----------------------------------------------------------------------------
    Susan Meyers        47899               Accounting          Vice President         
    Mark Jones          39119               IT                  Programmer
    Joy Rodgers         81744               Manufacturing       Engineer
    -----------------------------------------------------------------------------

    The program should store this date in three objects and then display the data for 
    each employee on the screen.

*/

#include "Employee.h" //Employee class definition header
#include <iostream> //Used to print to console
#include <iomanip> //Used to format what is printed to the console
#include <string> //String class used to whole strings


using namespace std; //Using the Standard name space


// Programs main function
int main() {

    //Three seperate Employee objects are being created, each with their own indivisual attribuites 
	Employee e1 = Employee("Susan Meyers", 47899, "Accounting", "Vice President");
	Employee e2 = Employee("Marke Jones", 39119, "IT", "Programmer");
	Employee e3 = Employee("Joy Rogers", 81774, "Manufacturing", "Engineer");


    //Information on the Employee objects are printed to the screen according to assignment specification
	cout << "---------------------------------------------------------------------------------------" << endl;
	cout << "Name" << setw(25) << "ID Number" << setw(25) << "Department" << setw(25) << "Position"  << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;
	cout << e1.getName() << setw(13) << e1.getIdNumber() << setw(29) << e1.getDepartment() << setw(31) << e1.getPosition() << endl;
	cout << e2.getName() << setw(14) << e2.getIdNumber() << setw(21) << e2.getDepartment() << setw(35) << e2.getPosition() << endl;
	cout << e3.getName() << setw(15) << e3.getIdNumber() << setw(32) << e3.getDepartment() << setw(22) << e3.getPosition() << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;


	return 0;
}