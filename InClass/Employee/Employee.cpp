/*
    Employee.cpp
    File that defines Employee class functions
*/

#include "Employee.h" //Employee class definition header
#include <string> //String class used to whole strings

//Overloaded Constructor where the department and position are included
Employee::Employee(string name, int idNumber, string department, string position) {
	this->name = name;
	this->idNumber = idNumber;
	this->department = department;
	this->position = position;
}

//Overloaded constructor where the department and poistion are not included
Employee::Employee(string name, int idNumber) {
	this->name = name;
	this->idNumber = idNumber;
	department = "";
	position = "";
}

//Overloaded default constructor
Employee::Employee() {
	name = "";
	idNumber = 0;
	department = "";
	position = "";
}

//Modifier function that sets the Employee object's name
void Employee::setName(string name) {
	this->name = name;
}

//Modifier function that sets the Employee object's id Number
void Employee::setIdNumber(int idNumber) {
	this->idNumber = idNumber;
}

//Modifier function that sets the Employee object's department
void Employee::setDepartment(string department) {
	this->department = department;
}

//Modifier function that sets the Employee object's poistion
void Employee::setPosition(string position) {
	this->position = position;
}

//Accessor function that returns the Employee object's name
string Employee::getName() {
	return name;
}

//Accessor function that returns the Employee object's name
int Employee::getIdNumber() {
	return idNumber;
}

//Accessor function that returns the Employee object's name
string Employee::getDepartment() {
	return department;
}

//Accessor function that returns the Employee object's name
string Employee::getPosition() {
	return position;
}
