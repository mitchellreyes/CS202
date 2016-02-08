#include "listA.h"

List::List(int i){
	size = i;
	data = new char[size];
	actual = cursor = -1;
}

List::List(const List&rhs){
	data = new char[rhs.size];
	*this = rhs;
}

List::~List(){
	size = 0;
	if(data != NULL){
		delete[]data;	
	}
	data = NULL;
	actual = cursor = -1;
}

bool List::gotoBeginning(){
	if(empty()){
		return false;
	}
	cursor = 0;
	return true;
}

bool List::gotoEnd(){
	if(empty()){
		return false;
	}
	cursor = actual;
	return true;
}

bool List::gotoNext(){
	if(empty() || full()){
		return false;
	}
	cursor = actual + 1;
	return true;
}

bool List::gotoPrior(){
	if(empty() || actual == 0){
		return false;
	}
	cursor = actual - 1;
	return true;
}

bool List::insert(char letter){
	if(full()){
		return false;
	}
	//will take care of empty and if their at the same place
	if(cursor == actual){
		cursor+=1;
		actual+=1;
		data[cursor] = letter;
		return true;
	}else{
		for(int i = actual+1; i > cursor+1; i--){
			data[i] = data[i-1];
		}
		cursor += 1;
		data[cursor] = letter;
		return true;
	}

}

//look through this
bool List::remove(char&outVal){
	//empty
	if(empty()){
		return false;
	}
	//1 data elementt
	if(actual == 0 && cursor == 0){
		outVal = data[actual];
		cursor = actual = -1;
		return true;
	}
	//end
	if(cursor+1 == size){
		outVal = data[cursor];
		cursor = 0;
		actual-=1;
		return true;
	}
	//middle
	outVal = data[cursor];
	for(int i = cursor; i < actual; i++){
		data[i] = data[i+1];
	}
	actual-=1;
	return true;
}

bool List::empty()const{
	if(actual == -1 && cursor == -1){
		return true;
	}else{
		return false;
	}
}

bool List::full()const{

	if(actual+1 == size){
		return true;
	}else{
		return false;
	}
}

bool List::clear(){
	cursor = actual = -1;
	return true;
}

//think this is the main problem
List& List::operator=(const List&origin){
	if(origin.actual == -1 && origin.cursor == -1){
		clear();
		return *this;
	}
	if(data != NULL){
		delete[]data;
	}
	data = new char[origin.size];
	if(origin.actual == 0){
		data[0] = origin.data[0];
		actual = origin.actual;
		cursor = origin.cursor;
		size = origin.size;	
	}else{
		actual = origin.actual;
		cursor = origin.cursor;
		for(int i = 0; i < actual+1;i++){
			data[i] = origin.data[i];
		}	
	}
	
}

ostream& operator<<(ostream&out, const List&input){
	if(input.actual == -1 && input.cursor == -1){
		out << "[empty]" << endl;
		return out;
	}
	if(input.actual == 0){
		out << "[start] " << input.data[input.actual] << " [end]" << endl;
	}else{
		
	out << "[start] " << input.data[0] << endl;
	for(int i = 0; i < input.actual; i++){
		out << input.data[i] << endl;
	}
	out << "[end] " << input.data[input.actual] << endl;	
	}
}