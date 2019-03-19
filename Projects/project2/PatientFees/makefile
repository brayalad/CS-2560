CC = g++
CFLAGS = -std=c++14 -g -Wall

PatientFees: main.o PatientAccount.o Pharmacy.o Surgery.o
	${CC} ${CFLAGS} PatientAccount.o Pharmacy.o Surgery.o main.o -o PatientFees

main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp

PatientAccount.o: PatientAccount.cpp
	${CC} ${CFLAGS} -c PatientAccount.cpp

Pharmacy.o: Pharmacy.cpp
	${CC} ${CFLAGS} -c Pharmacy.cpp

Surgery.o: Surgery.cpp
	${CC} ${CFLAGS} -c Surgery.cpp

clean:
	rm PatientAccount.o Pharmacy.o Surgery.o main.o PatientFees
