CC = g++
CFLAGS = -g -Wall

hwFive: hwFive.o Circle.o NumDays.o Employee.o ProductionWorker.o Time.o MilTime.o
	${CC} ${CFLAGS} hwFive.o Circle.o NumDays.o Employee.o ProductionWorker.o Time.o MilTime.o -o hwFive

hwFive.o: hwFive.cpp
	${CC} ${CFLAGS} -c hwFive.cpp

Circle.o: Circle.cpp
	${CC} ${CFLAGS} -c Circle.cpp

NumDays.o: NumDays.cpp
	${CC} ${CFLAGS} -c NumDays.cpp

Employee.o: Employee.cpp
	${CC} ${CFLAGS} -c Employee.cpp

ProductionWorker.o: ProductionWorker.cpp
	${CC} ${CFLAGS} -c ProductionWorker.cpp

Time.o: Time.cpp
	${CC} ${CFLAGS} -c Time.cpp

MilTime.o: MilTime.cpp
	${CC} ${CFLAGS} -c MilTime.cpp

clean:
	rm hwFive.o Circle.o NumDays.o Employee.o ProductionWorker.o Time.o MilTime.o hwFive
