#include "queue.h"
//queue stay
using namespace std;

Queue::Queue(int i){
	max = i;
	front = rear = -1;
	data = new int[max];
}

Queue::Queue(const Queue&rhs){
	data = new int[rhs.max];
	*this = rhs;
}

Queue::~Queue(){
	if(data != NULL){
		delete[]data;	
	}
	max = 0;
	front=rear=-1;
}

Queue& Queue::operator=(const Queue&rhs){
	if(rhs.max != max && data != NULL){
		delete[]data;
		data = new int[rhs.max];
	}

	for(int i = 0; i < rhs.rear + 1; i++){
		data[i] = rhs.data[i];
	}
	front = rhs.front;
	rear = rhs.rear;
}

bool Queue::enqueue(int newItem){
	if(full()){
		return false;
	}else{
		if(empty()){
			front++;
		}
		rear++;
		data[rear] = newItem;
		return true;
	}
}

bool Queue::dequeue(int& frontItem){
	if(empty()){
		return false;
	}else{
		frontItem = data[front];
		if(front == 0 && rear == 0){
			front--;
		}
		for(int i = 0; i < rear; i++){
			data[i] = data[i+1];
		}
		rear--;
		return true;
	}
}

bool Queue::empty() const{
	if(front == -1 && rear == -1){
		return true;
	}else{
		return false;
	}
}

bool Queue::full() const{
	if(front ==0 && rear == max-1){
		return true;
	}else{
		return false;
	}
}

bool Queue::clear(){
	front = rear = -1;
	return true;
}

bool Queue::operator==(const Queue&rhs) const{
	if(max == rhs.max && front == rhs.front && rear == rhs.rear){
		for(int i = 0; i < rear+1; i++){
			if(data[i] != rhs.data[i]){
				return false;
			}
		}
		return true;
	}else{
		return false;
	}
}

ostream& operator<<(ostream&out, const Queue&queueArray){
	if(queueArray.rear == 0){
		out << "([" << queueArray.data[queueArray.rear] << "])" << endl;
	}else{
		out << "["<< queueArray.data[0] << "]"<< " ";
		for(int i = 1; i < queueArray.rear+1; i++){
			out << queueArray.data[i] << " ";
		}
		out << "(" << queueArray.data[queueArray.rear] << ")" << endl;
	}
} 