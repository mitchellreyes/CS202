class student{
public:
	//bool isEqual(const student &); <-- instead of this
	//bool operator == (const student &);
	friend bool operator==(const student &, const student &);//this function is a friend to my class, it has direct access to the variables
};

//for the friend function
student s1, s2;
if(s1 == s2) /**or**/ if(operator==(s1, s2));

bool operator==(const student&one, const student &two){
	if(one.age == two.age && one.gpa == two.gpa){
		return true;
	}else{
		return false;
	}
}
//////////////////////////
//how to overload the assignment operator
class student{
public:

};

friend class reel{
private:
};


class symbol{
	friend class reel{
		class reel
	};
};







int main(){
	student s1, s2;
	//if(s1 isEqual(s2)){
		//....
	//}

	if(s1 == s2){ //overloaded return type or (s1.operator == (s2))
		//when you use the == with 2 students now, it
		//pretty much calls the funtion defined by '==' under the student class
		//.....
	}


	/**bool student::isEqual(const student &){
		if(s.age==age && s.gpa == gpa){
			return true;
		}else{
			return false;
		}
	}**/

	bool student::operator==(const student &){
		if(s.age == age && s.gpa == gpa){
			return true;
		}else{
			return false;
		}
	}
}