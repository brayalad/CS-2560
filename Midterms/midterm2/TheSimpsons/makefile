CC = g++
CFLAGS = -Wall -g

TheSimpsons: simpsons.o Human.o Child.o Parent.o
	${CC} ${CFLAGS} simpsons.o Human.o Child.o Parent.o -o TheSimpsons

simpsons.o: simpsons.cpp
	${CC} ${CFLAGS} -c simpsons.cpp

Human.o: Human.cpp
	${CC} ${CFLAGS} -c Human.cpp

Child.o: Child.cpp
	${CC} ${CFLAGS} -c Child.cpp

Parent.o: Parent.cpp
	${CC} ${CFLAGS} -c Parent.cpp

clean:
	rm simpsons.o Human.o Child.o Parent.o TheSimpsons
