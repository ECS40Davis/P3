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
    } // switch (choice)

  }  // infinite while loop

}  // run())


int main(int argc, char** argv) 
{
//  int i;

  Vector cities;
  cities.readCities();

//  for(i = 0; i < cities.count; i++)
//  {
//    printf("%s %s \n", cities.cityArray[i].name, cities.cityArray[i].state);
//  }

  cities.readAirports();

//  for(i = 0; i < cities.count; i++)
//  {
//    printf("\n%s %s %s", cities.cityArray[i].name, cities.cityArray[i].state, cities.cityArray[i].airport);
//  }

  cities.cleanCities();
  run(&cities);
  return 0;
} // main())
