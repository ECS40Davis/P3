// Author: Sean Davis

#include "vector.h"

void Vector::initialize()
{
  size = 10;
  count = 0;
  cityArray = new City[size];
  
  for (int i = 0; i < size; i++)
    cityArray->initialize();
}  // initialize()


void Vector::deallocate()
{
  for (int i = 0; i < count; i++)
    cityArray->deallocate();

  delete [] cityArray;
}  // deallocate())


void Vector::calcDistance(int index1, int index2)const
{
  cityArray[index2].calcDistance(&cityArray[index1]);
}  // calcDistance()

void Vector::cleanCities()
{
  int i = 0;
  
  while (i < count)
  {
    if (!cityArray[i].hasAirport())
    {
      cityArray[i].deallocate();
      cityArray[i] = cityArray[--count];
    }  // if city does not have an airport
    else // city has an airport
      i++;
  }  // while more in array
}  // cleanCities())


int Vector::findAirport(const char* airpor)const
{
  City city;
  
  city.initialize();
  city.setAirport(airpor);
  
  for (int i = 0; i < count; i++)
    if (cityArray[i].isEqual(&city))
      return i;
  
  cout<<airpor<<" is not a valid airport.\n";
  return -1;
}  // findAirport()

//<----------------------------------------------------------do
void Vector::readAirports()
{
  char line[1000];
  City city;
  city.initialize();
  
  FILE *fp = fopen("airportLL.txt", "r");
//  fstream file;
//  file.open("airportLL.txt");

  while (fgets(line, 1000, fp))
  {
    if (line[0] == '[')
    {
      city.readAirport(line);
      
      for (int i = 0; i < count; i++)
        if (cityArray[i].isEqual(&city))
        {
          cityArray[i].copyLocation(&city);
          break;
        }  // if found a matching name
      
      city.deallocate();
    }  // if an airport line
  }  // while
}  // readAirports()

//<----------------------------------------------------------do
void Vector::readCities()
{
  FILE *fp = fopen("citypopulations.csv", "r");
  
  while(!feof(fp))
  {
    if (size == count)
      resize();

    cityArray[count++].readCity(fp);

  } // while more in file
  
  count--;
  fclose(fp);

}  // readCities()


void Vector::resize()
{
  int i;
  City *temp = new City[2 * size];
  
  for (i = 0; i < size; i++)
    temp[i] = cityArray[i];
  
  size *= 2;
  
  for ( ;i < size; i++)
    temp[i].initialize();
    
  delete [] cityArray;
  cityArray = temp;
}  // resize()

