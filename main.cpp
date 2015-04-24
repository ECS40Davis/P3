#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include "vector.h"
using namespace std;

void run(Vector *cities);
                      
int main()
{
    Vector *cities = new Vector;
	    
    cities->initialize();
    cities->readCities();
    cities->readAirports();
    run(cities);
    
    return 0;
    
} // main()
                      
void run(Vector *cities)
{
    char abv1[10], abv2[10];
    //double passengers;
    //double distance;
    
    while (1)
    {
        cout<<"\nPlease enter two airport abbreviations (XXX XXX = done): ";
        cin>>abv1>>abv2;

        if (strcmp(abv1, "XXX") == 0 && strcmp(abv2, "XXX") == 0)
            break;
        
        if (strcmp(cities->returnStateName(abv1), "State Name Not Found") == 0)
            cout<<abv1<<" is not a valid airport.\n";
        
        if (strcmp(cities->returnStateName(abv2), "State Name Not Found") == 0)
            cout<<abv2<<" is not a valid airport.\n";
        
        if (strcmp(cities->returnStateName(abv1), "State Name Not Found") != 0
            && strcmp(cities->returnStateName(abv2),
            "State Name Not Found") != 0)
        {    
                cities->calcDistance(abv1, abv2);
                cout<<cities->returnname(abv1)<<","
                <<cities->returnStateName(abv1)<<" to "
                <<cities->returnname(abv2)
                <<","<<cities->returnStateName(abv2)
                <<"\n";
        }//if (strcmp(cities->return
    }//while(1)      
} // run()
