all: project12

project12: string_main.cpp string.o
	g++ -o project12 string_main.cpp string.o

string.o: string.h string.cpp
	g++ -c string.cpp

clean:
	rm *.o project12