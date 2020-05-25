//==============================================================
//    Plant.h
//==============================================================
// Sasha Ashtiani
// 4/26/17

#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Plant {
public:

	Plant();
	virtual ~Plant();

	//Accessors
	bool GetIsDiseased();
	bool GetIsAlive();
	int GetSize();

	//Mutators
	void SetSize(int size);
	void SetIsAlive(bool isAlive);
	void SetIsDiseased(bool isDiseased);

	//Virtual
	virtual void die() = 0;
	virtual void tick() = 0;
	virtual ostream& operator<<(ostream& os) = 0;

private:
	int m_size; //Current size
	bool m_isDiseased; //Can die
	bool m_isAlive; //Current status
};


#endif