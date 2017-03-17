/*
  Author: Matthew Wong
  Course: {135,136}
  Instructor: Ilya
  Assignment: Lab 6
  Replacing digits
*/

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

/* 
  Task 1 Answer 
  When giving a non numerical input it will loop
  endlessly, until killing the process or pressing ctrl + c

*/

int main() {
int rectH, rectW;
        do {

            cout << "Insert input height then length for rectangle: (Must be a "
                    "positive integer)"
                 << endl;

            if(!(cin >> rectH >> rectW) || rectH > INT_MAX || rectW > INT_MAX){
              cout << "Invalid input\n";

              cin.clear();
              cin.ignore();
              break;
            }


        } while (rectH < 0 && rectW < 0);
 return 0;       
}
