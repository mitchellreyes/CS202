all: test

test: test.cpp listarray.o
	g++ -o test test.cpp listarray.o

listarray.o: listA.h listarray.cpp
	g++ -c listarray.cpp

clean:
	rm *.o test