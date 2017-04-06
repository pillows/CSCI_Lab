/*
  Author: Matthew Wong
  Course: CSCI 136
  Instructor: Ilya Korsunsky
  Assignment: Lab 7
  Image Manipulation
*/

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAXCOUNTRIES = 0;
struct Country {
  string name;
  double pops[8];  // stores population in 1950, 1960,..., 2010, 2015 in order
};

struct World {
  int numCountries;
  Country countries[MAXCOUNTRIES];
} myWorld;


int main(){
  string csvx,p50,p70,p90,p10,p15,names,name;
  ifstream csv;
  csv.open("population.csv");
  while (csv >> p50 >> p70 >> p90 >> p10 >> p15) {
    getline(csv,name);
    cout << name << "\n";
  }
  csv.close();
  return 0;
}

