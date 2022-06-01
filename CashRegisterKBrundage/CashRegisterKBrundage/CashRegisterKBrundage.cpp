// CashRegisterKBrundage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include "InventoryItems.h"
#include "CashRegister.h"

using namespace std;


int main()
{
    const int NUM_ITEMS = 5;
    InventoryItem inventory[NUM_ITEMS] = {
        InventoryItem("Adjustable Wrench", 6.95, 6),
        InventoryItem("Screwdriver", 2.95, 4),
        InventoryItem("Pliers", 5.95, 23),
        InventoryItem("Ratchet", 8.95, 10),
        InventoryItem("Socket Wrench", 16.95, 8)
    };

    char loopCheck = 'y';
    while (loopCheck == 'y') {

        int idNum = -1;
        int purchaseQty = -1;

        cout << setw(5) << "\nID#";
        cout << setw(18) << "INVENTORY ITEM";
        cout << setw(16) << "QTY ON HAND" << endl;
        cout << "-----------------------------------------------------" << endl;

        for (int i = 0; i < NUM_ITEMS; i++) {
            cout << setw(5) << i + 1;
            cout << setw(18) << inventory[i].getDescription();
            cout << setw(16) << inventory[i].getUnits() << endl;
        }

        cout << "\nWhich item above is being purchased? ";
        cin >> idNum;
        while (idNum <= 0 || idNum > NUM_ITEMS) {
            cout << "\nInvalid value, please input a valid ID# ";
            cin >> idNum;
        }
        cout << "\n\nHow many units? ";
        cin >> purchaseQty;
        while (purchaseQty < 0 || purchaseQty > inventory[idNum-1].getUnits()) {
            cout << "\nInvalid value, please input a valid quantity ";
            cin >> purchaseQty;
        }
        static_cast<double>(purchaseQty);

        cout << fixed << showpoint << setprecision(2);

        CashRegister purchase = CashRegister(inventory[idNum - 1].getCost(), purchaseQty);
        cout << setw(12) << "Subtotal: ";
        cout << "$" <<  purchase.getSubtotal() << endl;
        cout << setw(12) << "Sales Tax: ";
        cout << "$" << purchase.getTax() << endl;
        cout << setw(12) << "Total: ";
        cout << "$" << purchase.getTotal() << endl;

        inventory[idNum - 1].setUnits(inventory[idNum-1].getUnits() - purchaseQty);
        

        cout << "\nDo you want to purchase another item? (Y/N) ";
        cin >> loopCheck;
        while (loopCheck != 'Y' && loopCheck != 'y' && loopCheck != 'N' && loopCheck != 'n') {
            cout << "\nPlease input 'y' or 'n'";
            cin >> loopCheck;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
