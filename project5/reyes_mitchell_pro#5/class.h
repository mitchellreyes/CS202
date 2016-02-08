#include <iostream>
using namespace std;

class symbol{
	public:
		symbol();
		~symbol();
		void setName(char* input, int length);
		void setBonus(int number);
		int getBonus();
		char* getName();
		void print();
	private:
		char *name;
		int bonus;
		bool TFBonus;
};