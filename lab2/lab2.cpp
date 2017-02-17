
/*
  Author: Matthew Wong
  Course: {135,136}
  Instructor: Ilya
  Assignment: Lab 3

  Calculate Verhulst Formula
*/

#include <iostream>
#include <iomanip>
using namespace std;
int start_s=clock();
int main(){

/*
Complete formula
p(n+1) = (1+g-h)p(n) - gp(n)^2/M.

*/

int initPop,calcYears;
//p (initPop) = initial population 
//n (calcYears) = year 
//m (maxPop) = maximum population 

double growthRate,lossRate,maxPop,finalPop;
//g (growthRate) = rate of growth 
//h (lossRate) = minimum loss rate
//finalPop = final population


//population loses gp(n) every year
/*
Initial population must at least be greater than 1
If not then loop
*/
do {
	cout << "Enter the initial population: ";
	cin >> initPop;

	
} while(initPop < 1);

/*
The number of years that are being calculated
Must be greater than 0
*/

do {

	cout << "Enter the number of years to calculate: ";
	cin >> calcYears;
	
} while(calcYears < 0);

/*
The rate of growth and loss for the population
User will input the rate in percentage form
It will then be converted to decimal
*/

do {

	cout << "Enter the rate of growth: (without %) ";
	cin >> growthRate;
	
} while(growthRate <= 0);

growthRate /= 100; //to convert into decimal format

do {

	cout << "Enter the rate of loss: (without %) ";
	cin >> lossRate;
	
} while(lossRate <= 0);

lossRate /= 100; //to convert into decimal format

/*
The maximum population
*/

do {

	cout << "Enter the maximum population: ";
	cin >> maxPop;

	
} while(maxPop < 1);



// Formatting columns to look nice
cout << setw(2) << left << "Year" << setw(25) << right << "Population" << endl;

// No decimals
cout << setprecision(0) << fixed;

//Hardcode for testing

initPop = 10;
calcYears = 20;
maxPop = 100;

growthRate = 2.9;
lossRate = .2;


for(int i=1;i <=calcYears;i++){
	if(i == 1)
		finalPop = ((1 + growthRate - lossRate) * initPop * i) - (growthRate *((initPop * i) / maxPop));
	else
		finalPop = ((1 + growthRate - lossRate) * finalPop) - (growthRate * ((finalPop * finalPop) / maxPop));

    //Keeps the value of the previous calculated population
    cout << setw(2) << i << left  << setw(25)<< right << finalPop << endl;
    
}

/*

Part 2
The bottom values are being calculated with:
10 as the initial population
20 years to calculate
100 as the maximum population
20% as the loss rate


Starts oscillating:
Part 1: 183%
Starts a little oscillation along years 3-5 and then becomes asymptotic with 89 as the population
Part 2: 205%
Pattern starts repeating and ends with 90-91 for the years 17-20

Starts chaotic pattern: 267%
First chaotic values start at years 3-5 going from 99-82-105


*/
return 0;
}
