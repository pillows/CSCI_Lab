/*
  Author: Matthew Wong
  Course: {135,136}
  Instructor: Ilya
  Assignment: Lab 4

  Factorials
*/

#include <iostream>
using namespace std;

int computeFactorial(int factorial)
{
  int result = 1;
  for(int i = factorial; i > 0; i--)
    result *= i;
  return result;  
}

int nMinusOneLoop(int n, int k)
{
  int result = 1;
  for(int i = 0; i < k; i++)
  {
    if(i == 0)
      result *= n;
      
    else if(i == (k - 1))
      result *= (n - 1);
      
    else 
      result *= (n - k + 1);
      
  }
  return result;
}

int computeCnk(int n, int k)
{
  int result;
  result = computeFactorial(n)/(computeFactorial(k) * computeFactorial(n-k));
  return result;
}

int computeCnk2(int n, int k)
{
  int result;
  result = nMinusOneLoop(n,k) / computeFactorial(k);
  return result;
}

float cnkProduct(int n, int k)
{
  float result = 1;
  cout << "Cnk Product test" << endl;
  for(int i = 1; i < k; i++)
  {
    result *= (1+((n-k)/i));
      
  } 
  return result; 
}

float cnkMethod4(int n, int k)
{
  float result = 1;
  result = cnkProduct(n,k);
  return result;
}

int main()
{
  int task = 1;
  cout << "1. Compute C(n,k)" << endl;
  cout << "2. Computer C(n,k) using n(n-1)(n-2)...(n-k+1)/k!" << endl;
  cout << "Choose the task that you would like to start: ";
  cin >>  task;
  
  
  int n,k;

  /*
  cout << "Task 1: Insert the input numbers for n and k to compute C(n,k)" << endl;
  cout << "Value for n: ";
  cin >> n;
  cout << "Value for k: ";
  cin >> k;
  */
  
  switch(task)
  {
    // Task 1 completed
    case 1:
      cout << "Task 1: Insert the input numbers for n and k to compute C(n,k)" << endl;
      cout << "Value for n: ";
      cin >> n;
      cout << "Value for k: ";
      cin >> k;

      cout << computeCnk(n,k) << endl;
      break;
    case 2:
      cout << "Task 2: Insert the input numbers for n and k to compute C(n,k)" << endl;
      cout << "Value for n: ";
      cin >> n;
      cout << "Value for k: ";
      cin >> k;

      cout << computeCnk2(n,k) << endl;
      break;
    case 3:
      cout << "Task 3: Insert the input numbers for n and k to compute C(n,k)" << endl;
      cout << "Value for n: ";
      cin >> n;
      cout << "Value for k: ";
      cin >> k;
      cout << computeCnk(n,n-k) << endl;
      break;
    case 4:
      cout << "Task 4: Insert the input numbers for n and k to compute C(n,k)" << endl;
      cout << "Value for n: ";
      cin >> n;
      cout << "Value for k: ";
      cin >> k;
      cout << cnkMethod4(n,k) << endl;
      break;
    default:
      cout << "Default case" << endl;
  }
  return 0;    
}