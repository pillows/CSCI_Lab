
/*
  Author: Matthew Wong
  Course: {135,136}
  Instructor: Ilya
  Assignment: Lab 3

  Calculate Verhulst Formula
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;

int main(){
/*
Complete formula
p(n+1) = (1+g-h)p(n) - gp(n)^2/M.

*/
int initPop,years,maxPop,finalPop,initf;
//p = initial population --------- p(n) is population for year n
//n = year
//m = maximum population

double growthRate,lossRate;
//g = rate of growth
//h = minimum loss rate --------- both are percentages/decimals
//finalPop = final population


//population loses gp(n) every year

while(true){
    cout << "Enter the initial population: ";
    cin >> initPop;
    
    if(initPop < 2){
        cout << "Please enter a number that is at least greater than 2." << endl;
        return 0;
    }
    
    cout << "Enter the number of years to calculate: ";
    cin >> years;
    
    if(initPop < 0){
        cout << "Please enter a number that is at least greater than 0." << endl;
        return 0;
    }
    
    cout << "Enter the rate of growth: (Please enter in percentage format without the percent sign) ";
    cin >> growthRate;
    
    if(growthRate < 0){
        cout << "Please enter a number that is at least greater than 0." << endl;
        return 0;
    }
    
    cout << "Enter the rate of loss: (Please enter in percentage format without the percent sign) ";
    cin >> lossRate;
    
    
    if(lossRate < 0){
        cout << "Please enter a number that is at least greater than 0." << endl;
        return 0;    
    }
    
    cout << "Enter the maximum population: ";
    cin >> maxPop;
    
    if(maxPop <= 0){
        cout << "Please enter a number that is at least greater than 0." << endl;
        return 0; 
    }
    
    //To covert user input to decimal format
    growthRate /= 100;
    lossRate /= 100;
    
    
    /*
    p = 10;
    n = 1;
    m = 100;
    
    g = 2.5;
    h = 0.2;
    */
    
    cout << setw(2) << left << "Year" << setw(25) << right << "Population" << endl;
    
    for(int i=1;i <years;i++){
    	if(i==1)
    		finalPop = ((1 + growthRate - lossRate) * initPop * i) - (growthRate *((initPop * i) / maxPop));
    	else
    		finalPop = ((1+growthRate - lossRate) * finalPop) - (growthRate * ((finalPop * finalPop) / maxPop));
    
        initf = finalPop; //Keeps the value of the previous calculated population
        cout << setw(2) << i << left  << setw(25)<< right << finalPop << endl;
        
    }
    return 0;
}


}
