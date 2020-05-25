//==============================================================
//    Fruit.h
//==============================================================
// Sasha Ashtiani
// 4/26/17

#ifndef FRUIT_H
#define FRUIT_H

#include <string>

using namespace std;

class Fruit {
public:

	Fruit();

	string GetColor();

private:
	string m_color;
};

#endif