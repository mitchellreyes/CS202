all: 13a

13a: binary_main.cpp listarray.o
	g++ -o 13a binary_main.cpp listarray.o

listarray.o: listA.h listarray.cpp
	g++ -c listarray.cpp

clean:
	rm *.o 13a