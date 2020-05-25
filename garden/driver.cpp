//==============================================================
//    driver.cpp
//==============================================================
// Sasha Ashtiani
// 4/26/17

#include "driver.h"

//constants
const int FLOWER = 1;
const int VEGGIE = 2;
const int TREE = 3;

int main() {

	srand(time(NULL)); //seed RNG
	cout << "Welcome to the Garden" << endl; //intro
	Garden garden; //create object
	manageMenu(garden); //menu
	return 0;
}

void menu() { //main menu

	cout << "1. Plant Single Item" << endl
		<< "2. Plant Many of the Same Item" << endl
		<< "3. Plant a Full Garden" << endl
		<< "4. Exit" << endl
		<< "Enter 1-4:" << endl;
}

void manageMenu(Garden& garden) {

	int choice = -1; //user choice initialize
	while (choice != 4) {

		menu();
		cin >> choice; //obtain input

		if (choice == 1) { //plant single item
			singleGarden(garden, choice);
			choice = 4; //choice set for exit
		}

		else if (choice == 2) { //plant many of same item
			singleGarden(garden, choice);
			choice = 4; //choice set for exit
		}

		else if (choice == 3) { //plant a full garden
			manyGarden(garden);
			choice = 4; //choice set for exit
		}

		else { //if invalid input
			cout << "Sorry, please choose again." << endl << endl;
		}
	}
}

void singleGarden(Garden& garden, int num) {

	int choice = -1; //user choice initialize
	while ((choice >= 1) || (choice <= 3)) {

		plantMenu();
		cin >> choice;

		if ((choice < 1) || (choice > 3)) { //if invalid input
			cout << "Sorry, please choose again." << endl << endl;
		}

		else {

			if (num == 2) { //plant many of the same item
				int num2 = -1; //user choice2 initialize
				while (num2 < 0) {
					cout << "How many would you like to plant?" << endl;
					cin >> num2;

					if (num2 < 0) { //if invalid input
						cout << "Sorry, please choose again." << endl << endl;
					}
				}
				garden.addPlant(choice, num2);
				simulateTime(garden);
				return;
			}

			else { //plant single item
				garden.addPlant(choice, num);
				simulateTime(garden);
				return;
			}
		}
	}
}

void manyGarden(Garden& garden) {

	int numFlower = -1, numVeggie = -1, numTree = -1; //user choice initialize

	while (numFlower < 0) {
		cout << "How many flowers would you like to plant?" << endl;
		cin >> numFlower;

		if (numFlower < 0) { //if invalid input
			cout << "Sorry, please choose again." << endl << endl;
		}

		else {
			garden.addPlant(FLOWER, numFlower);
		}
	}

	while (numVeggie < 0) {
		cout << "How many vegetables would you like to plant?" << endl;
		cin >> numVeggie;

		if (numVeggie < 0) { //if invalid input
			cout << "Sorry, please choose again." << endl << endl;
		}

		else {
			garden.addPlant(VEGGIE, numVeggie);
		}
	}

	while (numTree < 0) {
		cout << "How many trees would you like to plant?" << endl;
		cin >> numTree;

		if (numTree < 0) { //if invalid input
			cout << "Sorry, please choose again." << endl << endl;
		}

		else {
			garden.addPlant(TREE, numTree);
		}
	}

	simulateTime(garden);
}

void plantMenu() {

	cout << "What would you like to plant?" << endl
		<< "1. Flower" << endl
		<< "2. Vegetable" << endl
		<< "3. Tree" << endl
		<< "Enter 1-3" << endl;
}

void simulateTime(Garden& garden) {

	int numMonths = -1; //user input initialize

	while (numMonths < 1) {
		cout << "How many months would you like to simulate?" << endl;
		cin >> numMonths;
	}

	garden.tick(numMonths);
}