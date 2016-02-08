#ifndef __LIST_H_
#define __LIST_H_
#include <iostream>

using namespace std;

class List{
        public:
            List(int = 10);
            List(const List&);
            ~List();
            int getCursor();
            int getActual();
            bool moveCursor(int);
            bool gotoBeginning();
            bool gotoEnd();
            bool gotoNext();
            bool gotoPrior();
  	        bool insert(int);
            bool insertBefore(int);
            bool remove(int&);
            bool empty() const;
            bool full() const;
            bool clear();
  	        List& operator=(const List&);
            friend ostream& operator<<(ostream&, const List&);
            friend istream& operator>>(istream&, List&);
          private:
            int size;
		    int actual;
            int cursor;
            int *data;
};

#endif