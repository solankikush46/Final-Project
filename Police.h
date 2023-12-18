// Programmer 1: Kush Solanki, Lab Section:303
// Programmer 2: Abraham Yirga, Lab Section:306
// Date: 10-12-23
// Project: Final Project
// File: Police.h
// Description: Contains the definition of the class Police.
#ifndef POLICE_H
#define POLICE_H
#include "Robber.h"
#include <iostream>
#include <string>
using namespace std;

class Police {
public:
  int police_id;// Variable to store the police id.
  int pos_x, pos_y;// variables to store the co-ordinates of the polices
  int rob_caught;// Variable to keep track of the number of robbers caught
  int loot_consf;// variable to keep track of the loot confiscated.

  Police() {
    police_id = 0;
    this->rob_caught = 0;
    this->loot_consf = 0;
  }

  void arrest(Robber& r);

  void moves(int movement);

  void redistribution(Police &p);
};

#endif
