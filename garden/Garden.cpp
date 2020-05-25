//==============================================================
//    Garden.cpp
//==============================================================
// Sasha Ashtiani
// 4/26/17

#include "Garden.h"

Garden::Garden() { //Constructor

	vector <Plant*> m_garden;
	m_gardenSize = 0;
	m_month = 0;
}

Garden::~Garden() { //Destructor

	int size = m_garden.size(); //get size
	for (int i = 0; i < size; i++) {
		delete m_garden[i]; //delete
		m_garden[i] = NULL; //set to NULL
	}
}

void Garden::addPlant(int type, int quantity) { //add plants to vector

	for (int i = 0; i < quantity; i++) {

		if (type == 1) { //Flower
			Flower* flower = new Flower(0, "Red");
			m_garden.push_back(flower);
		}

		else if (type == 2) { //Vegetable
			Vegetable* veggie = new Vegetable;
			m_garden.push_back(veggie);
		}

		else { //Tree
			Tree* tree = new Tree;
			m_garden.push_back(tree);
		}
	}
}

void Garden::tick(int months) {

	for (int i = 0; i < months; i++) {
		cout << "MONTH: " << i + 1 << endl;

		for (int j = 0; j < getSize(); j++) { //for every plant in garden
			cout << j + 1 << ": ";

			m_garden.at(j)->tick();
			*(m_garden.at(j)) << cout;

			cout << endl;
		}

		m_month += 1;
	}
}

void Garden::tick() {

	for (int i = 0; i < getSize(); i++) {
		m_garden.at(i)->tick();
		*(m_garden.at(i)) << cout;
	}
}

//Getters
int Garden::getSize() {

	m_gardenSize = m_garden.size();
	return m_gardenSize;
}

int Garden::getMonths() {

	return m_month;
}