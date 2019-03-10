CC = g++
CFLAGS = -g -Wall

ParkingTicketSimulator: ParkingTicketSimulator.o ParkedCar.o ParkingMeter.o ParkingTicket.o PoliceOfficer.o
	${CC} ${CFLAGS} ParkingTicketSimulator.o ParkedCar.o ParkingMeter.o ParkingTicket.o PoliceOfficer.o -o ParkingTicketSimulator

ParkingTicketSimulator.o: ParkingTicketSimulator.cpp
	${CC} ${CFLAGS} -c ParkingTicketSimulator.cpp

ParkedCar.o: ParkedCar.cpp
	${CC} ${CFLAGS} -c ParkedCar.cpp
	
ParkingTicket.o: ParkingTicket.cpp
	${CC} ${CFLAGS} -c ParkingTicket.cpp

ParkingMeter.o: ParkingMeter.cpp
	${CC} ${CFLAGS} -c ParkingMeter.cpp


PoliceOfficer.o: PoliceOfficer.cpp
	${CC} ${CFLAGS} -c PoliceOfficer.cpp

clean:
	rm ParkingTicketSimulator.o ParkedCar.o ParkingMeter.o ParkingTicket.o PoliceOfficer.o ParkingTicketSimulator
