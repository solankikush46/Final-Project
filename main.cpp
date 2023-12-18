// Programmer 1: Kush Solanki, Lab Section:303
// Programmer 2: Abraham Yirga, Lab Section:306
// Date: 10-12-23
// Project: Final Project
// File: main.cpp
// Description: Contains the main function of the program.
#include "City.h"
#include "Jewel.h"
#include "Police.h"
#include "Robber.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main() {
  srand(100);// Sets the seed to 100.
  City city;// Initialize a variable city of the type City.

  Jewel jewels[30];// Initializes an array of size 30 and type Jewels.
  // Scattering the jewels all over the city.

  cout<<"The Jewels, robbers and the Policemen are on the grid now:\n"<<endl;
for(int i=0;i<30;i++)
  {
      int rand_x=rand()%8;
      int rand_y=rand()%8;

      while(city.grid[rand_x][rand_y]!=' ')
      {
            rand_x=rand()%8;
            rand_y=rand()%8;
      }
        jewels[i].pos_x=rand_x;
        jewels[i].pos_y=rand_y;
        jewels[i].value=(jewels[i].pos_x + jewels[i].pos_y +1)*(jewels[i].pos_x + jewels[i].pos_y +1);
      city.place_entity(jewels[i].pos_x,jewels[i].pos_y,'J');

  }

  Robber robbers[4];// Initializing a array of robbers of size 4;
  for (int i = 0; i < 4; i++) {
    robbers[i].robber_id = i + 1;
  }
  // Assigning 2 of the robbers to be greedy.
  robbers[0].greedy = true;
  robbers[2].greedy = true;

  Police polices[2];// Initializing a array of policemen of size 2;
  for (int i = 0; i < 2; i++) {
    polices[i].police_id = i + 1;
  }

  // Scattering the robbers and the policemen at random location on the city.
  for(int i=0;i<4;i++)
  {
      int rand_x=rand()%8;
      int rand_y=rand()%8;

      while(city.grid[rand_x][rand_y]!=' ')
      {
            rand_x=rand()%8;
            rand_y=rand()%8;
      }
        robbers[i].pos_x=rand_x;
        robbers[i].pos_y=rand_y;
        city.place_entity(robbers[i].pos_x,robbers[i].pos_y,'r');

  }

  for(int i=0;i<2;i++)
  {
      int rand_x=rand()%8;
      int rand_y=rand()%8;

      while(city.grid[rand_x][rand_y]!=' ')
      {
            rand_x=rand()%8;
            rand_y=rand()%8;
      }
        polices[i].pos_x=rand_x;
        polices[i].pos_y=rand_y;
      city.place_entity(polices[i].pos_x,polices[i].pos_y,'p');

  }
  city.display();
  cout<<"Lets the Chase begin....\n"<<endl;
    int i=0;
    // The chase only continues if at least one of the robber is still active.
  while(i<50 && (robbers[0].active==true || robbers[2].active==true || robbers[2].active==true || robbers[3].active==true))
  {
      cout<<"\nRound "<<i+1<<": "<<endl;
      for(int r=0;r<4;r++)
      {
          // checks if the current robber has been moving for 5 consecutive rounds without picking up any Jewels.
         if(robbers[r].robber_moves>=5 && robbers[r].immobilization<=2)
        {
            city.remove_entity(robbers[r].pos_x,robbers[r].pos_y);
            city.place_entity(robbers[r].pos_x,robbers[r].pos_y,'A');
            continue;
        }
        if(robbers[r].robber_moves<5)
            robbers[r].active=true;
        // If the robber is not active skip the current iteration.
          if(robbers[r].active==false)
            continue;
          else
          {
            // different Scenarios for the robber:
            int movement=rand()%8;
            while(isValid(robbers[r].pos_x,robbers[r].pos_y,movement)!=true)
            {
                movement=rand()%8;
            }
            city.remove_entity(robbers[r].pos_x,robbers[r].pos_y);
            robbers[r].moves(movement);// Moves the robber around.
            if(city.grid[robbers[r].pos_x][robbers[r].pos_y]=='J')
            {
                city.remove_entity(robbers[r].pos_x,robbers[r].pos_y);
                city.place_entity(robbers[r].pos_x,robbers[r].pos_y,'r');
                Jewel j;
                for(int k=0;k<30;k++)
                {
                    if(robbers[r].pos_x==jewels[k].pos_x && robbers[r].pos_y==jewels[k].pos_y)
                        j=jewels[k];
                }
                robbers[i].pickUpLoot(city,j);
                robbers[r].robber_moves=0;
            }
            else if(city.grid[robbers[r].pos_x][robbers[r].pos_y]=='p')
            {
              for(int p=0;p<2;p++)
              {
                 if(polices[p].pos_x==robbers[r].pos_x && polices[p].pos_y==robbers[r].pos_y)
                        polices[p].arrest(robbers[r]);
              }
            }
            else if(city.grid[robbers[r].pos_x][robbers[r].pos_y]=='r')
            {
                for(int j=0;j<4;j++)
                {
                    if(r==j)
                        continue;
                    if(robbers[r].pos_x==robbers[j].pos_x && robbers[r].pos_y==robbers[j].pos_y)
                    {
                        city.remove_entity(robbers[j].pos_x,robbers[j].pos_y);
                        city.place_entity(robbers[j].pos_x,robbers[j].pos_y,'R');

                        if(robbers[r].greedy==true)
                        {
                            for(int k=robbers[r].loot_count;k>=robbers[r].loot_count/2;k--)
                            {
                                robbers[r].p_loot-=robbers[r].bag[k];
                                place_jewels(robbers[r].bag[k],jewels,30,city);
                                robbers[r].bag[k]=0;
                            }
                            robbers[r].loot_count/=2;
                        }
                    }
                }
            }
            else
            {
                robbers[r].robber_moves++;
                if(robbers[r].robber_moves>5)
                    robbers[r].immobilization++;
                city.remove_entity(robbers[r].pos_x,robbers[r].pos_y);
                city.place_entity(robbers[i].pos_x,robbers[i].pos_y,'r');
            }
          }
      }

     for(int p=0;p<2;p++)
      {
          int movement=rand()%8;
          while(isValid(polices[p].pos_x,polices[p].pos_y,movement)!=true)
          {
              movement=rand()%8;
          }
          city.remove_entity(polices[p].pos_x,polices[p].pos_y);
          polices[p].moves(movement);// Moves the policeman.

          // Different scenarios for the policeman.
          if(city.grid[polices[p].pos_x][polices[p].pos_y]=='r')
          {
              for(int l=0;l<4;l++)
              {
                  if(polices[p].pos_x==robbers[l].pos_x && polices[p].pos_y==robbers[l].pos_y)
                    {polices[p].arrest(robbers[l]);}
              }
              city.place_entity(polices[p].pos_x,polices[p].pos_x,'p');

          }
          else if(city.grid[polices[p].pos_x][polices[p].pos_y]=='p')
          {
              int other_police;
              if(p==0)
                other_police=1;
              else
                other_police=0;

              polices[p].redistribution(polices[other_police]);
              while(polices[p].pos_x!=polices[other_police].pos_x || polices[p].pos_y!=polices[other_police].pos_y)
              {
                movement=rand()%8;
                while(isValid(polices[p].pos_x,polices[p].pos_y,movement)!=true)
                    {
                        movement=rand()%8;
                        city.remove_entity(polices[p].pos_x,polices[p].pos_y);
                        polices[p].moves(movement);
                    }
              }
          }
          else if(city.grid[polices[p].pos_x][polices[p].pos_y]=='J')
          {
              city.remove_entity(polices[p].pos_x,polices[p].pos_y);
              city.place_entity(polices[p].pos_x,polices[p].pos_y,'p');
          }
          else
          {
              city.remove_entity(polices[p].pos_x,polices[p].pos_y);
              city.place_entity(polices[p].pos_x,polices[p].pos_y,'p');
          }


      }
      // Displaying the current position of the robbers and the policemen after each round.
      city.display();
      cout<<endl;
      i++;

  }
    // Displaying the final summary of the chase.
    cout<<"Summary of the chase: "<<endl;
    if(i<49)
    {
        cout<<"The Police has won the chase "<<endl;
    }
    else
    {
        cout<<"The robbers wins the chase because maximum turns (50) have been reached "<<endl;
    }
    for(int i=0;i<2;i++)
    {
        cout<<"Police id: "<<polices[i].police_id<<endl;
        cout<<"\tConfiscated jewels amount: "<<polices[i].loot_consf<<"\n\tFinal number of robbers caught: "<<polices[i].rob_caught<<"\n"<<endl;
    }
    for(int i=0;i<4;i++)
    {
        if(robbers[i].greedy==true)
            cout<<"Greedy Robber id: "<<robbers[i].robber_id<<endl;
        else
            cout<<"Ordinary Robber id: "<<robbers[i].robber_id<<endl;

        cout<<"\tNo. of Jewels picked up: "<<robbers[i].loot_count<<endl;
        cout<<"\tTotal Jewel Worth: "<<robbers[i].p_loot<<endl;
        cout<<endl;
    }

    cout<<"End of the simulation.\nHope you had fun !!!!!!!!!"<<endl;


  return 0;
}
