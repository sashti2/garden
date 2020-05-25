//==============================================================
//    Tree.cpp
//==============================================================
// Sasha Ashtiani
// 4/26/17

#include "Tree.h"

Tree::Tree() { //Constructor

	vector <Fruit*> m_fruit;
}

Tree::~Tree() { //Destructor

	int size = m_fruit.size(); //get vector size
	for (int i = 0; i < size; i++) {
		delete m_fruit[i]; //delete
		m_fruit[i] = NULL; //set to NULL
	}
}

void Tree::die() { //Tree dies

	SetIsAlive(false);
}

void Tree::ClearFruit() { //Clear fruit

	m_fruit.clear();
}

void Tree::tick() { //20% to become diseased, grows if not diseased

	int numR;

	SetIsDiseased(false); //set to "un" diseased

	if (GetIsAlive() == true) { //if alive
		numR = rand() % 100 + 1;

		if (numR <= 20) { //20% chance to become diseased
			SetIsDiseased(true);
		}

		else {
			if ((GetSize() >= 36)) { //if tree is mature
				Fruit* fruit = new Fruit;
				m_fruit.push_back(fruit);
			}

			else { //if tree has not reached mature
				SetSize((GetSize() + 1));
			}
		}
	}
}

ostream& Tree::operator<<(ostream& output) { //output operator

	if (GetIsAlive() == false) { //if dead
		output << "The tree has died." << endl;
	}

	else { //if not dead
		output << "Tree (";

		if (GetSize() < 12) { //seedling
			output << "Seedling : Alive: ";
		}

		else if (GetSize() < 24) { //sapling
			output << "Sapling : Alive: ";
		}

		else if (GetSize() < 36) { //pole
			output << "Pole : Alive: ";
		}

		else if (GetSize() > 36) { //mature
			output << "Mature : Alive: ";
		}

		if (m_fruit.size() > 0) { //has fruit
			output << "Fruiting : ";
		}

		else if (m_fruit.size() == 0) { //has no fruit
			output << "Not Fruiting : ";
		}

		if (GetIsDiseased() == false) { //if not diseased
			output << "Not Diseased)" << endl;
		}

		else if (GetIsDiseased() == true) { //if diseased
			output << "Diseased)" << endl;
		}
	}

	return output;
}