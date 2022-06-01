// InventoryBin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <iomanip>
using namespace std;

const int NUM_PARTS = 10;
struct PartsInventory
{
	int binID = 0;
	string partName;
	int partQuantity = 0;
};

//Function prototypes
int addParts(PartsInventory *, int);
int removeParts(PartsInventory *, int);
void showBins(PartsInventory *);
int selectedBin(PartsInventory *);
int mainMenu(PartsInventory *);


int main()
{
	PartsInventory Part[NUM_PARTS];
	Part[0] = { 1, "Valve", 10 };
	Part[1] = { 2, "Bearing", 5 };
	Part[2] = { 3, "Bushing", 15 };
	Part[3] = { 4, "Coupling", 21 };
	Part[4] = { 5, "Flange", 7 };
	Part[5] = { 6, "Gear", 5 };
	Part[6] = { 7, "Gear Housing", 5 };
	Part[7] = { 8, "Vacuum Gripper", 25 };
	Part[8] = { 9, "Cable", 18 };
	Part[9] = { 10, "Rod", 12 };

    while (true) { //begins looping structure, break to exit
		
		cout.fill('-');
		cout.width(80);
		cout << "\n\tInventory Bin" << endl;

		cout << "\n\tThis program will keep track of 10 bins of" << "\n\tparts.  The user will be able to view the" << "\n\tbins, add/remove parts to/from the bins, and" << "\n\texit the program when desired." << endl;
		//Begin by displaying the main menu
		mainMenu(Part);
		
		//Quit if user exits from mainMenu()
		break;

	};
	return(0);
}

int addParts(PartsInventory *s, int binNum) {
	int addNum;
	//increses a bin's part count by a user specified number
	cout << "\nHow many parts would you like to add?: ";
	cin >> addNum;
	s[binNum].partQuantity = s[binNum].partQuantity + addNum;
	cout << "\n" << addNum << " parts have been added, there are now " << s[binNum].partQuantity << " parts." << endl;
	return s[binNum].partQuantity;
};

int removeParts(PartsInventory *s, int binNum) {
	int subNum;
	//increses a bin's part count by a user specified number
	cout << "\nHow many parts would you like to remove?: ";
	cin >> subNum;
	if (subNum > s[binNum].partQuantity) { //check to see if there are enough parts in the bin
		cout << "There are not enough parts present at this time, please remove a lower number." << endl;
		removeParts(s, binNum);
	}
	else {
		s[binNum].partQuantity = s[binNum].partQuantity - subNum;
		cout << "\n" << subNum << " parts have been removed, there are now " << s[binNum].partQuantity << " parts." << endl;
		return s[binNum].partQuantity;
	};
};

void showBins(PartsInventory *s) {
	//Formatting bits and bobs
	const int idWidth = 12;
	const int partWidth = 20;
	const int quantWidth = 20;
	const char dataFill = ' ';
	
	//Header disply
	cout << "\n\t\tSelection: 1\n" << endl;
	cout << left << setw(idWidth) << setfill(dataFill) << "BIN ID #";
	cout << left << setw(partWidth) << setfill(dataFill) << "PART NAME";
	cout << left << setw(quantWidth) << setfill(dataFill) << "PART QUANTITY" << endl;
	//displays bins to the user using a for loop
	for (int i = 0; i < NUM_PARTS; i++) {
		cout << left << setw(idWidth) << setfill(dataFill) << s[i].binID;
		cout << left << setw(partWidth) << setfill(dataFill) << s[i].partName;
		cout << left << setw(quantWidth) << setfill(dataFill) << s[i].partQuantity << "\n";
	}
};

int selectedBin(PartsInventory *s) {
	//declarations
	int userInput;
	int binNumber;
	char modifierSelect;

	//Header disply
	cout << "\n\t\tSelection: 2" << endl;
	//Prompt user for bin #
	cout << "\n\tPlease enter bin #: ";
	cin >> userInput;
	binNumber = (userInput - 1);
	//Display name and number of parts currently in bin
	cout << "\n\tBin Name: " << s[binNumber].partName;
	cout << "\n\tNumber of Parts: " << s[binNumber].partQuantity;

	//Prompt user to add or remove parts
	cout << "\n\n(A)dd or (R)emove parts?: ";
	cin >> modifierSelect;
	if (modifierSelect == 'a' || modifierSelect == 'A') {
		addParts(s, binNumber);
	}
	else if (modifierSelect == 'r' || modifierSelect == 'R') {
		removeParts(s, binNumber);
	}
	else {
		cout << "\nInvalid selection";
		selectedBin(s); //restarts process if bad input
	};
	return s[binNumber].partName, s[binNumber].partQuantity;
};

int mainMenu(PartsInventory *s)
{
	while (true) {
		//declarations
		char input;
		//Header display
		cout << "\n\t\tMain Menu" << endl;
		//Menu with user selections below
		cout << "\n\tPlease make a selection:" << endl;
		cout << "\n1: View bins" << "\n2: Select a bin" << "\n3: Exit program" << endl;
		cout << "\nSelection: ";
		cin >> input;
		//get user input and assign to variable
		if (input == '1') {
			showBins(s);
		}
		else if (input == '2') {
			selectedBin(s);
		}
		else if (input == '3') {
			return(0);
		}
		else {
			cout << "Invalid selection, please restart and input 1, 2, or 3" << endl;
			mainMenu(s);
		}
	}
};