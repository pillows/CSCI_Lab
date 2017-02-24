/*
  Author: Matthew Wong
  Course: {135,136}
  Instructor: Ilya
  Assignment: Lab 3

  Shapes Shapes Shapes
*/

#include <iostream>
#include <cmath>

using namespace std;

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

void lowerTriangle(int height) {
  for (int i = 1; i <= height;
       i++) {  // Responsible for the height of the triangle
    for (int j = 1; j <= i; j++)
      cout << "*";  // This for loop is responsible for the width of each line

    cout << endl;
  }
}

void trapezoid(int height, int width) {
  for (int i = height; i >= 1;
       i--) {  // Responsible for the height of the trapezoid
    for (int j = i; j <= width; j++)
      cout << "*";  // This for loop is responsible for the width of each line

    cout << endl;
  }
}

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

int main() {
  int choice;
  /* Test case:
  User inserts an integer 1-5 depending on the shape that they want drawn.
  If user inserts a number that is not 1-5 then the script will default to the
  default case.
  At which it will display to the user: "You did not insert a valid integer"
  */
  cout << "1. Rectangle" << endl;
  cout << "2. Lower Triangle" << endl;
  cout << "3. Trapezoid" << endl;
  cout << "4. Upper Triangle" << endl;
  cout << "5. Circle" << endl;
  cout << "Choose task you would like to start: " << endl;
  cin >> choice;

  switch (choice) {
    case 1:
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
      int rectH, rectW;
      do {
        cout << "Insert input height then length for rectangle: (Must be a "
                "positive integer)"
             << endl;
        cin >> rectH;
        cin >> rectW;
      } while (rectH < 0 && rectW < 0);
      rect(rectH, rectW);

      break;
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
    case 2:
      int lowerH;
      do {
        cout << "Insert input height for triangle: (Must be a positive integer)"
             << endl;
        cin >> lowerH;
      } while (lowerH < 0);
      lowerTriangle(lowerH);

      break;
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
    case 3:
      int trapezoidH, trapezoidW;
      do {
        cout << "Insert input height then width for trapezoid: (Must be a "
                "positive integer and the width must be greater than the "
                "height)"
             << endl;
        cin >> trapezoidH >> trapezoidW;
      } while (trapezoidH < 0 && rectW < 0 && trapezoidH > trapezoidW);
      trapezoid(trapezoidH, trapezoidW);
      break;
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
    case 4:
      int higherH;
      do {
        cout << "Insert input height for triangle: " << endl;
        cin >> higherH;
      } while (higherH < 0);
      higherTriangle(higherH);
      break;
	  
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
    case 5:
      int radius;
      do {
        cout << "Insert radius for circle: (Must be a positive integer" << endl;
        cin >> radius;
      } while (radius < 0);
      circle(radius);
      break;
	  /*
	  Default case will only appear if user does not give an input with 1-5 as a choice.
	  Any non-integer will also default to this case.
	  */
    default:
      cout << "You did not insert a valid integer" << endl;
  }

  return 0;
}
