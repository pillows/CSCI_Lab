/*
Author: 
Course: {135,136}
Instructor: <Alex Nikolaev
Assignment: Lab 2 task B

*/

#include <iostream>
using namespace std;

int main()
{
	double p0 = 0; //population
	double g = 0; //growth rate
	double h = 0; //death rate
	double M = 0; //Maximum capacity
	int y = 0; //years
	
	cout << "Enter the initial population (p0)" << endl;
	cin >> p0;
	while (p0 < 0) //error checking, we need p0 a positive number
	{
		 cout << "Please re-enter" << endl;
		 cin >> p0;
	}
	
	cout << "Enter the groth rate (g)" << endl;
	cin >> g;
	while (g < 0) //error checking, we need g a positive number
	{
		 cout << "Please re-enter" << endl;
		 cin >> g;
	}
	
	cout << "Enter the death rate (h)" << endl;
	cin >> h;
	while (h < 0) //error checking, we need h a positive number
	{
		 cout << "Please re-enter" << endl;
		 cin >> h;
	}
	
	cout << "Enter the maximum capacity (M)" << endl;
	cin >> M;
	
	while (M < 0) //error checking, we need p0 a positive number
	{
		 cout << "Please re-enter" << endl;
		 cin >> M;
	}
	
	cout << "Enter the number of years to simulate (years):";
	cin >> y;
	
	cout << "0	" << p0 << endl;
	for(int i=1; i<=y ; i++)
	{
		p0 = p0 + (g * p0) - (h * p0) - (g * (p0*p0)/M);
		cout << i << "	" << p0 << endl;
	}
	
}
		