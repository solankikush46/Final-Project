// Programmer 1: Kush Solanki, Lab Section:303
// Programmer 2: Abraham Yirga, Lab Section:306
// Date: 10-12-23
// Project: Final Project
// File: implementation.cpp
// Description: Contains the function definitions of all the functions used in the program.
#include<iostream>
#include<string>
#include "Robber.h"
#include "Jewel.h"
#include "City.h"
#include "Police.h"

using namespace std;

// ******************* CITY FUNCTIONS ******************************* //

City::City()
{
  SIZE=7;

  for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
          this->grid[i][j] = ' ';
      }
  }
}

void City::place_entity(int x, int y, char entity)
{
  this->grid[x][y] = entity;
}
void City::remove_entity(int x, int y)
{
    this->grid[x][y] = ' ';
}
void City::display()
{
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cout <<" "<< this->grid[i][j] <<" ";
        }
        cout << "\n";
    }
}

void place_jewels(int value,Jewel jewels[],const int SIZE, City &city)
    {
        for(int i=0;i<SIZE;i++)
        {
            if(jewels[i].value==value)
            {
                city.place_entity(jewels[i].pos_x,jewels[i].pos_y,'J');
            }
        }
    }

// ******************* ROBBER FUNCTIONS ******************************* //

Robber::Robber()
{
    this->robber_id=0;
    this->greedy = false;
    this->active = true;
    this->loot_count = 0;
    this->p_loot=0;
}

void Robber::moves(int movement)
{
    // Updates the x position by changing the columns and updates the y position by changing the row.
        switch(movement)
          {
            case 0:
              this->pos_x-=1;
              this->pos_y-=1;
              break;

            case 1:
            this->pos_x-=1;
            break;

            case 2:
              this->pos_x-=1;
              this->pos_y+=1;
            break;

            case 3:
              this->pos_y-=1;
            break;

            case 4:
              this->pos_y+=1;
            break;

            case 5:
              this->pos_y-=1;
              this->pos_x+=1;
            break;

            case 6:
              this->pos_x+=1;
            break;

            case 7:
              this->pos_y+=1;
              this->pos_x+=1;
            break;

            default:
                break;
        }
        if(this->pos_x>6 || this->pos_y>6)
        {
            if(this->pos_x>6)
                this->pos_x=6;
            if(this->pos_y>6)
                this->pos_y=6;
        }
        if(this->pos_x<0 || this->pos_y<0)
        {
            if(this->pos_x<0)
                this->pos_x=0;
            if(this->pos_y<0)
                this->pos_y=0;
        }
}

bool isValid(int x, int y, int movement)
{
    bool valid=0;
    switch(movement)
    {
            case 0:
                x-=1;
                y-=1;
                break;

            case 1:
                x-=1;
                break;

            case 2:
                x-=1;
                y+=1;
                break;

            case 3:
                y-=1;
                break;

            case 4:
                y+=1;
                break;

            case 5:
                y-=1;
                x+=1;
                break;

            case 6:
                x+=1;
                break;

            case 7:
                y+=1;
                x+=1;
                break;

            default:
                break;
    }
    // returns true only if x and y are in the range of the grid.
    if((x<0 || x>7)||(y<0 || y>7))
    {
        cout<<movement<<" is Invalid"<<endl;
        return valid;
    }
    else
    {
        cout<<movement<<" is valid"<<endl;
        valid=1;
    }

    return valid;

}

void Robber::pickUpLoot(City &city, Jewel j)
{
    int static greedy_move=0;
  if(this->loot_count>=10)// returns if robber's bag is already full.
  {
      return;
  }
  else// Places the loot in the robbers bag and add the value to the personal loot.
  {
    this->bag[this->loot_count]= j.value;
    this->p_loot+=j.value;
    this->loot_count++;
    return;
  }
    // Checks if the robber is greedy and the loot added is an even number then the greedy robber moves again making sure that he doesn't move under this mechanism more than 3 times.
  if(this->greedy==true && greedy_move<3 && (j.value%2==0))
  {
      int movement=rand()%8;
      while(isValid(this->pos_x,this->pos_y,movement)!=true)
      {
          movement=rand()%8;
      }
      city.remove_entity(this->pos_x,this->pos_y);
      this->moves(movement);
      city.place_entity(this->pos_x,this->pos_y,'r');
      greedy_move++;
  }
  return;
}



//********************** POLICE FUNCTIONS ***************************//

void Police::arrest(Robber& r)
{
  // Makes the arrested robber inactive and his loot gets confiscated.
  r.active=false;
  r.loot_count=0;
  for(int i=0;i<r.bag_size;i++)
    r.bag[i]=0;
  this->rob_caught++;
  this->loot_consf+=r.p_loot;
  r.p_loot=0;
}

void Police::moves(int movement)
{
        switch(movement)
          {
            case 0:
              this->pos_x-=1;
              this->pos_y-=1;
              break;

            case 1:
            this->pos_x-=1;
            break;

            case 2:
              this->pos_x-=1;
              this->pos_y+=1;
            break;

            case 3:
              this->pos_y-=1;
            break;

            case 4:
              this->pos_y+=1;
            break;

            case 5:
              this->pos_y-=1;
              this->pos_x+=1;
            break;

            case 6:
              this->pos_x+=1;
            break;

            case 7:
              this->pos_y+=1;
              this->pos_x+=1;
            break;

            default:
                break;
        }
        if(this->pos_x>6 || this->pos_y>6)
        {
            if(this->pos_x>6)
                this->pos_x=6;
            if(this->pos_y>6)
                this->pos_y=6;
        }
        if(this->pos_x<0 || this->pos_y<0)
        {
            if(this->pos_x<0)
                this->pos_x=0;
            if(this->pos_y<0)
                this->pos_y=0;
        }
}
void Police::redistribution(Police &p)
{
    // If this police officer runs into another police officer than they redistribute the loot.
    int difference;
    if(p.loot_consf>this->loot_consf)
    {
        difference=p.loot_consf-this->loot_consf;
        p.loot_consf+=difference/2;
        this->loot_consf+=difference/2;
    }
    else
    {
        difference=this->loot_consf-p.loot_consf;
        p.loot_consf+=difference/2;
        this->loot_consf+=difference/2;
    }
}

