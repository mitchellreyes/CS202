#include "class.h"
#include "string.h"

symbol::symbol(){
	name = NULL;
	bonus = 0;
	TFBonus = false;
}

symbol::~symbol(){
	if(name != NULL){
		delete[]name;
	}
	name = NULL;
	bonus = 0;
	TFBonus = false;
}

void symbol::setName(char* input, int length){
	name = new char[length+1];
	stringCopy(name, input);
}

void symbol::setBonus(int number){
	bonus = number;
	if(number == 0){
		TFBonus = false;
	}else{
		TFBonus = true;
	}
}

int symbol::getBonus(){
	return bonus;
}

char* symbol::getName(){
	return name;
}

void symbol::print(){
	cout << name << " " << "(" <<
	bonus << ")" << " " << "(" <<
	TFBonus << ")" << endl;
}