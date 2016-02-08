#include "stack.h"

Node::Node(char letter, Node*nPtr){
	data = letter;
	next = nPtr;
}

Stack::Stack(int i){
	max = i;
	top = NULL;
	actual = 0;
}

Stack::Stack(const Stack&input){
	top = NULL;
	*this = input;
}

Stack::~Stack(){
	if(top != NULL){
		clear();
	}
}

Stack& Stack::operator=(const Stack&rhs){
	if(this != &rhs){
		if(top != NULL){
			clear();
		}
		if(rhs.top == NULL){
			return *this;
		}
		max = rhs.max;
		actual = rhs.actual;
		Node*rhsTmp = rhs.top;
		top = new Node(rhs.top->data, NULL);
		Node*cpyTmp = top;
		while(rhsTmp->next != NULL){
			rhsTmp = rhsTmp->next;
			top = top->next = new Node(rhsTmp->data, NULL);
		}
		top = cpyTmp;
		rhsTmp = cpyTmp = NULL;
		return *this;
	}
}

bool Stack::push(char letter){
	if(full()){
		return false;
	}
	top = new Node(letter, top);
	actual += 1;
	return true;
}

bool Stack::pop(char&output){
	if(empty()){
		return false;
	}
	output = top->data;
	Node* tmp = top;
	top = top->next;
	actual -= 1;
	delete tmp;
	return true;
}

bool Stack::empty() const{
	if(top == NULL){
		return true;
	}else{
		return false;
	}
}

bool Stack::full() const{
	if(actual == max){
		return true;
	}else{
		return false;
	}
}

bool Stack::clear(){
	char a;
	while(pop(a));
	actual = 0;
	return true;
}

bool Stack::operator==(const Stack&rhs) const{
	if(top == NULL && rhs.top == NULL){
		return true;
	}
	if((top == NULL || rhs.top == NULL) 
		|| (actual != rhs.actual || max != rhs.max)) {
		return false;
	}
	if(top->data != rhs.top->data){
		return false;
	}else{
		Node* tmp = top;
		Node* rhsTmp = rhs.top;
		while(tmp->next != NULL && rhsTmp->next != NULL){
			if(tmp->data != rhsTmp->data){
				return false;
			}
			tmp = tmp->next;
			rhsTmp = rhsTmp->next;
		}
		if(tmp->data == rhsTmp->data 
			&& (tmp->next == NULL && rhsTmp->next == NULL)){
			delete tmp;
			delete rhsTmp;
			return true;
		}else{
			delete tmp;
			delete rhsTmp;
			return false;
		}
	}
}

ostream& operator<<(ostream&out, const Stack&outstack){
	if(outstack.empty()){
		return out;
	}
	if(outstack.top->next == NULL){
		out << "[TOP]" << outstack.top->data << "[END]" << endl;
		return out;
	}
	Node* tmp = outstack.top;
	out << "[TOP]" << tmp->data << endl;
	while(tmp->next != NULL){
		tmp = tmp->next;
		out << tmp->data << endl;
	}
	tmp = NULL;
	return out;
}

