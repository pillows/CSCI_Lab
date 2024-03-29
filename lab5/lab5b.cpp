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

int digitAtIndex(int, int);
int numDigits(int);
int divisibleByNine(int);

int digitAtIndex(int num, int index)  // return the index'th digit of num   97534 (4 indicies, to get index 2, )
{
  // cout << "digitAtIndex function" << endl;
  int padding = 10;
  int nextpad, leftover;
  int indexStop = numDigits(num) - index;
  // cout << "indexStop: " << indexStop << endl;
  int numberOfDigits = numDigits(num);

  for (int i = numberOfDigits; i > 0; i--) {
    nextpad = pow(padding, i - 1);
    // cout << "nextpad value: " << nextpad << endl;
    leftover = num / nextpad;
    // cout << "Leftover: " << leftover << endl;

    if (i == indexStop) {
      return leftover % 10;
    }
  }
  // cout << "end digitAtIndex function" << endl;
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
  // cout << "leftover: " << leftover << endl;
  int lastDigit = digitAtIndex(num, numDigits(num) - 1);
  // cout << "last digit: " << lastDigit << endl;
  int leftPlusLastDigit = lastDigit + leftover;
  // cout << "last addition digit: " << leftPlusLastDigit << endl;
  if (leftover == 0) return num;

  int getNine = (9 - lastDigit) + num;

  for (int i = 0; i <= 9; i++) {
    if (getNine % 9 == 0) return getNine;

    cout << "------------------" << endl;
    cout << "i " << i << endl;
    cout << "modulo " << ((getNine - i) % 9) << endl;
    cout << "------------------" << endl;
    if ((getNine - i) % 9 == 0) {
      getNine -= i;
      cout << "Second if " << ((getNine - i) % 9) << endl;
      return getNine;
    }
  }
}

  /*
  else if(leftPlusLastDigit < 5)
  {
    num -= leftover;

    cout << "First else if" << endl;
    return num;
  }
  else if(leftPlusLastDigit > 5)
  {
    num += (leftPlusLastDigit - leftover);

    cout << "Second else if" << endl;
    return num;
  }
  else if()
  */

int sumDigits(int num) {
  int loops = numDigits(num);
  int result = 0;
  if (num < 10) return num;
  for (int i = 0; i < loops; i++) {
    result += digitAtIndex(num, i);
  }
  return result;
}
int main() {
  int number;

  cout << "Enter number: ";
  cin >> number;
  cout << sumDigits(number);
  cout << transformNum(number) << endl;
  
  return 0;
}