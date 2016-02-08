#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

struct studentData{
	char first[20];
	char last[20];
	int age;
	float gpa;
};

void readFromFile(ifstream &fin, studentData students[10]);
float calcAvg(studentData students[10]);
void highestGrade(studentData students[10]);

int main(){
	studentData students [10];
	ifstream fin ("students");
	if(fin.good()){
		readFromFile(fin, students);
		float x = calcAvg(students);
		highestGrade(students);
		cout << "Class average: " << x << endl;

		//cout << "its working" << endl;
	}else{
		cout << "Error: Unable to read file.";
	}
}

void readFromFile(ifstream &fin, studentData students[10]){
	for(int i = 0; i < 10; i ++){
		fin >> students[i].first;
		fin >> students[i].last;
		fin >> students[i].age;
		fin >> students[i].gpa;
		//cout << "is it working?" << endl;
	}
}

float calcAvg(studentData students[10]){
	float sum = 0.0;
	for(int i = 0; i < 10; i++){	
		sum += students[i].gpa; 
	}
	float avg = sum / 10;
return avg;
}

void highestGrade(studentData students[10]){
	float high = 0.0;
	float low = 10000.0;
	for(int i = 0; i < 10; i++){
		if(students[i].gpa > high){
			high = students[i].gpa;
		}
		if(students[i].gpa < low){
			low = students[i].gpa;
		}
	}

	for(int i = 0; i < 10; i++){
		if(students[i].gpa == low){
			cout << "Lowest Grade: ";
			cout << students[i].first << " ";
			cout << students[i].last << " ";
			cout << students[i]. age << " ";
			cout << low << endl;
		}
	}

	for(int i = 0; i < 10; i++){
		if(students[i].gpa == high){
			cout << "Highest Grade: ";
			cout << students[i].first << " ";
			cout << students[i].last << " ";
			cout << students[i]. age << " ";
			cout << high << endl;
		}
	}
}
