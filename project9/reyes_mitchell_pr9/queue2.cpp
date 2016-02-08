//queue move
#include "queue.h"

//using namespace std;

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
	front = rhs.front;
	int frontBookmark = front;
	if(front == rhs.rear){
		data[front] = rhs.data[rhs.front];
	}
	while(frontBookmark != rhs.rear){
		frontBookmark++;
		if(frontBookmark == rhs.max){
			frontBookmark = 0;
		}
		data[frontBookmark] = rhs.data[frontBookmark];
	}
	rear = rhs.rear;
	data[rear] = rhs.data[rhs.rear];
}

bool Queue::enqueue(int newItem){
	if(full()){
		return false;
	}
	if(empty()){
		front++;
	}
	rear = (rear+1)%max;
	data[rear] = newItem;
}

bool Queue::dequeue(int& frontItem){
	if(empty()){
		return false;
	}
	frontItem = data[front];
	if(front == rear){
		front = rear = -1;
	}else{
		front = (front+1)%max;
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
	if((front == 0 && rear == max-1) || front -1 == rear){
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
	for(int i = front, j = rhs.front;;i = (i+1)%max, j=(j+1)%rhs.max){
		if(rhs.data[i] != data[j]){
			return false;
		}
		if((i == rear && j != rhs.rear)||(i != rear && j != rhs.rear)){
			return false;
		}else if(i == rear && j == rhs.rear){
			return true;
		}
	}
}

ostream& operator<<(ostream&out, const Queue&queueArray){
	int frontHold = queueArray.front;
	if(queueArray.front == queueArray.rear){
		out << "([" << queueArray.data[queueArray.rear] << "])" << endl;
	}else{
		out << "["<< queueArray.data[queueArray.front] << "]"<< " ";
		while(queueArray.front != queueArray.rear){
			frontHold++;
			if(frontHold == queueArray.max){
				frontHold = 0;
			}
			out << queueArray.data[frontHold] << " ";
		}
		out << "(" << queueArray.data[queueArray.rear] << ")" << endl;
	}
}