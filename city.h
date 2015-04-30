#ifndef CITY_H
#define	CITY_H
// Author: Sean Davis
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

class City
{
public:
  double longitude;
  double latitude;
  char *name;
  char *state;
  char airport[4];
  int population;

public:
  City(); //default constructor
  ~City(); //default destructor
  City& operator=(const City &rhs);
  void calcDistance(const City *city1)const;
  void copyLocation(const City *srcCity);
  bool hasAirport();
  bool isEqual(const City *city)const;
  void readAirport(char *line, char *stat);
  void readCity(fstream *fp);
  void setAirport(const char *airport);
  int calcAirportTraffic(const City *city1)const;
}; //endclass
#endif	// CITY_H 
