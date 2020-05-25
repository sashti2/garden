//==============================================================
//    Flower.cpp
//==============================================================
// Sasha Ashtiani
// 4/26/17

#include "Flower.h"

Flower::Flower() { //Default constructor

	m_isFlowering = false;
}

Flower::Flower(int numPetals, string color) { //Set petals and color

	m_numPetals = numPetals;
	m_color = color;
}

void Flower::die() { //flower dies

	SetIsAlive(false);
	m_numPetals = 0;
}

void Flower::tick() { //20% to become diseased, grows if not diseased

	int numR;

	SetIsDiseased(false); //set to "un" diseased

	if (GetIsAlive() == true) { //if alive
		numR = rand() % 100 + 1;

		if (numR <= 20) { //20% chance to become diseased
			SetIsDiseased(true);
		}

		else {
			if ((GetSize() == 3) && (m_numPetals == 0)) { //max size and no petals
				m_numPetals += 1;
			}

			else if (m_isFlowering == true) { //if petals dropped
				die();
			}

			else if ((GetSize() == 3) && (m_numPetals > 0)) { //max size and petals
				m_isFlowering = true;
			}

			else { //grow +1 if not fully grown
				SetSize(GetSize() + 1);
			}
		}
	}
}

ostream& Flower::operator<<(ostream& output) { //output operator

	if (GetIsAlive() == false) { //if dead
		output << "Flower(Dead)" << endl;
	}

	else { //if not dead and not flowering

		if (m_isFlowering == true) { //if flowering
			output << "The flower drops its petals." << endl;
		}

		output << "Flower (";

		if (GetSize() <= 1) { //if seedling
			output << "Seedling: Alive : ";
		}

		else if (GetSize() == 2) { //if medium-sized
			output << "Medium-sized: Alive : ";
		}

		else if (GetSize() == 3) { //if fully mature
			output << "Fully Mature: Alive : ";
		}

		if (m_isFlowering == false) { //if not flowering
			output << "Not Flowering : ";
		}

		else if (m_isFlowering == true) { //if flowering
			output << "Flowering : ";
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