//==============================================================
//    driver.h
//==============================================================
// Sasha Ashtiani
// 4/26/17

#ifndef DRIVER_H
#define DRIVER_H

#include "Garden.h"

//Displays main menu
void menu();

//Manages user input and calls corresponding function
void manageMenu(Garden& garden);

//Asks user type of plant and # of plants
//Calls addPlant and then simulateTime
void singleGarden(Garden& garden, int quantity = 1);

//Asks user how many of each plant to plant
//Calls addPlant and then simulateTime
void manyGarden(Garden& garden);

//Displays the menu of different types of plants
void plantMenu();

//Asks user how many months to simulate
//Calls the garden.tick and passes # of months
void simulateTime(Garden& garden);

#endif