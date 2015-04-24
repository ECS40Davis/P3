#ifndef CITY_H
  #define CITY_H

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

class City
{        

        float longitude;
        float latitude;
        char *name;
        char *state;
        char *airport;
        float population;
 
      public:
   
        // sets default values
        void initialize();
    
        // parses line from airpotLL.txt
        void readAirport(char *airs);
    
        // parses line from citypops.csv
        void readCities(char *n, char *st, float pop);
            
        // true if cities have identical nams
        bool isEqual(const City *city1, const City *city2);
        
        //set airpot of local City variable of findAirport()
        void setAirport(const char *airName);
    
        // DO THIS ONE LATER
        void copyLocation(const City *city2);
    
        // true if city has airpot
        bool hasAirport();
    
        // calculate distance between airpots
        void calcDistance(const City *city1, const City *city2);
        
        int const calcPopulation(const City *city1, const City *city2);
    
        // kills memory leaks or unrecoverable space
        void deallocate();

        // New functions
        // Compare Airports
        int cmpAirport(City *city1, City *city2);
  
        // Compare Abbreviations
        int cmpAbv(char *abv);

        // Get Name
        char* getName(void);
 
        // Get State
        char* getState(void);
        
}; //endclass


#endif
