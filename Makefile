GXX=g++
FLAGS=-Wall -Wextra -Werror -lncurses -ltinfo -lpthread

space.o: space.cpp space.h
	$(GXX) space.cpp -c $(FLAGS)

board.o: board.cpp board.h space.o
	$(GXX) board.cpp -c $(FLAGS)

cweep: cweep.cpp space.o board.o
	$(GXX) cweep.cpp -o cweep $(FLAGS)

run: cweep
	./cweep

clean:
	rm -f *.o cweep
