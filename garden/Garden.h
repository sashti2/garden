//==============================================================
//    Garden.h
//==============================================================
// Sasha Ashtiani
// 4/26/17

#ifndef GARDEN_H
#define GARDEN_H

#include "Plant.h"
#include "Vegetable.h"
#include "Tree.h"
#include "Flower.h"

class Garden {
public:

	Garden();
	~Garden();

	//Plant added to garden vector
	void addPlant(int type, int quantity);

	//Calls tick for each item in the garden for # of months
	void tick(int);

	//Calls tick for each item in the garden for one month
	void tick();

	//Returns how many items are in the garden
	int getSize();

	//Returns how many months have passed since start of simulation
	int getMonths();

private:
	vector <Plant*> m_garden;
	int m_gardenSize;
	int m_month;
};

#endif