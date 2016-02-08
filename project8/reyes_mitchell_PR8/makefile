all: project8

project8: main.cpp playerclass.o
	g++ -o project8 main.cpp playerclass.o

playerclass.o: playerclass.h playerclass.cpp
	g++ -c playerclass.cpp

clean:
	rm *.o project8