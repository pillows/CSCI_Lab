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

// Precondition: num > 0 and (0 < index < number of Digits - 1)
// Postcondition: the return value is the iterated sum of digits of num
int getDigit(int num, int index);

// Precondition: num > 0
// Postcondition: the return value is the number of digits of the input number
int numDigits(int num);

// Precondition: num > 0
// Postcondition: the return value will make the input divisble by 9 not if not divisible already
int transformNum(int num);

// Precondition: num > 0
// Postcondition: the return value is the iterated sum of digits of num
int sumDigits(int num);

int getDigit(int num, int index)  // return the index'th digit of num   97534 (4 indicies, to get index 2, )
{
  int padding = 10;
  int nextpad, leftover;
  int indexStop = numDigits(num) - index;
  int numberOfDigits = numDigits(num);

  for (int i = numberOfDigits; i > 0; i--) {
    nextpad = pow(padding, i - 1);
    leftover = num / nextpad;

    if (i == indexStop) {
      return leftover % 10;
    }
  }
}

int numDigits(int num)  // return the number of digits in num
{
  int padding = 10;
  int nextpad, leftover;
  for (int i = 1; i < INT_MAX; i++) {
    nextpad = pow(padding, i);
    leftover = num / nextpad;
    if (leftover == 0) {
      return i;
    }
  }
}

int transformNum(int num) {

  int leftover = num % 9;
  int lastDigit = getDigit(num, numDigits(num));
  int result;
  int difference = (leftover - lastDigit);
  
  if(leftover == 0)
    return num;
  if(num < 9)
    return 9;
  if(difference < 5)
  {
    if(lastDigit < 4)
      result = (num - leftover);
    if(lastDigit >= 5)
      result = (num - (9 - leftover));
  }
  else
  {
    if(lastDigit < 4)
      result = (num + (9 - leftover));
    if(lastDigit >= 5)
      result = (num - (9 - leftover));
  }
    
  return result;
 
}

int sumDigits(int num) {
  int loops = numDigits(num);
  int result = 0;
  if (num < 10) return num;
  for (int i = 0; i < loops; i++) {
    result += getDigit(num, i);
  }
  if(result > 10)
    sumDigits(result);
  else
    return result;
}

int main() {
  int number;

  cout << "Enter number: ";
  cin >> number;
  cout << "The sum of the digits is: " << sumDigits(number) << endl;
  
  cout << transformNum(number) << " will now by divisble by 9." << endl;
  //cout << "Last digit is: " << getDigit(number, numDigits(number) - 1) << endl;
  return 0;
}
