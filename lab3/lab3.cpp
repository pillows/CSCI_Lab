/*
  Author: Matthew Wong
  Course: {135,136}
  Instructor: Ilya
  Assignment: Lab 3

  Calculate Verhulst Formula
*/

#include <iostream>
using namespace std;

void rect(int, int);
void lowerTriangle(int);
void trapezoid(int, int);

//correct
void rect(int height, int width)
{
    for(int i = 1;i <= height; i++)
    {
        for(int j = 1;j <= width; j++)
        {
            
            if(i == 1 || i == height)
            
                cout << "*";
            
            else if(j==1 || j == width)
            
                cout << "*";
            
            else
            
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
        {
            cout << "*"; 
        }
        cout << endl; 
    }
}

void trapezoid(int height, int width)
{
    for(int i = height;i >= 1; i--)
    {
       
        for(int j = i;j <= width; j++){
            cout << "*";
            
        }
        
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
            {
                cout << "*";
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
       
        default:
        
            cout << "You didn't choose anything" << endl;
    }
    
    return 0;
}