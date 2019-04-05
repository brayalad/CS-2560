CC = g++
CFLAGS = -Wall -g

ExceptionProject: main.o Employee.o ProductionWorker.o
	${CC} ${CFLAGS} main.o Employee.o ProductionWorker.o -o ExceptionProject

main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp

Employee.o: Employee.cpp
	${CC} ${CFLAGS} -c Employee.cpp

ProductionWorker.o: ProductionWorker.cpp
	${CC} ${CFLAGS} -c ProductionWorker.cpp

clean:
	rm main.o Employee.o ProductionWorker.o ExceptionProject
