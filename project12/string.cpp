#include "string.h"

String::String(int i){
	while(i<1){
		cout << "Cant use that value. Choose another: ";
		cin >> i;
	}
	bufferSize = i;
	buffer = new char[bufferSize];
	buffer[0] = '\0';
}
//need help with this
String::String(const char*input){
	int i = 0;
	//int j = 0;
	while(input[i] != '\0'){
		i++;
	}
	bufferSize = i + 1;
	buffer = new char[bufferSize];
	i = 0;
	while(input[i] != '\0'){
		buffer[i] = input[i];
		i++;
	}
	buffer[i] = '\0';
}

String::String(const String&rhs){
	buffer = NULL;
	bufferSize = 0;
	*this = rhs;
	//return *this;
}

String::~String(){
	if(!empty()){
		delete[]buffer;
	}
	buffer = NULL;
	bufferSize = 0;
}

int String::getLength()const{
	int i = 0;
	while(buffer[i] != '\0'){
		i++;
	}
	return i;
}

bool String::empty()const{
	 if(buffer[0] == '\0'){
	 	return true;
	 }else{
	 	return false;
	 }
}

bool String::clear(){
	buffer[0] = '\0';
	return true;
}

String& String::operator=(const String&original){
	if(this != &original)
		if(original.empty()){
			clear();
			return *this;
		}
		//if the string cant fit the string wanting to be copied
		else if(bufferSize < original.getLength()){
			int i = 0;
			if(buffer != NULL){
				delete[]buffer;
			}
			buffer = NULL;
			buffer = new char[original.bufferSize];
			while(original.buffer[i] != '\0'){
				buffer[i] = original.buffer[i];
				i++;
			}
			buffer[i] = '\0';
			//but if it can hold the string
		}else{
			clear();
			int i = 0;
			while(original.buffer[i] != '\0'){
				buffer[i] = original.buffer[i];
				i++;
			}
			buffer[i] = '\0';
		}
}

char String::operator[](int i)const{
	int threshold = getLength() + 1;
	if(i >= threshold || empty()){
		return '\0';
	}else{
		return buffer[i];
	}
}

bool operator+(String&first, const String&second){
	//the assignment operator already checks the buffersize
	if(first.empty()){
		first = second;
		cout << first.buffer << endl;
		return true;
	}
	//checking if the original buffersize is large enough to fit both 
	//strings already.
	if(first.bufferSize < (first.getLength() + second.getLength()) +1){
		String tmp = first;
		delete[]first.buffer;
		first.buffer = new char[tmp.bufferSize + second.bufferSize + 1];
		first = tmp;
		delete[]tmp.buffer;
	}
	int i = 0;
	int j = 0;
	//if the first string cant fit both strings
	while(first.buffer[i] != '\0'){
		i++;
	}
	//i++;
	while(second.buffer[j] != '\0'){
		first.buffer[i] = second.buffer[j];
		j++;
		i++;
	}
	first.buffer[i] = '\0';
	cout << first.buffer << endl;
	return true;
}
//need help with this
istream& operator>>(istream&in, String&input){
	char*tmp = new char[50];
	in >> tmp;
	int i = 0;
	while(tmp[i] != '\0'){
		i++;
	}
	input.bufferSize = i+1;
	input.buffer = new char[input.bufferSize];
	i = 0;
	while(tmp[i] != '\0'){
		input.buffer[i] = tmp[i];
		i++;
	}
	input.buffer[i] = '\0';
	delete[]tmp;
	tmp = NULL;
	return in;
}

ostream& operator<<(ostream&out, String&output){
	if(output.empty()){
		return out;
	}else{
		out << output.buffer;
		out << endl;
		return out;
	}

}