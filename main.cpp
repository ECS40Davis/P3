// Author: Sean Davis 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#include "vector.h"
using namespace std;

void run(const Vector *cities)
{
  int choice, exit = 0;

  while (!exit)
  {
    choice = cities->getChoice();
    switch (choice)
    {
      case 0:
        exit = 1;
        break;
      case 1:
        cities->cmpCity();
        break;
      case 2:
        cities->calcAirportTraffic();
        break;
    }

  }  // infinite while loop
}  // run())


int main(int argc, char** argv) 
{
  Vector cities;
  cities.readCities();
  cities.readAirports();
  cities.cleanCities();

//  srand(1);
//  int i;
//  for(i = 0; i < cities.count; i++){
    //printf("%s %s\n", cities.cityArray[i].airport, cities.cityArray[rand() % cities.count].airport);
//    printf("%s %s %d %lf\n", cities.cityArray[i].name, cities.cityArray[i].state, cities.cityArray[i].population, cities.cityArray[i].longitude);
//  }
  run(&cities);
  return 0;
} // main())
