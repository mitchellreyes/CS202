#include <iostream>
#include <fstream>

using namespace std;

struct studentData{
	char first[20];
	char last[20];
	int age;
	float gpa;
};

void readFromFile(ifstream &fin, studentData *s);
float calcAvg(studentData *s);
void highestGrade(studentData *s);

int main(){
	studentData students[10];
	studentData* s = students;
	ifstream fin ("students");
	if(fin.good()){
		readFromFile(fin, students);
		float x = calcAvg(students);
		highestGrade(students);
		cout << "Class average: " << x << endl;
	}else{
		cout << "Error: Unable to read file.";
	}
}

void readFromFile(ifstream &fin, studentData *s){
		int i = 0;
		while(i < 10){
			fin >> (*s).first;
			fin >> (*s).last;
			fin >> (*s).age;
			fin >> (*s).gpa;
			s++;
			i++;
		}
}

float calcAvg(studentData *s){
	float sum = 0.0;
	int i = 0;
	while(i < 10){	
		sum += (*s).gpa;
		s++;
		i++; 
	}
	float avg = sum / 10;
return avg;
}

void highestGrade(studentData* s){
	float high = 0.0;
	float low = 10000.0;
	int i = 0;
	studentData* temp = s;
	while(i < 10){
		if((*s).gpa > high){
			high = (*s).gpa;
		}
		if((*s).gpa < low){
			low = (*s).gpa;
		}
	s++;
	i++;
	}
	i = 0;
	s = temp;
		
	while(i < 10){
		if((*s).gpa == low){
			cout << "Lowest Grade: ";
			cout << (*s).first << " ";
			cout << (*s).last << " ";
			cout << (*s). age << " ";
			cout << low << endl;
		}
		if((*s).gpa == high){
			cout << "Highest Grade: ";
			cout << (*s).first << " ";
			cout << (*s).last << " ";
			cout << (*s). age << " ";
			cout << high << endl;
		}
	s++;
	i++;
	}
	s = temp;
}
