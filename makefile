CFLAGS = -g -std=c++20 -Wall
CC = g++


sorting:	main person
	$(CC) $(CLAGS) main.o sort.o -o memory-tests

main:	main.cpp person.h
	$(CC) $(CFLAGS) -c main.cpp

person:	person.cpp person.h
	$(CC) $(CFLAGS) -c person.cpp


clean:
	rm memory-tests *.o