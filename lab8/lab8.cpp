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
#include <cmath>

using namespace std;

const int MAXCOUNTRIES = 300;

struct Country {
  string name;
  double pops[8];  // stores population in 1950, 1960,..., 2010, 2015 in order
};

struct World {
  int numCountries;
  Country countries[MAXCOUNTRIES];
} myWorld;

// Growth rate is initial + final / initial
void growthRate(World &world){
  double initPop, finalPop, grow, fastInitPop, fastFinalPop, fastgrow, slowgrow, slowInitPop, slowFinalPop;
  int fastest, slowest;
  fastest = slowest = 0;

  for(int i = 0; i < world.numCountries; i++){


    /*
    initPop/finalPop/grow = values for the current comparing country
    slowInitPop/slowFinalPop/slowgrow = stored values for the slowest country
    fastInitPop/fastFinalPop/fastgrow = stored values for the fastest country
    */
    initPop = world.countries[i].pops[0];
    finalPop = world.countries[i].pops[7];

    fastInitPop = world.countries[fastest].pops[0];
    fastFinalPop = world.countries[fastest].pops[7];

    slowInitPop = world.countries[slowest].pops[0];
    slowFinalPop = world.countries[slowest].pops[7];

    grow = abs((finalPop - initPop) / initPop * 100); // Growth formula for current country

    fastgrow = abs(((fastFinalPop - fastInitPop) / fastInitPop) * 100); // Growth for highest

    slowgrow = abs(((slowFinalPop - slowInitPop) / slowInitPop) * 100);
    

    if(grow > fastgrow) // Getting the highest by comparing with the current and keeping the highest index
      fastest = i;

    if(grow < slowgrow){ // Opposite of the above if
      slowest = i;
    }
  }

  cout << "The fastest growing country is" <<  world.countries[fastest].name <<", which grew by " << fastgrow << "% between 1960 and 2015." << endl;
  cout << "The slowest growing country is" <<  world.countries[slowest].name <<", which grew by " << slowgrow << "% between 1960 and 2015." << endl;
  
  
}

void sortNegative(World &world){



}

void readFile(World &world){
  string cname;
  int country = 0;
  double p50, p70, p90, p10, p15;

  ifstream csv;

  Country temp;
  csv.open("population.csv");
  while (csv >> p50 >> p70 >> p90 >> p10 >> p15) {

    getline(csv, cname);

    temp.name = cname;

    temp.pops[0] = p50;          // 1950
    temp.pops[1] = (p50+p70)/2; // 1960
    temp.pops[2] = p70;         // 1970
    temp.pops[3] = (p70+p90)/2;            // 1980
    temp.pops[4] = p90;              // 1990
    temp.pops[5] = (p90+p10)/2;              // 2000
    temp.pops[6] = p10;              // 2010
    temp.pops[7] = p15;            // 2015
    
    //cout << cname << endl;
    world.countries[world.numCountries] = temp;
    world.numCountries++;

  }
  growthRate(world);
  csv.close();
}

int main(){
  myWorld.numCountries = 0;
  readFile(myWorld);
  return 0;
}

