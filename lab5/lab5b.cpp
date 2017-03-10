/*
  Author: Matthew Wong
  Course: {135,136}
  Instructor: Ilya Korsunsky
  Assignment: Lab 5

  Functions with practicing 
*/

#include <iostream>
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


/*
Test case
2049 with index 3 will give 9
*/
int getDigit(int num, int index)  // return the index'th digit of num   97534 (4 indicies, to get index 2, )
{
  int padding = 10; // This is to get the number depending on the index by dividing by a power of 10
  int nextpad, leftover;
  int indexStop = numDigits(num) - index;
  int numberOfDigits = numDigits(num);

  for (int i = numberOfDigits; i > 0; i--) { // Start from the number of digits to get the highest power of 10
    nextpad = pow(padding, i - 1); 
    leftover = num / nextpad; // Will give the number that is leftover from the division of two ints

    if (i == indexStop) { // When the loop reaches the needed index, it will return the modulo of 10 giving the number of the index
      return leftover % 10;
    }
  }
}

/*
Test case:
1024 
will give
7 (1+2+4)

2048
will give
5 (2+4+8 = 14 = 1+4)
*/
int numDigits(int num)  // return the number of digits in num
{
  int padding = 10; // This time padding will increase until num becomes 0 from division
  int nextpad, leftover;
  int start = 1;
  
  while(true)
  {
    nextpad = pow(padding, start); // Goes from 10 at first loop, 100 at second, etc
    leftover = num / nextpad;
    if (leftover == 0) // When it can't divide anymore then we end the loop
      return start;
    
    else
      start++;
  }
}

int transformNum(int num) {

  int leftover = num % 9; // How much leftover is needed for a number to become a multiple of 9
  int lastDigit = getDigit(num, numDigits(num)); // Necessary for difference variable below 
  int result;
  int difference = (leftover - lastDigit); // How far the number needs to be added or subtracted to become a multiple of 9
  
  if(leftover == 0) // Multiple of 9 just return num
    return num;
    
  if(num < 9) // I would guess that anything below 9 should just be 9
    return 9;
    
  /*
    Test cases:
    1995
    difference < 5
    last digit < 4
    number returned will be 1998 (1+9+9+8 = 27)
    
    2017
    difference < 5
    last digit >= 5
    number returned will be 2016 (2+0+1+6 = 9)
    
    2022 
    else (difference > 5)
    last digit < 4
    number returned will be 2025 (2+0+2+5 = 9)
    
    2046
    else (difference > 5)
    last digit < 4
    number returned will be 2043 (2+0+4+3 = 9)
  */
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
  int loops = numDigits(num); // How many loops are required
  int result = 0;
  if (num < 10) return num; // If the number is less than 10 then it's done
  for (int i = 0; i < loops; i++) {
    result += getDigit(num, i); // Add each digit by index
  }
  if(result > 10)
    sumDigits(result); // If greater than 10 then do a recursive loop
  else
    return result; // If less than 10 then return result
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
