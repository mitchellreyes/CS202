all: main

project9: main.cpp stack1.o
	g++ -o project9 main.cpp stack1.o

stack1.o: stack.h stack1.cpp
	g++ -c stack1.cpp

clean:
	rm *.o project9