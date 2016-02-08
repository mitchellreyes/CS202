all: project6

project6: main.cpp string.o class.o
	g++ -o project6 main.cpp string.o class.o

string.o: string.h string.cpp
	g++ -c string.cpp

class.o: class.h class.cpp
	g++ -c class.cpp

clean:
	rm *.o project6