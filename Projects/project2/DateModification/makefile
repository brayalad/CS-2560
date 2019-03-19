CC = g++
CFLAGS = -g -Wall

DateModification: main.o Date.o
	${CC} ${CFLAGS} Date.o main.o -o DateModification

main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp

Date.o: Date.cpp
	${CC} ${CFLAGS} -c Date.cpp

clean:
	rm Date.o main.o DateModification
