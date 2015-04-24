#ifndef VECTOR_H
  #define VECTOR_H

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include "city.h"
using namespace std;


class Vector
{
        City *cityArray;
        int size;
        int count;

        // double array siz if necessary
        void resize();
        
        // return city index in cityarray that has specified airport, else -1
        int findAirport(const char *airportName, const City *cityArr)const;
        
        void cleanCities();
    
        // kills memory leaks or unrecoverable space
        void deallocate();

      public:

        // Functions in Main
        // sets default values
        void initialize();

        // reads airportsLL.txt, calls City's readAirport()
        void readAirports();
    
        // read line from citypopulations.csv + store data in cityarray
        void readCities();

    
        // Functions in Run
        // calls City's calcDistance()
        void calcDistance(char *abv1, char *abv2)const;
        
        char *returnname(char *abv1);
        
        char *returnStateName(char *abv1);
        
}; //endclass
                      
#endif
