//==============================================================
//    Flower.h
//==============================================================
// Sasha Ashtiani
// 4/26/17

#ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h"

class Flower : public Plant {
public:

	Flower();
	Flower(int numPetals, string color);

	//Sets isAlive to false and numPetals to 0
	virtual void die();

	//A month passes
	virtual void tick();

	//Inserts the stream information about the flower
	virtual ostream& operator<<(ostream&);

protected:
	int m_numPetals;
	string m_color;
	bool m_isFlowering;
};

#endif