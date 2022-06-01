// InventoryProgramKBrundage.cpp : This file contains the 'main' function. Program execution begins and ends there.

// This program will allow the user to make data entries where they will be prompted for the item description, quantity, wholesale cost, retail cost, and date added.  The user will be able to add new records, display records, and change records

#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

//Declare struct for the record
const int DESC_SIZE = 40; //Defines maximum size for item description
const int DATE_SIZE = 10;
struct InventoryItem {
    int idNum = 0;
    char itemDescription[DESC_SIZE];
    int quantity = 0;
    double wholesaleCost = 0;
    double retailPrice = 0;
    string dateAdded = "13/32/9999";
};

// Function Prototypes
void mainMenu();
void inventoryView();
void addItem();
void editItem();
int isValidDate(string date);



int main()
{
    fstream inventory;
    inventory.open("inventory.dat", ios::app | ios::binary);

    mainMenu();


}

void mainMenu() {
    int selection = 0;

    while (true) {

        cout << "Welcome, what would you like to do?\n\n1) View/Edit existing inventory items\n2) Add a new item\n3) Exit the program\n\n\tEnter your selection: ";
        cin >> selection;
        if (selection == 1) {
            inventoryView();
        }
        else if (selection == 2) {
            addItem();
        }
        else if (selection == 3) {
            break;
        }
        else {
            cout << "\n\tInvalid entry, please input 1, 2, or 3\n\n";
        }
    };
    ;
};

void inventoryView() {

    //char loopInput ='y';
    long count = 0; //Establishes a reference for the items when the user wants to edit an item
    int selection = 0;
    fstream inventory;
    InventoryItem record;

        cout << "\nHere is the current data:\n";

        string line;
        inventory.open("inventory.dat", ios::in | ios::out | ios::binary); //opens inventory.txt
        inventory.seekg(ios::beg);
        inventory.read(reinterpret_cast<char*>(&record), sizeof(record));

        while (!inventory.eof()) {
            count += 1;
            record.idNum = count;
            cout << "Item number: " << record.idNum << endl;
            cout << "Description: " << record.itemDescription << endl;
            cout << "Quantity: " << record.quantity << endl;
            cout << "Wholesale cost: " << record.wholesaleCost << endl;
            cout << "Retail price : " << record.retailPrice << endl;
            cout << "Date added: " << record.dateAdded << "\n" << endl;
            inventory.read(reinterpret_cast<char*>(&record), sizeof(record));
        }
        
        inventory.close();

        
        while (selection != 1 && selection != 2) {
            cout << "\n1)Edit Data\n2)Return to main menu\n\n\tPlease make a selection: ";
            cin >> selection;
            if (selection == 1) {
                editItem();
            }
            else if (selection == 2) {
                main();
            } else {
                cout << "\nPlease make a valid selection\n";
            }
        }

};

void addItem() {
    //Items will be assigned an ID# which can be referenced later for editing
    InventoryItem record;
    string date;

    fstream inventory("inventory.dat", ios::in | ios::out | ios::binary);

    cout << "\nInput the following data:" << endl;
    cout << "Description (30 characters max): ";
    cin.ignore();
    cin.getline(record.itemDescription, DESC_SIZE);
    record.quantity = -1;
    while (record.quantity < 0) {
        cout << "Quantity: ";
        cin >> record.quantity;
    }
    record.wholesaleCost = -1;
    while (record.wholesaleCost < 0) {
        cout << "Wholesale cost: ";
        cin >> record.wholesaleCost;
    }
    record.retailPrice = -1;
    while (record.retailPrice < 0) {
        cout << "Retail price: ";
        cin >> record.retailPrice;
    }
    string dateCheck = "13/32/9999";
    while (!isValidDate(dateCheck)) {
        cout << "Date added (mm/dd/yyyy): ";
        cin >> dateCheck;
        record.dateAdded = dateCheck;
    };
    

    inventory.seekp(0, ios::end);
    inventory.write(reinterpret_cast<char*>(&record), sizeof(record));

    inventory.close();
};

void editItem() {
    //Items will be selected via user inputted ID#
    InventoryItem record;
    long recordNum;

    fstream inventory("inventory.dat", ios::in | ios::out | ios::binary);
    cout << "\nWhich item would you like to edit? ";
    cin >> recordNum;

    inventory.seekg((recordNum) * sizeof(record), ios::beg);
    inventory.read(reinterpret_cast<char*>(&record), sizeof(record));

    cout << "\nThese are the current contents: " << endl;
    cout << "Description: " << record.itemDescription<< endl;
    cout << "Quantity: " << record.quantity << endl;
    cout << "Wholesale cost: " << record.wholesaleCost << endl;
    cout << "Retail price: " << record.retailPrice << endl;
    cout << "Date added: " << record.dateAdded << endl;

    cout << "\nPlease enter the new data:" << endl;
    cout << "Description (30 characters max): ";
    cin.ignore();
    cin.getline(record.itemDescription, DESC_SIZE);
    record.quantity = -1;
    while (record.quantity < 0) {
        cout << "Quantity: ";
        cin >> record.quantity;
    }
    record.wholesaleCost = -1;
    while (record.wholesaleCost < 0) {
        cout << "Wholesale cost: ";
        cin >> record.wholesaleCost;
    }
    record.retailPrice = -1;
    while (record.retailPrice < 0) {
        cout << "Retail price: ";
        cin >> record.retailPrice;
    }
    string dateCheck = "13/32/9999";
    while (!isValidDate(dateCheck)) {
        cout << "Date added (mm/dd/yyyy): ";
        cin >> dateCheck;
        record.dateAdded = dateCheck;
    };

    inventory.seekp((recordNum) * sizeof(record), ios::beg);
    inventory.write(reinterpret_cast<char*>(&record), sizeof(record));

    inventory.close();

    main();
};

int isValidDate(string date) {
    //cout << date.length() <<endl;
    if (date.length() != 10) {
        return false;
    }
    string yearStr(date, 6, 4);
    string dayStr(date, 3, 2);
    string monthStr (date, 0 , 2);
    int month = stoi(monthStr);
    int day = stoi(dayStr);
    int year = stoi(yearStr);
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > 31 || (month == 2 && day > 28 && year % 4 != 0) || (month == 2 && day > 29 && year % 4 == 0)) {
        return false;
    }
    if (year < 1900 || year > 2022) {
        return false;
    }
    else {
        return true;
    }

};
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
