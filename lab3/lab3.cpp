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


void rect(int height, int width)
{
  for(int i = 1;i <= height; i++) // for loop for height 
  {
    for(int j = 1;j <= width; j++) // for loop for width
    {

      if(i == 1 || i == height || j==1 || j == width) // Give it a full line of stars if the rectangle/square is on the first and last line.

        cout << "*";

      else // Give spaces on the inside to make it hollow

        cout << " ";


      }

    cout << endl; 

  }
    
}

//correct
void lowerTriangle(int height)
{
  for(int i = 1;i <= height; i++)
  {

    for(int j = 1;j <= i; j++)

      cout << "*"; 
    
    cout << endl; 

  }
}

void trapezoid(int height, int width)
{
  for(int i = height;i >= 1; i--)
  {

    for(int j = i;j <= width; j++)

      cout << "*";

    cout << endl; 

  }

}

void higherTriangle(int height)
{
  for(int i = height;i > 0; i--)
  {

    for(int j = 0;j < height - i; j++)
      cout << " ";

    for(int k = 1;k<=i;k++)
      cout << "*";
    

    cout << endl; 

  }
}

void circle(int radius)
{
  // formula is x^2 + y^2 <= r^2
  int diax = radius * 2;
  int diay = radius * 2;
 for(int x = 0;x <= diax; x++) // for loop for height 
  {
    for(int y = 0;y <= diay; y++) // for loop for width
    {

      float centerx = radius/2;
      float centery = radius/2;
      cout << "*";      
      /*
      if((pow(radx,2) + pow(rady,2)) <= pow(radius,2))
      {
        cout << "*";
      }
      */
      
      
    }
    cout << endl; 

  }
}

int main()
{
  int choice;

  cout << "1. Rectangle" << endl;
  cout << "2. Lower Triangle" << endl;
  cout << "3. Trapezoid" << endl;
  cout << "4. Upper Triangle" << endl;
  cout << "5. Circle" << endl;
  cout << "Choose task you would like to start: " << endl;
  cin >> choice;

  switch(choice) {
    case 1:

      int rectH, rectW;
      cout << "Insert input height then length for rectangle: " << endl;
      cin >> rectH;
      cin >> rectW;
      rect(rectH,rectW);
      break;

    case 2:
      int lowerH;
      cout << "Insert input height for triangle: " << endl;
      cin >> lowerH;
      lowerTriangle(lowerH);
      break;

    case 3:
      int trapezoidH, trapezoidW;
      cout << "Insert input height then width for trapezoid: " << endl;
      cin >> trapezoidH >> trapezoidW;
      trapezoid(trapezoidH,trapezoidW);
      break;

    case 4:
      int higherH;
      cout << "Insert input height for triangle: " << endl;
      cin >> higherH;
      higherTriangle(higherH);
      break;
    
    case 5:
      int radius;
      cout << "Insert radius for circle" << endl;
      cin >> radius;
      circle(radius);
      break;
    default:
      cout << "You didn't choose anything" << endl;
  }

  return 0;
}
