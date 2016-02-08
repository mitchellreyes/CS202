all: project5

project5: project5.cpp string.o class.o
	g++ -o project5 project5.cpp string.o class.o

string.o: string.h stringFunc.cpp
	g++ -c string.cpp

class.o: class.h class.cpp
	g++ -c class.cpp