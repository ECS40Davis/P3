#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "city.h"
using namespace std;

void City::initialize()
{
  name = NULL;
  state = NULL;
  airport[0] = '\0';  // sentinel value
}  // initialize()


void City::deallocate()
{
  if (name)
    free(name);

  if (state)
    free(state);
}  // deallocate()


void City::calcDistance(const City *city1)const
{
  int distance, passengers;
  
  passengers = (double) city1->population * population / 250000000;
  distance = acos(
    sin(city1->latitude * M_PI / 180) * sin(latitude * M_PI / 180) 
    + cos(city1->latitude * M_PI / 180) * cos(latitude * M_PI / 180)
    * cos((city1->longitude - longitude) * M_PI / 180)) * 3963;
  
  if (distance < 100)
    passengers = 0;

  printf("%d passengers fly the %d miles from\n%s,%s to %s,%s\n", passengers,
    distance, city1->name, city1->state, name, state);
  
}  // calcDistance())

void City::copyLocation(const City *srcCity)
{
  strcpy(airport, srcCity->airport);
  latitude = srcCity->latitude;
  longitude = srcCity->longitude;
}  // copyLocation()


bool City::hasAirport()
{
  return this->airport[0] != '\0';
}  // hasAirport()


bool City::isEqual(const City *city)
{
  if (city->name && name)
    return strcmp(city->name, name) == 0;
  
  if (city->airport[0] && airport[0])
    return strcmp(city->airport, airport) == 0;
  
  return false;
}  // isName()

//<---------------------------------------------------------do
void City::readCity(FILE *fp)
{
  char line[1000], *ptr;
  
  if (!fgets(line, 1000, fp) || !strstr(line, ","))
    return;
  
  ptr = strtok(line, ",");
  
  if (ptr)
  {  
    name = (char*) malloc(strlen(ptr) + 1);
    strcpy(name, ptr);
    ptr = strtok(NULL, ",");
    state = (char*) malloc(strlen(ptr) + 1);
    strcpy(state, ptr);
    population = atoi(strtok(NULL, ",\n"));
  } // if something on line
}  // readCity()

void City::readAirport(char *line)
{
  char *ptr;
  
  strtok(line, "] ");
  strcpy(airport, &line[1]);
  latitude = atof(strtok(NULL, " "));
  longitude = atof(strtok(NULL, " "));
  ptr = strtok(NULL, ",") + 1;
  name = (char*) malloc(strlen(ptr) + 1);
  strcpy(name, ptr);
}  // readAirport


void City::setAirport(const char *airpor)
{
  strcpy(airport, airpor);
}  // setAirport()
