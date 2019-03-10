CC = g++
CFLAGS = -g -Wall

GameOf21: GameOf21.o Die.o Player.o
	${CC} ${CFLAGS} GameOf21.o Die.o Player.o -o GameOf21

GameOf21.o: GameOf21.cpp
	${CC} ${CFLAGS} -c GameOf21.cpp

Die.o: Die.cpp
	${CC} ${CFLAGS} -c Die.cpp

Player.o: Player.cpp
	${CC} ${CFLAGS} -c Player.cpp

clean: 
	rm GameOf21.o Die.o Player.o GameOf21