//top move

#include "stack.h"

Stack::Stack(int i){
	max = i;
	data = new char[max];
	top = -1;
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
	top = -1;
}

Stack& Stack::operator=(const Stack&rhs){
	data = new char[rhs.max];
	top = rhs.top;
	for(int i = 0; i < rhs.top + 1; i++){
		data[i] = rhs.data[i];
	}

}

bool Stack::push(char letter){
	if(full()){
		return false;		
	}else{
		top++;
		data[top] = letter;
		return true;
	}
}

bool Stack::pop(char& c){
	if(empty()){
		return false;
	}else{
		c = data[top];
		top--;
		return true;
	}

}

bool Stack::empty() const{
	if(top == -1){
		return true;
	}else{
		return false;
	}
}

bool Stack::full() const{
	if(top+1 == max){
		return true;
	}else{
		return false;
	}
}

bool Stack::clear(){
	top = -1;
	return true;
}

bool Stack::operator==(const Stack&rhs) const{
	if(data[0] != rhs.data[0]){
		return false;
	}else{
		for(int i = 0; i < top+1; i++){
			if(data[i] != rhs.data[i]){
				return false;
			}
		}
		return true;
	}
}

ostream& operator<<(ostream&out, const Stack&rhs){
	if(rhs.top == 0){
		out << "[(" << rhs.data[rhs.top] << ")]" << endl;
	}else{
		out << "[" << rhs.data[0] << "]" << " ";
		for(int i = 0; i < rhs.top; i++){
			out << rhs.data[i] << " ";
		}
		out << "(" << rhs.data[rhs.top] << ")" << endl;
	}
}