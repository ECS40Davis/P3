#include "city.h"

void City::initialize()
{
    name = new char[50];
    state = new char[50];
    airport = new char[50];
    longitude = 0.0;
    latitude = 0.0;
    population = 0;
    
} // initialize()

void City::readAirport(char *airports)
{

    if (airports)
    {
        char tempairport[100];
        sscanf(airports, "%s  %f  %f  %[^,]%*c", tempairport,
                       &latitude, &longitude, name);
        std::string s (tempairport);
        this->airport = strdup(s.substr(1, 3).c_str());
        
    }	
} // readAirport()

void City::readCities(char *n, char *st, float pop)
{
    this->name = n;
    this->state = st;
    this->population = pop;
    
} // readCities()
                      
bool City::isEqual(const City *city1, const City *city2)
{

    if (strcmp(city2->name, city1->name) == 0)
        return true;
    return false;
        
} // isEqual()
                      
void City::copyLocation(const City *city2)
{
    this->airport = city2->airport;
    this->latitude = city2->latitude;
    this->longitude = city2->longitude;    
    
} // copyLocation()
                      
void City::deallocate()
{
    
    delete name;
    delete state;
    //fre(airport);
        
} // deallocate()
                      
void City::setAirport(const char *airportName)
{    
    airport = strdup(airportName);
}//void City::setAirport(const char *airportName)
                      
bool City::hasAirport()
{
    char c;
    int i = 0;
    
    while (this->airport[i])
    {
        c = this->airport[i];

        if (!isupper(c))
            return false;
        i++;
    }//while (this->airport[i])
    
    return true;
    
} // hasAirport()
                      
void City::calcDistance(const City *city1, const City *city2)
{
    City test;
    int R = 3963;
    int passengers;
    int dist = floor(acos(sin(city1->latitude * M_PI / 180)
               * sin(city2->latitude * M_PI / 180)
               + cos(city1->latitude * M_PI / 180)
               * cos(city2->latitude * M_PI / 180)
               * cos(city1->longitude * M_PI / 180
               - city2->longitude * M_PI / 180)) * R);

    if (dist < 100)
        passengers = 0;

    else // farthur than 100 miles
        passengers = test.calcPopulation(city1, city2);

    cout<<passengers<<" passengers fly the "<<dist<<" miles from\n";
} // calcDistance()

int const City::calcPopulation(const City *city1, const City *city2)
{
    return floor((city1->population * city2->population) / 250000000) ;
    
}//double City::calcPopulation(City city2)

// New Functions

int City::cmpAirport(City *city1, City *city2)
{
  return strcmp(city1->airport, city2->airport);
}//int cmpAirport(City city1, City city2);

int City::cmpAbv(char *abv)
{
  return strcmp(abv, airport);
}//City::cmpAbv(char *abv)

char* City::getName(void)
{
  return name;
}//City::getName(void)

char* City::getState(void)
{
  return state;
}//char* City::getState(void)
