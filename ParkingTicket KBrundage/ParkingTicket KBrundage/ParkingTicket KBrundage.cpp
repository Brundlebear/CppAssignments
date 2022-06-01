// ParkingTicket KBrundage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"
#include <iostream>
#include <string>

using namespace std;

ParkedCar Car;
ParkingMeter Meter;
PoliceOfficer Cop;

int main()
{   

    cout << "This program allows a user to enter information about a vehicle" << endl << "and a police officer, it will then simulate a parking ticket." << endl;

    bool repeat = true;
    string str;
    int val;

    while(repeat){ //Begins looping structure
        string looper = "a";

        cout << "\nEnter car make: "; //Entry prompts for vehicle information
        cin >> str;
        Car.setMake(str);
        cout << "\nEnter car model: ";
        cin >> str;
        Car.setModel(str);
        cout << "\nEnter car color: ";
        cin >> str;
        Car.setColor(str);
        cout << "\nEnter license plate: ";
        cin >> str;
        Car.setPlate(str);
        cout << "\nEnter number of minutes car has been parked: ";
        cin >> val;
        Car.setTimeParked(val);

        cout << "\nEnter number of minutes purchased: ";  //Entry prompt for Parking Meter
        cin >> val;
        Meter.setTime(val);

        cout << "\nEnter officer name: ";  //Entries for officer information
        cin >> str;
        Cop.setName(str);
        cout << "\nEnter officer badge number: ";
        cin >> str;
        Cop.setBadge(str);

        Cop.patrol(Car, Meter);


            


        //Looping structure input
        while (looper != "y" && looper != "n" && looper != "Y" && looper != "N") {
            cout << "\nWould you like to repeat the program? (y/n)";
            cin >> looper;
            if (looper == "n" || looper == "N") {
                repeat = false;
            }
            else if (looper != "y" && looper != "Y") {
                cout << "\nPlease make a valid selection" << endl;
            }
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
