CC = g++
CFLAGS = -g -Wall

hwFour: ParkingTicketSimulator.o ParkedCar.o ParkingMeter.o ParkingTicket.o PoliceOfficer.o GameOf21.o Die.o Player.o hwFour.o
	${CC} ${CFLAGS} ParkingTicketSimulator.o ParkedCar.o ParkingMeter.o ParkingTicket.o PoliceOfficer.o GameOf21.o Die.o Player.o hwFour.o -o hwFour

hwFour.o: hwFour.cpp
	${CC} ${CFLAGS} -c hwFour.cpp

GameOf21.o: GameOf21.cpp
	${CC} ${CFLAGS} -c GameOf21.cpp

Die.o: Die.cpp
	${CC} ${CFLAGS} -c Die.cpp

Player.o: Player.cpp
	${CC} ${CFLAGS} -c Player.cpp

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
	rm ParkingTicketSimulator.o ParkedCar.o ParkingMeter.o ParkingTicket.o PoliceOfficer.o GameOf21.o Die.o Player.o hwFour.o hwFour