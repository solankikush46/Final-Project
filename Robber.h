// Programmer 1: Kush Solanki, Lab Section:303
// Programmer 2: Abraham Yirga, Lab Section:306
// Date: 10-12-23
// Project: Final Project
// File: Robber.h
// Description: Contains the definition of the class Robber
#ifndef ROBBER_H
#define ROBBER_H
#include "City.h"
#include "Jewel.h"
#include <iostream>
#include <string>
using namespace std;

class Robber {
public:
  int robber_id;// variable to store the robber id.
  int pos_x, pos_y;// variables to store the co-ordinates of the robber's position.
  int bag_size=10;// Variable to store the bag size of the robber
  int bag[10];// Array to keep track of the worth of each jewel in the bag.
  static int total_loot;// A variable to keep track of the total loot confiscated by the robber.
  int p_loot;// A variable to keep track of the robber's personal loot.
  int loot_count;// a variable to keep track of how many jewel the robber has in his bag.
  bool active, greedy;// variable to store whether the robber is active or greedy
  int robber_moves=0;// A variable to keep track of how many moves the robber has been moving without picking up any jewels.
  int immobilization=0;// A variable to keep track of for how many moves the robber has been immobilized.

  // Description: A default constructor that initializes the variables for each object created.
  // Pre: None
  // Post: Initializes the variables for each object created.
  Robber();

  // Description: pickup the loot at the particular location and puts it in the robbers bag.
  // Pre: none
  // Post: Updates the robbers current loot and the city map.
  void pickUpLoot(City &city, Jewel j);

  // Description: Moves the robber according to the movement number.
  // Pre: Movement should be within the range of 0-7
  // Post: Updates the robber's current position.
  void moves(int movement);
};



#endif // ROBBER_H

