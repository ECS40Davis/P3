#ifndef CITY_H
#define	CITY_H
// Author: Sean Davis
#include <cstdio>
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


  void initialize();
  void deallocate();
  void calcDistance(const City *city1)const;
  void copyLocation(const City *srcCity);
  bool hasAirport();
  bool isEqual(const City *city);
  void readAirport(char *line);
  void readCity(FILE *fp);
  void setAirport(const char *airport);
};//endclass
#endif	// CITY_H 