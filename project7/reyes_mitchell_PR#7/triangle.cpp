#include "triangle.h"
using namespace std;

triangle::triangle(int b, int h){
	base = b;
	height = h;
	area = .5*b*h;
} 

triangle::triangle(const triangle&t){
	*this = t;
}

triangle::~triangle(){
	base = 0;
	height = 0;
	area = 0;
}

triangle& triangle::operator=(const triangle&rhs){
	base = rhs.base;
	height = rhs.height;
	area = rhs.area;
}

bool triangle::operator==(const triangle&rhs)const{
	if(base == rhs.base && height == rhs.base && rhs.area){
		return true;
	}else{
		return false;
	}
}

triangle operator+(const triangle&lhs, const triangle&rhs){
	triangle result;
	result.base = lhs.base + rhs.base;
	result.height = lhs.height + rhs.height;
	result.area = .5*result.base*result.height;
	return result;
}

ostream& operator<<(ostream& out, triangle& rhs){
	out << rhs.base << " " << rhs.height << " " << rhs.area;
}

ifstream& operator>>(ifstream& in, triangle& rhs){
	in >> rhs.base;
	in >> rhs.height;
	rhs.area = .5*rhs.base*rhs.height;
}