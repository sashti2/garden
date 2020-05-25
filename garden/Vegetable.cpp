//==============================================================
//    Vegetable.cpp
//==============================================================
// Sasha Ashtiani
// 4/26/17

#include "Vegetable.h"

Vegetable::Vegetable() { //Constructor

}

Vegetable::Vegetable(string color) { //Destructor

	m_color = color;
}

void Vegetable::die() { //vegetable dies

	SetIsAlive(false);
}

void Vegetable::harvest() { //harvest vegetable

	cout << "The vegetable has been harvested." << endl;
	die();
}

void Vegetable::tick() { //20% chance to get diseased, grows if not diseased

	int numR;

	SetIsDiseased(false); //set to "un" diseased

	if (GetIsAlive() == true) { //if not harvested
		numR = rand() % 100 + 1;

		if (numR <= 20) { //20% chance to become diseased
			SetIsDiseased(true);
		}

		else {
			if (GetSize() == 5) { //harvest if fully grown
				harvest();
			}

			else { //grow +1 if not fully grown
				SetSize(GetSize() + 1);
			}
		}
	}
}

ostream& Vegetable::operator<<(ostream& output) { //output operator

	if (GetIsAlive() == false) { //if harvested
		output << "Vegetable: Harvested" << endl;
	}

	else { //if not harvested
		output << "Vegetable (Alive : ";

		if (GetSize() != 5) { //if not harvestable
			output << "Not Harvestable : ";
		}

		else if (GetSize() == 5) { //if harvestable
			output << "Harvestable : ";
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