//this is where you put the class functions
#include "class.h"
#include "string.h"

using namespace std;

symbol::symbol(){
	name = NULL;
	value = 0;
	bonus = false;
}

symbol::~symbol(){
	if(name != NULL){
		delete[]name;
	}
	name = NULL;
	value = 0;
	bonus = false;
}

symbol::symbol(const symbol &inputSymbol){
	int length = stringLength(inputSymbol.name);
	name = new char[length+1];
	stringCopy(name, inputSymbol.name);
	value = inputSymbol.value;
	bonus = inputSymbol.bonus;
}

void symbol::setName(char* string1){
	if(name != NULL){
		delete[]name;
	}
	int length = stringLength(string1);
	name = new char [length+1];
	stringCopy(name, string1);
}

void symbol::setBonus(int someValue){
	if(someValue == 0){
		bonus = false;
	}else{
		bonus = true;
	}
}

void symbol::setValue(int someNumber){
	value = someNumber;
}

char* symbol::getName(){
	return name;
}

int symbol::getValue(){
	return value;
}

bool symbol::getBonus(){
	return bonus;
}

void symbol::print(){
	cout << name << " " << value << " " << bonus << "  ";
}

reel::reel(){
	TenSlots = new symbol[10];
	payLine = 0;
}

reel::~reel(){
	delete[]TenSlots;
	TenSlots = NULL;
	payLine = 0;
}

void reel::setValues(symbol *someArray, int randValue, int j){
		TenSlots[j].setName(someArray[randValue].getName());
		TenSlots[j].setValue(someArray[randValue].getValue());
		TenSlots[j].setBonus(someArray[randValue].getBonus());
}

void reel::printReel(int i){
		TenSlots[i].print();
}

void reel::spin(int j){
	for(int i = 0; i < j; i++){
		for(int k = 1; k < 10; k++){
			//cout << "test" << endl;
			swap(TenSlots[0], TenSlots[k]);
		}
	}
}

void swap(symbol &s1, symbol &s2){
	symbol temp(s1);
	//cout << temp.getName() << endl;
	s1.setName(s2.getName());
	s1.setValue(s2.getValue());
	s1.setBonus(s2.getBonus());
	s2.setName(temp.getName());
	s2.setValue(temp.getValue());
	s2.setBonus(temp.getBonus());
} 
