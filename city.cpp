
#include "city.h"

City::City():name(NULL), state(NULL)
{
  airport[0] = '\0';  // sentinel value
} // default constructor


City::~City()
{
  if (name)
    delete [] name;

  if (state)
    delete [] state;
}  // default destructor

City& City::operator=(const City &rhs)
{
  if (this == &rhs)
    return *this;

  longitude = rhs.longitude;
  latitude = rhs.latitude;

  if (name)
    delete [] name;

  if (rhs.name)
  {
    name = new char[strlen(rhs.name) + 1];
    strcpy(name, rhs.name);
  } // if (rhs.name)

  if (state)
    delete [] state;

  if (rhs.state)
  {
    state = new char[strlen(rhs.state) + 1];
    strcpy(state, rhs.state);
  } // if (rhs.state)

  strcpy(airport, rhs.airport);
  population = rhs.population;
  return *this;
} // operator=

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

  cout<<passengers<<" passengers fly the "<<distance<<" miles from\n"
      <<city1->name<<","<<city1->state<<" to "<<name<<","<<state<<"\n";
  
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

void City::readCity(fstream *fp)
{
  string line;
  char *ptr;
  
  if (!getline(*fp, line) || !strstr(line.c_str(), ","))
    return;

  char *line_copy = strdup(line.c_str());
  ptr = strtok(line_copy, ",");
  
  if (ptr)
  {  
    name = new char[strlen(ptr) + 1];
    strcpy(name, ptr);
    ptr = strtok(NULL, ",");
    state = new char[strlen(ptr) + 1];
    strcpy(state, ptr);
    population = atoi(strtok(NULL, ",\n"));

  } // if something on line
  delete [] line_copy;
}  // readCity()

void City::readAirport(char *line)
{
  char *ptr;
  
  strtok(line, "] ");
  strcpy(airport, &line[1]);
  latitude = atof(strtok(NULL, " "));
  longitude = atof(strtok(NULL, " "));
  ptr = strtok(NULL, ",") + 1;
  name = new char[strlen(ptr) + 1];
  strcpy(name, ptr);
}  // readAirport


void City::setAirport(const char *airpor)
{
  strcpy(airport, airpor);
}  // setAirport()
