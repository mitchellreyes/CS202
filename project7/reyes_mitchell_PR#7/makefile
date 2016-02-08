all: project7

project7: test.cpp triangle.o
	g++ -o project7 test.cpp triangle.o

triangle.o: triangle.h triangle.cpp
	g++ -c triangle.cpp

clean:
	rm *.o project7