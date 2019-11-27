GXX=g++
FLAGS=-Wall -Wextra -Werror -lncurses -ltinfo -lpthread

space.o: space.cpp space.h
	$(GXX) space.cpp -c $(FLAGS)

board.o: board.cpp board.h space.o
	$(GXX) board.cpp space.o -c $(FLAGS)

cweep: cweep.cpp space.o board.o
	$(GXX) cweep.cpp -o cweep $(FLAGS)

boardtest: board.o
	$(GXX) boardtest.cpp board.o space.o -o boardtest $(FLAGS)

run: cweep
	./cweep

clean:
	rm -f *.o cweep
