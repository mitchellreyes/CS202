//top move

#include <iostream>

using namespace std;
template<typename T>
class Stack {
        public:
                Stack(int = 10);
                Stack(const Stack<T>&);
                ~Stack();
                Stack& operator=(const Stack<T>&);
                bool push(T);
                bool pop(T&);
                bool empty() const;
                bool full() const;
                bool clear();
				bool operator==(const Stack<T>&) const;
				template<typename S>
                friend ostream& operator<<(ostream&, const Stack<S>&);
        private:
                int max;
                int top;
                int actual; //only used in stack (stay) implementation
                T* data;
};

template<typename T>
Stack<T>::Stack(int i){
	max = i;
	data = new T[max];
	top = -1;
}
template<typename T>
Stack<T>::Stack(const Stack<T>&plates){
	data = new T[plates.max];
	*this = plates;
}
template<typename T>
Stack<T>::~Stack(){
	max = 0;
	if(data != NULL){
		delete[]data;
	}
	top = -1;
}
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>&rhs){
	data = new T[rhs.max];
	top = rhs.top;
	for(int i = 0; i < rhs.top + 1; i++){
		data[i] = rhs.data[i];
	}

}
template<typename T>
bool Stack<T>::push(T letter){
	if(full()){
		return false;		
	}else{
		top++;
		data[top] = letter;
		return true;
	}
}
template<typename T>
bool Stack<T>::pop(T& c){
	if(empty()){
		return false;
	}else{
		c = data[top];
		top--;
		return true;
	}

}
template<typename T>
bool Stack<T>::empty() const{
	if(top == -1){
		return true;
	}else{
		return false;
	}
}
template<typename T>
bool Stack<T>::full() const{
	if(top+1 == max){
		return true;
	}else{
		return false;
	}
}
template<typename T>
bool Stack<T>::clear(){
	top = -1;
	return true;
}
template<typename T>
bool Stack<T>::operator==(const Stack<T>&rhs) const{
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
template<typename S>
ostream& operator<<(ostream&out, const Stack<S>&rhs){
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