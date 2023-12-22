# Final-Project-repository
 Final-Project

 - Had to create a real life simulation with a scenario of a Jewel-Hiest
 - Several Entities like robbes, policemen and Jewels were to placed on the city which was a 7x7 grid.

 - The robbers and the policemen go around the city to pick up jewels with different Scenarios being encountered:
     - If a robber get caught by a policemen the robber becomes in-active
     - If a greedy robber runs into another greedy robber than the roober drops half of its jewels and those jewels would be redistributed to their original position.
     - If a robber moves to a position where there is a jewel than he will get the loot, equal to the sum of the coordinates squared, added to his bag.
     - If the policemen enconters a robber than he arrests him making the robber inactive and he will confisticate all the loot that the robber has.
     - If the policemen moves to a position where there is a jewel than he simply remove the jewel from that position.

 - If the robbers all together get a total loot of $2023 than the simulation end and the robbers will be the winners
 - If the simulation go for all 50 rounds and there are still one or more robbers active than the robbers win.
 - If all the robbers get caught before any of the 2 conditions become true than the police wins.

 - After the simulations end, a detailed summary of each of the character in the simulation will be displayed.
