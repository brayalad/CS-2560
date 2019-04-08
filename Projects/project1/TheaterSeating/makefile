CC = gcc
CFLAGS = -Wall -g

TheaterSeating: TheaterSeating.o
	${CC} ${CFLAGS} TheaterSeating.o -o TheaterSeating

TheaterSeating.o: TheaterSeating.c
	${CC} ${CFLAGS} -c TheaterSeating.c

clean:
	rm TheaterSeating TheaterSeating.o