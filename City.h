// Programmer 1: Kush Solanki, Lab Section:303
// Programmer 2: Abraham Yirga, Lab Section:306
// Date: 10-12-23
// Project: Final Project
// File: City.h
// Description: Contains the definition of the class City.
#ifndef CITY_H
#define CITY_H
#include <iostream>
#include <string>
using namespace std;

class City {
public:
  char grid[7][7];
  int SIZE;

  // Description: A default Constructor that initializes the grid of the city.
  // Pre: none
  // Post: Initializes the grid with every character ' '(blank space).

  City();
  // Description: Places the given character entity on the map on the given co-ordinates.
  // Pre: The coordinates should be with the range of the map.
  // Post: Updates the grid with the respective character on it.
  void place_entity(int x, int y, char entity);

  // Description: Removes the character entity on the map on the given co-ordinates.
  // Pre: The coordinates should be with the range of the map.
  // Post: Updates the grid by removing the respective character on it.
  void remove_entity(int x, int y);

  // Description: Prints the grid.
  // Pre: None
  // Post: Prints the grid.
  void display();
};

    // Description: Checks whether the movement is possible or not.
    // Pre: The location entered in the parameters should be within the range of the grid
    // Post: Returns whether the movement is possible or not.
    bool isValid(int x, int y, int movement);

#endif // CITY_H
