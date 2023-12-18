// Programmer 1: Kush Solanki, Lab Section:303
// Programmer 2: Abraham Yirga, Lab Section:306
// Date: 10-12-23
// Project: Final Project
// File: Jewel.h
// Description: Contains the definition of the class Jewel.
#ifndef JEWEL_H
#define JEWEL_H
#include "City.h"
#include <iostream>
#include <string>
using namespace std;

class Jewel
{
  public:
      int value;// A Variable to store the value of the Jewel.
      int pos_x,pos_y;// Variables to hold the x and y coordinates of the jewel
};
// Description: Places the jewel that were dropped back on the grid.
// Pre: The coordinates should be with the range of the map.
// Post: Updates the grid by putting the respective character on it.
void place_jewels(int value,Jewel jewels[],const int SIZE, City &city);
#endif // JEWEL_H
