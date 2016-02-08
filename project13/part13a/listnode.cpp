#include "listN.h"

Node::Node(char a, Node* point){
	data = a;
	next = point = NULL; //should I put NULL here to initialize it to NULL?
}


List::List(int i){
	head = cursor = NULL;
}

List::List(const List&rhs){
	head = cursor = NULL;
	*this = rhs;
}

List::~List(){
	head = cursor = NULL;
}

bool List::gotoBeginning(){
	if(empty()){
		return false;
	}
	//move cursor to head
}

bool List::gotoEnd(){
	if(empty()){
		return false;
	}
	while(cursor->next != NULL){
		cursor = cursor->next;
	}
	return true;
	//until the "next" portion of the node = NULL
}

bool List::gotoNext(){
	if(empty()){
		return false;
	}
	if(cursor->next == NULL){
		return false;
	}else{
		cursor = cursor->next;
	}
	//point to the node after the cursor
		//if not at the end, move it to the next node.
}

bool List::gotoPrior(){
	if(empty()){
		return false;
	}
	if(head == cursor){
		return false;
	}
	Node* tmp = head;
	while(tmp->next != cursor){
		tmp = tmp->next;
	}
	cursor = tmp;
	tmp = NULL;
	return true;
	//if i move cursor to tmp, do I have to delete the next pointer of it?
	//point to the node before the cursor
		//if not at the beginning
}

bool List::insert(char letter){
	if(full()){
		return false;
	}
	if(empty()){
		head = cursor = new Node(letter, NULL);
		return true;
	}
	cursor = cursor->next = new Node(letter, cursor->next);
	return true;

	//insert after the cursor
		//move the cursor to a new element
}

bool List::remove(char&output){
	if(empty()){
		return false;
	}
	output = cursor->data;
	if(head == cursor){
		head = head->next;
		delete cursor;
		cursor = head;
		return true;
	}
	if(cursor->next == NULL){
		Node* tmp = cursor;
		gotoPrior();
		cursor->next = NULL;
		delete tmp;
		tmp = NULL;
		cursor = head;
		return true;
	}
	Node* temp = cursor;
	gotoPrior();
	cursor = cursor->next = temp->next;
	delete temp;
	temp = NULL;
	return true;

	//remove the value at the cursor, leave the cursor in place.
		//if last element, move cursor to the beginning of the list
			//return removed value
}

bool List::empty()const{
	if(head != NULL && cursor != NULL){
		return false;
	}else{
		return true;
	}
}

bool List::full()const{
	return false;
}

bool List::clear(){
	if(empty()){
		return false;
	}
	while(head->next != NULL){
		Node* tmp = head;
		head = tmp->next;
		delete tmp;
		tmp = NULL;
	}
	delete head;
	head = cursor = NULL;
}

List& List::operator=(const List&rhs){
	Node*rhsPtr = rhs.head;
	if(head != NULL && cursor != NULL){
		clear();
	}
	if(rhs.head == NULL && rhs.cursor == NULL){
		return *this;
	}
	head = new Node(rhsPtr->data, NULL);
	Node* nodePtr = head;
	//the while loop takes care if there is only 1 node
	while(rhsPtr->next != NULL){
		rhsPtr = rhsPtr->next;
		nodePtr = nodePtr->next = new Node(rhsPtr->data, NULL);
		if(rhsPtr == rhs.cursor){
			cursor = nodePtr;
		}
	}

}

//make sure this is right
ostream& operator<<(ostream&out, const List&stuff){
	if(stuff.head == NULL && stuff.cursor == NULL){
		out << "[empty]" << endl;
		return out;
	}
	if(stuff.head == stuff.cursor){
		out<< "[head][cursor] " << stuff.head->data << endl;
	}else{
		Node* tmpCrs = stuff.head;
		out << "[head] " << stuff.head->data << endl;
		while(tmpCrs->next != NULL){
			tmpCrs = tmpCrs->next;
			out << tmpCrs->data << endl;
		}
	}
}
