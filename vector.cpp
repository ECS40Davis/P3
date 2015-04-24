#include "vector.h"
#include "city.h"
                      
void Vector::initialize()
{
    count = 0;
    size = 10;
    cityArray = new City[10];
        
} // initialize()
                      
void Vector::resize()
{
  if (count == size)
  {
    City *newSpace = new City[2 * size];
    
    for (int i = 0; i < size; i++)
    {
        newSpace[i] = cityArray[i];
        //cityArray[i].deallocate();
        
    } //for loop
    //todo: delete entire cityArray
    cityArray = newSpace;
    size *= 2;
      
  } //if

} // resize()
                      
void Vector::readAirports()
{
    //supposed to call isEqual() and copyLocation()
    fstream file;
    string line;
    char airport[100];
    float latitude;
    float longitude;
    char name[100];
    file.open("airportLL.txt"); //, iostream
    
    while(std::getline(file, line))
    {
        char *cstring = strdup(line.c_str());
        int fsf = sscanf(cstring, "%s  %f  %f  %[^\n]%*c", 
                airport, &latitude, &longitude, name);

        if (fsf == 4)
        {
            strtok(name, ",");
            strtok(NULL, "/0");
            City tempCity;
            tempCity.initialize();
            tempCity.readAirport(cstring);
            
            for (int i = 0; i < count; i++)
            {

                if (tempCity.isEqual(&cityArray[i], &tempCity))
                {
                    cityArray[i].copyLocation(&tempCity);
                } //if
            } //for
        } //if
    } //while
} // readAirports()

void Vector::readCities()
{
    char *name;
    char *state;
    int population;
    fstream file;
    string line;
    
    file.open("citypopulations.csv");
   
    while(getline(file, line))
    {
        char *cstring = strdup(line.c_str());
    
        name = strtok(cstring, ",");
        state = strtok(NULL, ",");
        population = atoi(strtok(NULL, "\n"));
        
        City newCity;
        newCity.initialize();
        newCity.readCities(name, state, population);
        
    
        this->cityArray[count] = newCity;
        count++;
        this->resize();
    } //while
                
} // readCities()
                      
int Vector::findAirport(const char *airportName, const City *cityArr) const
{
    City city1;
    city1.initialize();
    city1.setAirport(airportName);
    City city2;
    
    for (int i = 0; i < this->count; i++)
    {
        city2 = cityArr[i];
     
        if (city1.cmpAirport(&city1, &city2) == 0)
        {
            return i;
        } //if
        
    } //for
    
    return -1;
} //int Vector::findAirport                  

void Vector::cleanCities()
{
    int airportCount = 0;   
    
    City *newSpace = new City[size];
    
    for (int i = 0; i < size; i++)
    {
        
        if (cityArray[i].hasAirport())
        {
            newSpace[airportCount] = cityArray[i];
            cityArray[i].deallocate();
            airportCount++;
            
        } //if
        
    } //for
//todo: delete entire cityArray
    count = airportCount;
    cityArray = newSpace;
} //end cleanCity

void Vector::calcDistance(char *abv1, char *abv2) const
{
    int index = findAirport(abv1, cityArray);
    City city1 = cityArray[index];
    
    int index2 = findAirport(abv2, cityArray);
    City city2 = cityArray[index2];
    
    city1.calcDistance(&city1, &city2);
    
    //return cityArray[findAirport(abv1)].calcDistance(cityArray[findAirport(abv2)])
    
} // calcDistance()

void Vector::deallocate()
{
    
    for (int i = 0; i < count; i++)
        cityArray[i].deallocate();
    
    delete [] cityArray;
        
} // deallocate()

char* Vector::returnname(char *abv1)
{
    //takes in abbreviation, searches thru array for abv, return name of abv
    for (int i = 0; i < count; i++)
        if (cityArray[i].cmpAbv(abv1) == 0)
            return cityArray[i].getName();
    return strdup("City Name Not Found");
    
} //returnname

char* Vector::returnStateName(char *abv1)
{

    for (int i = 0; i < count; i++)

        if (cityArray[i].cmpAbv(abv1) == 0)
            return cityArray[i].getState();
    return strdup("State Name Not Found");
} //returnStateName
