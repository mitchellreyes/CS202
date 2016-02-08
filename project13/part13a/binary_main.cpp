#include <iostream>
#include "listA.h"
#include <fstream>
using namespace std;

void sort(List&first);
int search(List first,int key, int low, int high);

int main(){
	ifstream fin;
	fin.open("nums");
	if(fin.good()){
		int key = 8;
		List first;
		fin >> first;
        int high = first.getActual()+1;
        int low = 0;
		first.gotoBeginning();
		sort(first);
		cout << first << endl;
        first.gotoBeginning();
        int index = search(first, key, low, high);
		if(index == -1){
            cout << "No item to be found" << endl;
        }else{
            cout << "item is found at index: " << endl;
            cout << index << endl;
        }
	}else{
		cout << "No file exists" << endl;
		return 0;
	}
	fin.close();
	return 0;
}

void sort(List&first)
{
    bool solved = false;
    while(!solved)
    {
        int count = 0;
        first.gotoBeginning();
        while(count != first.getActual())
        {
        	int cursor = first.getCursor();
        	first.gotoNext();
            if(cursor > first.getCursor())
            {
                int valueRemoved;
                first.gotoPrior();
                first.remove(valueRemoved);
                first.insert(valueRemoved);
            }
            count++;
        }

        first.gotoBeginning();
        for(int i = 0; i < first.getActual();i++)
        {
        	int value = first.getCursor();
        	first.gotoNext();
            if(value < first.getCursor())
            {
                if (i == first.getActual()-1)
                {
                    solved = true;
                }

            }
            else{
            	solved = false;
            	break;
            }
        }
    }
}


int search(List first,int key, int low, int high){
    int pivot;
    if(low > high){
        int index = -1;
        return index;
    }
    else{
        pivot = (low + high) / 2;
        first.moveCursor(pivot);
        if(first.getCursor() == key){
            return pivot;
        }else if(key < first.getCursor()){
            int i = search(first, key, low, pivot-1); 
            return i;
        }else if(key > first.getCursor()){
            return search(first, key, pivot+1, high);
        }
    }
    return pivot;
}
