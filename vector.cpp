// Author: Sean Davis

#include "vector.h"

Vector::Vector():size(10), count(0)
{
  cityArray = new City[size];
}  // default constructor


Vector::~Vector()
{
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
      cityArray[i] = cityArray[--count];
    }  // if city does not have an airport

    else // city has an airport
      i++;
  }  // while more in array

}  // cleanCities())


int Vector::findAirport(const char* airpor)const
{
  City city;

  city.setAirport(airpor);
  
  for (int i = 0; i < count; i++)
    if (cityArray[i].isEqual(&city))
      return i;
  
  cout << airpor << " is not a valid airport.\n";
  return -1;
}  // findAirport()

void Vector::readAirports()
{
  string line;
  City city;
  char * temp_state;
  fstream file;
  file.open("airportLL.txt");

  while (std::getline(file, line))
  {
    if (line[0] == '[')
    {
      cpyLocation(city, line, temp_state);
    } // if an airport line

    else // if state
      if (line[0] != '\0')
        {
          temp_state = new char[line.size() + 1];
          copy(line.begin(), line.end(), temp_state);
          temp_state[line.size()] = '\0';
        } // if state

  }  // while

}  // readAirports()

void Vector::readCities()
{
  fstream file;
  file.open("citypopulations.csv");

  while(!file.eof())
  {
    if (size == count)
      resize();

    cityArray[count++].readCity(&file);
  } // while more in file
  
  count--;
  file.close();
}  // readCities()


void Vector::resize()
{
  int i;
  City *temp = new City[2 * size];

  for (i = 0; i < size; i++)
  {
    temp[i] = cityArray[i];
  } // for all cities
  
  size *= 2;
  delete [] cityArray;
  cityArray = temp;
}  // resize()

int Vector::getChoice()const
{
    char input[79];
    int choice;
    // Menu
    cout << "\nFlight Simulator Menu\n";
    cout << "0. Done.\n";
    cout << "1. Determine distance and passengers between two airports.\n";
    cout << "2. Determine all traffic from one airport.\n\n";
    cout << "Your choice (0 - 2): ";
    
    cin>>input;
    cin.ignore(256, '\n');

    if (isdigit(input[0]))
    {
        choice = atoi(input);

        switch (choice)
        {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 2;
            default:
                cout << "Your choice must be between 0 and 2. ";
                cout << "Please try again.\n";
                return -1;   
        }//switch (input)

    }//if (isdigit(input[0])

    else // not a digit
    {
        cout << "Your choice must be between 0 and 2. Please try again.\n" ;
        return -1;
    }// else

} // getChoice()

void Vector::calcAirportTraffic()const
{
  char airport1[80];
  int index, tot_passengers = 0;

  
  cout << "\nPlease enter an airport abbreviation (XXX): ";
  cin>>airport1;

  index = findAirport(airport1);

  if (index >= 0)
  {

    for (int i = 0; i < count; i++)
    {

      if (i != index)
        tot_passengers += cityArray[index].calcAirportTraffic(&cityArray[i]);
    } // if not the same airport

  cout << "Total passengers: " << tot_passengers << endl;
  } // if airport exists
 
} // calcAirportTraffic()

void Vector::cmpCity()const
{

  char airport1[80], airport2[80];
  int index1, index2;
  cout << "\nPlease enter two airport abbreviations (XXX XXX): ";
  cin>>airport1>>airport2;
    
  index1 = findAirport(airport1);
  index2 = findAirport(airport2);
    
  if (index1 >= 0 && index2 >= 0)
    calcDistance(index1, index2);
} // cmpCity()

void Vector::cpyLocation(City city, string line, char *temp_state)
{
  char * temp = new char[line.size() + 1];
  copy(line.begin(), line.end(), temp);
  temp[line.size()] = '\0';
  city.readAirport(temp, temp_state);
      
  for (int i = 0; i < count; i++)
  {
    if (cityArray[i].isEqual(&city))
    {
      cityArray[i].copyLocation(&city);
      break;
    }  // if found a matching name

  } // for all cities

} // cpyLocation(City city, string line, char *temp_state)










