CC = g++
CFLAGS = -g -Wall

StoreCustomer: main.o PersonData.o CustomerData.o PreferredCustomer.o
	${CC} ${CFLAGS} main.o PersonData.o CustomerData.o PreferredCustomer.o -o StoreCustomer

main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp

PersonData.o: PersonData.cpp
	${CC} ${CFLAGS} -c PersonData.cpp

CustomerData.o: CustomerData.cpp
	${CC} ${CFLAGS} -c CustomerData.cpp

PreferredCustomer.o:
	${CC} ${CFLAGS} -c PreferredCustomer.cpp

clean:
	rm main.o PersonData.o CustomerData.o PreferredCustomer.o StoreCustomer
