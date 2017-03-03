/*
  Author: Matthew Wong
  Course: {135,136}
  Instructor: Ilya
  Assignment: Lab 4

  Factorials
*/

#include <iostream>
using namespace std;

/*
  The loop would start from the
  factorial and decrease by one for each iteration.
  Used a base for Tasks 1 and 2.
*/

int computeFactorial(int factorial) {
  int result = 1;
  int steps = 0;
  for (int i = factorial; i > 0; i--) {
    result *= i;
    steps++;
  }
  cout << "computeFactorial steps: " << steps << endl;  // Checking steps required for calculation
  return result;
}

/*
  This loop uses the n(n-1)(n-2)...(n-k+1)/k! method
  Used for Task 2
*/
int nMinusOneLoop(int n, int k) {
  int result = 1;
  int steps = 0;
  for (int i = 0; i < k; i++) {
    steps++;
    if (i == 0)  // The first iteration will always multiply n first
      result *= n;

    else if (i < (k - 1))  // If i is still less than k - 1 then the iteration
                           // will multiply by n - i
      result *= (n - i);

    else
      result *= (n - k + 1);  // Last step is the final iteration (n - k + 1)
  }
  cout << "nm1loop steps: " << steps
       << endl;  // Checking steps required for calculation
  return result;
}

// Function for Task 1
int computeCnk(int n, int k) {
  int result;
  result = computeFactorial(n) / (computeFactorial(k) * computeFactorial(n - k));  // Calculates n!/(k!(n-k)!)
  return result;
}

// Function for Task 2 and 3
int computeCnk2(int n, int k) {
  int result;
  result = nMinusOneLoop(n, k) / computeFactorial(k);
  return result;
}

/*
  Function for Task 4
  The inputs must be floats as opposed to ints or else in division they will be
  rounded to the nearest integer
*/
float cnkTask4(float n, float k) {
  float result = 1;
  int steps = 0;
  for (int i = 1; i <= k; i++) {
    steps++;
    result *= (1 + ((n - k) / i));
  }
  cout << "cnkTask4 steps: " << steps
       << endl;  // Checking steps required for calculation
  return result;
}

int main() {
  int task = 1;
  cout << "1. Compute C(n,k)" << endl;
  cout << "2. Computer C(n,k) using n(n-1)(n-2)...(n-k+1)/k!" << endl;
  cout << "3. Using P2 to calculate factorial" << endl;
  cout << "4. Computer C(n,k) using  (1+(n-k)/1) (1+(n-k)/2) (1+(n-k)/3) ... "
          "(1+(n-k)/k)"
       << endl;
  cout << "Choose the task that you would like to start: ";
  cin >> task;

  int n, k, smallest;

  switch (task) {
    /*
      Explanation for Task 1:
      12 would be the smallest number before error because 13! would equal
      6,227,020,800 while the largest number for ints is 2,147,483,647

      Test Case:
      Value for n: 7
      Value for k: 4
      computeFactorial steps: 7
      computeFactorial steps: 4
      computeFactorial steps: 3
      35

      The number of steps used for this test case is 14.

    */

    case 1:
      cout << "Task 1: Insert the input numbers for n and k to compute C(n,k)"
           << endl;
      cout << "Value for n: ";
      cin >> n;
      cout << "Value for k: ";
      cin >> k;

      cout << "Answer: " << computeCnk(n, k) << endl;

      break;

    /*
      Test case for Task 2:
      Value for n: 7
      Value for k: 4
      nm1loop steps: 4
      computeFactorial steps: 4
      Answer: 35

      Total number of steps is lower than Task 1.  4 + 4 = 8
    */

    case 2:
      cout << "Task 2: Insert the input numbers for n and k to compute C(n,k)"
           << endl;
      cout << "Value for n: ";
      cin >> n;
      cout << "Value for k: ";
      cin >> k;

      cout << "Answer: " << computeCnk2(n, k) << endl;

      break;

    /*
      Test case for Task 3:
      Value for n: 7
      Value for k: 4
      nm1loop steps: 3
      computeFactorial steps: 3
      Answer: 56

      To get the fewest amount of steps for multiplication choose the lowest
      value for k.
      Example: (5 2) is the same as (5 3) but (5 2) will take fewer steps with a
      lower k.
    */

    case 3:
      cout << "Task 3: Insert the input numbers for n and k to compute C(n,k)"
           << endl;
      cout << "Value for n: ";
      cin >> n;
      cout << "Value for k: ";
      cin >> k;

      smallest = n - k;
      if (smallest < k)  // Choose the smallest k to make it more efficient.
        k = smallest;

      cout << "Answer: " << computeCnk2(n, k) << endl;
      break;

    /*
      Test case for Task 4:
      Value for n: 6
      Value for k: 4
      cnkTask4 steps: 4
      Answer: 15
    */

    case 4:
      cout << "Task 4: Insert the input numbers for n and k to compute C(n,k)"
           << endl;
      cout << "Value for n: ";
      cin >> n;
      cout << "Value for k: ";
      cin >> k;

      cout << "Answer: " << cnkTask4(n, k) << endl;

      break;

    default:
      cout << "You chose a number that is not between 1 and 4." << endl;
  }
  return 0;
}
