//==============================================================
//    Vegetable.h
//==============================================================
// Sasha Ashtiani
// 4/26/17

#ifndef VEGETABLE_H
#define VEGETABLE_H

#include "Plant.h"

class Vegetable : public Plant {
public:

	Vegetable();
	Vegetable(string color);

	//Vegetable isAlive = false
	virtual void die();

	//Harvest the vegetables and calls die
	void harvest();

	//Post: A month passes in the vegetable's life
	//Vegetables are harvested when they have a size of 5
	//Vegetables grow every tick that they aren't diseased
	//Vegetables have a 20% chance of being diseased each month
	//Vegetables are "un" diseased at the beginning of each month
	virtual void tick();

	//Inserts into the stream the vegetable's information
	virtual ostream& operator<<(ostream&);

private:
	string m_color;
};

#endif