#Make file for compiling the Employee project for CS 2560
#Author: Bryan Ayala

CC = g++
CFLAGS = -g -Wall

#Link object files into runnable executable
employeeProgram: employeeProgram.o Employee.o
	${CC} ${CFLAGS} employeeProgram.o Employee.o -o employeeProgram

#Compiles hwFour source file into it's object file
employeeProgram.o: employeeProgram.cpp
	${CC} ${CFLAGS} -c employeeProgram.cpp

#Compiles Employee class source file into it's object file
Employee.o: Employee.cpp
	${CC} ${CFLAGS} -c Employee.cpp

#Cleans the compilated files when run
clean: 
	rm employeeProgram.o Employee.o employeeProgram