//Header file for the Employee class that is a blueprint for an employee object

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string> //Standard C++ library for strings

using namespace std; //Using the Standard name space

//Employee class
class Employee {

//Modifier that makes the class' variables private
private:

	string name;
	int idNumber;
	string department;
	string position;

//Modifier that makes the class' constructor and functions public 
public:

	Employee(string name, int idNumber, string department, string position);
	Employee(string name, int idNumber);
	Employee();

	void setName(string name);
	void setIdNumber(int idNumber);
	void setDepartment(string department);
	void setPosition(string position);

	string getName();
	int getIdNumber();
	string getDepartment();
	string getPosition();

};

#endif