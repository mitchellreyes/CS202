//this is where the classes are put in
#include <iostream>
using namespace std;


class symbol{
	public:
		symbol();
		symbol(const symbol& inputSymbol);
		~symbol();
		void setName(char* string1);
		void setBonus(int someValue);
		void setValue(int someNumber);
		char* getName();
		int getValue();
		bool getBonus();
		void print();
	private:
		char *name = NULL;
		int value;
		bool bonus;
};

class reel{
	public:
		reel();
		~reel();
		void setValues(symbol *someArray, int randValue, int j);
		void printReel(int j);
		void spin(int j);
	private:
		symbol *TenSlots = NULL;
		int payLine;
};

void swap(symbol &s1, symbol &s2);