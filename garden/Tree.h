//==============================================================
//    Tree.h
//==============================================================
// Sasha Ashtiani
// 4/26/17

#ifndef TREE_H
#define TREE_H

#include "Plant.h"
#include "Fruit.h"
#include <vector>

class Tree : public Plant {
public:

	Tree();
	~Tree();

	//A tree can die after 120 months
	virtual void die();

	//Clears all fruit from the tree
	void ClearFruit();

	//A month passes
	virtual void tick();

	//Inserts into the ostream& the tree's information
	virtual ostream& operator<<(ostream&);

private:
	vector <Fruit*> m_fruit;
};

#endif