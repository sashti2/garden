//==============================================================
//    Plant.cpp
//==============================================================
// Sasha Ashtiani
// 4/26/17

#include "Plant.h"

Plant::Plant() { //Constructor

	m_size = 0;
	m_isAlive = true;
	m_isDiseased = false;
}

Plant::~Plant() { //Destructor

}

//Getters
bool Plant::GetIsDiseased() {

	return m_isDiseased;
}

bool Plant::GetIsAlive() {

	return m_isAlive;
}

int Plant::GetSize() {

	return m_size;
}

//Setters
void Plant::SetSize(int size) {

	m_size = size;
}

void Plant::SetIsAlive(bool isAlive) {

	m_isAlive = isAlive;
}

void Plant::SetIsDiseased(bool isDiseased) {

	m_isDiseased = isDiseased;
}