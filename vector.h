#ifndef VECTOR_H
#define	VECTOR_H
// Author Sean Davis
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#include "city.h"
using namespace std;

class Vector
{
private:
  City *cityArray;
  int size;
  int count;

  void resize();

public:
  Vector(); //default constructor
  ~Vector(); //default destructor
  void calcDistance(int index1, int index2)const;
  void cleanCities();
  int findAirport(const char *airport)const;
  void readAirports();
  void readCities();
};// Vector
#endif	// VECTOR_H 
