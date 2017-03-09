/*
  Author: Matthew Wong
  Course: {135,136}
  Instructor: Ilya
  Assignment: Lab 5

  Replacing digits
*/

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int replaceDig(int, int, int);
int getDigit(int, int);
int numDigits(int);

int replaceDig(int num, int oldDigit, int newDigit)
{
  int padding = 10;
  int nextpad, leftover;
  
  int numberOfDigits = numDigits(num);
  int currentDigit;
  
  int result;
  
  cout << "Old digit: " << oldDigit << endl;
  cout << "New digit: " << newDigit << endl;
  for(int i=0; i < numberOfDigits; i++)
  {
    nextpad = pow(padding, numberOfDigits - (i + 1));
    currentDigit = getDigit(num,i);
    cout << "index: " << i << " " << "currentDigit: " << currentDigit << endl;
    
    if(oldDigit == currentDigit)
    {
      result += newDigit * nextpad;
      cout << "Result replace: " << result;
    }
    else 
      result += currentDigit * nextpad;
      cout << "Current result: " << result << endl;
  }
  return result;
}

int getDigit(int num, int index) // return the index'th digit of num   97534 (4 indicies, to get index 2, )
{
  //cout << "getDigit function" << endl;
  int padding = 10;
  int nextpad, leftover;
  int indexStop = numDigits(num) - index;
  //cout << "indexStop: " << indexStop << endl;
  int numberOfDigits = numDigits(num);
  
  for(int i=numberOfDigits; i > 0; i--)
  {
    nextpad = pow(padding, i - 1);
    //cout << "nextpad value: " << nextpad << endl;
    leftover = num/nextpad;
    //cout << "Leftover: " << leftover << endl;
    
    if(i == indexStop)
    {
      return leftover % 10;
    }
  }
  //cout << "end getDigit function" << endl; 
}

int numDigits(int num) // return the number of digits in num
{
  int padding = 10;
  int nextpad, leftover;
  for(int i=1; i < INT_MAX; i++)
  {
    nextpad = pow(padding, i);
    leftover = num/nextpad;
    if(leftover == 0)
    {
      return i;
    }
  }
}

int main()
{
  int original, oldDigit, newDigit, index, maxIndex;
  
  cout << "Enter original number: ";
  cin >> original;
  
  if(!cin)
  {
    cout << "Original number is not an int." << endl;
    return 0;
  }
  
  
  
  cout << "Enter integer to be replaced: ";
  cin >> oldDigit;
  cout << "Enter integer that will replace the above integer: ";
  cin >> newDigit;
  
  cout << replaceDig(original, oldDigit, newDigit) << endl;
  return 0;
}