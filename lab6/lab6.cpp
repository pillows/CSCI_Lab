/*
  Author: Matthew Wong
  Course: CSCI 136
  Instructor: Ilya Korsunsky
  Assignment: Lab 6

  Extending lab 3 with input checking
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

/*

  Test case for rectangle
  User will insert any two positive integers to make a rectangle.
  Case will only loop if the user inputs a 0 or negative integer.
  The script will then reask the user for new integers.
  The do while loop does not account for non-integers. It will give an
  infinite loop.
  An example for the rectangle when given 3 as height and 4 as width of
  choice will display:
  ****
  *  *
  ****

*/

void rect(int height, int width) {
  for (int i = 1; i <= height; i++)  // for loop for height
  {
    for (int j = 1; j <= width; j++)  // for loop for width
    {
      if (i == 1 || i == height || j == 1 ||
          j == width)  // Give it a full line of stars if the rectangle/square
                       // is on the first and last line.

        cout << "*";

      else  // Give spaces on the inside to make it hollow

        cout << " ";
    }

    cout << endl;
  }
}

/*
Test case for triangle
User will insert any positive integer to make a triangle.
The do while loop does not account for non-integers. It will give an
infinite loop instead.
Case will only loop if the user inputs a 0 or negative integer.
The script will then reask the user for new integers.
An example for 5 as an integer of choice will display:
*
**
***
****
*****
*/

void lowerTriangle(int height) {
  for (int i = 1; i <= height;i++) {  // Responsible for the height of the triangle
    for (int j = 1; j <= i; j++)
      cout << "*";  // This for loop is responsible for the width of each line

    cout << endl;
  }
}

/*

  Test case for trapezoid
  User will insert any two positive integers to make a
  trapezoid
  Case will only loop if the user inputs a 0, negative
  integer, or when the height is greater than the width.
  The do while loop does not account for non-integers. It will
  give an infinite loop instead.
  If there was not a check for that then the script would
  display a triangle instead.
  The script will then reask the user for new integers.
  An example for the trapezoid when given 3 for height and 5
  for width of choice will display:
  ***
  ****
  *****

*/

void trapezoid(int height, int width) {
  for (int i = height; i >= 1;
       i--) {  // Responsible for the height of the trapezoid
    for (int j = i; j <= width; j++)
      cout << "*";  // This for loop is responsible for the width of each line

    cout << endl;
  }
}

/*
  Test case for higher triangle
  User will insert any positive integer to make a triangle.
  Case will only loop if the user inputs a 0 or negative
  integer.
  The do while loop does not account for non-integers. It will
  give an infinite loop instead.
  An example for 4 as an integer of choice will display:
  ****
   ***
    **
     *
*/

void higherTriangle(int height) {
  for (int i = height; i > 0;
       i--) {  // This for loop is responsible for the height of each line
    for (int j = 0; j < height - i; j++)
      cout << " ";  // This for loop is responsible padding of space(s) on each
                    // line

    for (int k = 1; k <= i; k++)
      cout << "*";  // This for loop is responsible for adding the leftover
                    // asterisks

    cout << endl;
  }
}

/*
  Test case for circle
  User will insert any positive integer to make a circle.
  Case will only loop if the user inputs a 0 or negative integer.
  The do while loop does not account for non-integers. It will give an
  infinite loop instead.
  An example for 5 as an integer of choice will display:
                  *
         *  *  *  *  *  *  *
      *  *  *  *  *  *  *  *  *
      *  *  *  *  *  *  *  *  *
      *  *  *  *  *  *  *  *  *
   *  *  *  *  *  *  *  *  *  *  *
      *  *  *  *  *  *  *  *  *
      *  *  *  *  *  *  *  *  *
      *  *  *  *  *  *  *  *  *
         *  *  *  *  *  *  *
                  *
  There is also non-spaced version of a circle commented in the
  circle() function.
*/

void circle(int radius) {
  int diameter = radius * 2;
  for (int x = 0; x <= diameter; x++)  // for loop for height
  {
    for (int y = 0; y <= diameter; y++)  // for loop for width
    {
      float originx, originy;  // To give a point and where the center of the
                               // circle will be
      originx = originy = radius;

      /*
       The uncommented version looks more like a wide oval compared to a narrow
       oval.
       It appears to look more circular, in my opinion.
       I didn't use the formula in class, but rather the distance formula to
       calculate the stars in the circle
      */

      if (sqrt(pow((x - originx), 2) + pow((y - originy), 2)) <=
          radius)  // Distance formula
        cout << " * ";
      else
        cout << "   ";

      /*
            cout << "Non-spaced version" << endl;
            if(sqrt(pow((x - originx),2) + pow((y - originy),2)) <= radius)
            cout << "*";
            else
            cout << " ";
      */
    }
    cout << endl;
  }
}

/* Test case:
User inserts a letter (R, L, T, T, C, E) depending on the shape that they want
drawn.
If user inserts a number that is not any of the letters then the script will
default
to the default case and display "You did not enter a valid choice".

It will keep looping and making shapes until the user inputs E as a choice.
*/

int menu() {
  char choice;
  bool loop = true;
  while (loop) {
    cout << "Enter (R)ectangle, (L)ower Triangle, (H)igher Triangle, "
            "(T)rapezoid, (C)ircle, (E)nd: ";
    cin >> choice;
    cout << choice << "\n";

    switch (choice) {
      case 'r':
      case 'R':  // Upper or lowercase will work
        int rectH, rectW;
        do {
          cout << "Insert input height then length for rectangle: (Must be a "
                  "positive integer)"
               << endl;

          if (!(cin >> rectH >> rectW) || rectH > INT_MAX ||
              rectW >
                  INT_MAX) {  // Check for failed input. Then check for max ints
            cout << "Invalid input\n";

            cin.clear();   // To clear the cin input
            cin.ignore();  // Ignore the rest of input
            break;
          }

        } while (
            rectH < 0 ||
            rectW <
                0);  // Height and width must not be negative. If so loop again.
        rect(rectH, rectW);
        break;

      case 'l':
      case 'L':
        int lowerH;
        do {
          cout << "Insert input height for triangle: (Must be a positive "
                  "integer)"
               << endl;
          if (!(cin >>
                lowerH)) {  // Display invalid input if non-integer is inputed.
            cout << "Invalid input\n";

            cin.clear();   // To clear the cin input
            cin.ignore();  // Ignore the rest of input
            break;
          }
        } while (lowerH < 0);  // Height must not be negative. If so loop again.
        lowerTriangle(lowerH);
        break;

      case 't':
      case 'T':
        int trapezoidH, trapezoidW;
        do {
          cout << "Insert input height then width for trapezoid: (Must be a "
                  "positive integer and the width must be greater than the "
                  "height)"
               << endl;

          if (!(cin >> trapezoidH >> trapezoidW)) {  // Display invalid input if
                                                     // non-integer is inputed.
            cout << "Invalid input\n";

            cin.clear();   // To clear the cin input
            cin.ignore();  // Ignore the rest of input
            break;
          }
        } while (trapezoidH < 0 || rectW < 0 ||
                 trapezoidH > trapezoidW);  // Checking for negative values and
                                            // making sure height is greater
                                            // than width.
                                            // Loop if there are negative values
        trapezoid(trapezoidH, trapezoidW);
        break;

      case 'h':
      case 'H':
        int higherH;
        do {
          cout << "Insert input height for triangle: " << endl;
          if (!(cin >> higherH)) {  // Display invalid input if non-integer is
                                    // inserted.
            cout << "Invalid input\n";

            cin.clear();   // To clear the cin input
            cin.ignore();  // Ignore the rest of input
            break;
          }
        } while (higherH < 0);  // Height must not be negative
        higherTriangle(higherH);
        break;

      case 'c':
      case 'C':
        int radius;
        do {
          cout << "Insert radius for circle: (Must be a positive integer"
               << endl;
          if (!(cin >> radius)) {
            cout << "Invalid input\n";

            cin.clear();   // To clear the cin input
            cin.ignore();  // Ignore the rest of input
            break;
          }
        } while (radius < 0);  // Radius must not be negative
        circle(radius);
        break;

      case 'e':
      case 'E':
        cout << "Program terminated\n";  // Ends the loop
        loop = false;
        break;

      default:
        cout << "You did not enter a valid choice \n";  // If none of the
                                                        // letters are chosen
        break;
    }
  }
}

int main() {
  menu();
  return 0;
}