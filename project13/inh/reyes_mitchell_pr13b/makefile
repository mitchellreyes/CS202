13b.out: main.o class.o
		g++ -o 13b.out main.o class.o

class.o:	class.cpp class.h
		g++ -c class.cpp

main.o: main.cpp class.cpp class.h
		g++ -c main.cpp

clean:
		rm *.o 13b.out