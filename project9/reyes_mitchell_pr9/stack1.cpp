//stay
#include "stack.h"

Stack::Stack(int i){
	max = i;
	data = new char[max];
	top = actual = -1;
}

Stack::Stack(const Stack&plates){
	data = new char[plates.max];
	*this = plates;
}

Stack::~Stack(){
	max = 0;
	if(data != NULL){
		delete[]data;
	}
	top = actual = -1;
}

Stack& Stack::operator=(const Stack&rhs){
	data = new char[rhs.max];
	top = rhs.top;
	actual = rhs.actual;
	for(int i = 0; i < rhs.actual+1; i++){
		data[i] = rhs.data[i];
	}
}

bool Stack::push(char letter){
	if(full()){
		return false;
	}
	if(empty()){
		top++;
		actual++;
		data[top] = letter;
	}
	else{
		int rear = actual+1;
		data[rear] = data[actual];
		while(actual != top){
			data[actual] = data[actual-1];
			actual--;
		}
		data[actual] = data[top];
		data[top] = letter;
		actual = rear;
	}
}

bool Stack::pop(char& c){
	if(empty()){
		return false;
	}
	data[top] = c;
	if(top == actual){
		top = actual = -1;
	}else{
		while(top != actual){
			top++;
			data[top-1] = data[top];
		}
		data[top] = data[actual];
		actual = top;
		top = 0;
	}
}

bool Stack::empty() const{
	if(top == -1 && actual == -1){
		return true;
	}else{
		return false;
	}
}

bool Stack::full() const{
	if(actual+1 == max){
		return true;
	}else{
		return false;
	}
}

bool Stack::clear(){
	top = actual = -1;
	return true;
}

bool Stack::operator==(const Stack&rhs) const{
	if(data[top] != rhs.data[rhs.top]){
		return false;
	}else{
		for(int i = 0; i < actual+1; i++){
			if(data[i] != rhs.data[i]){
				return false;
			}
		}
		return true;
	}
}

ostream& operator<<(ostream&out, const Stack&rhs){
	if(rhs.top == rhs.actual){
		out << "([" << rhs.data[rhs.top] << "])" << endl;
	}else{
		out << "(" << rhs.data[rhs.top] << ")" << " ";
		for(int i = 1; i < rhs.actual; i++){
			out << rhs.data[i] << " ";
		}
		out << rhs.data[rhs.actual] << endl;
	}
}