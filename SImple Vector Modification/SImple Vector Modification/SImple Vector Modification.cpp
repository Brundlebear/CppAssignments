// SImple Vector Modification.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include "SimpleVector.h"

using namespace std;

int main()
{
    bool repeat = true;

     while (repeat) { //Begins looping structure
        string looper = "a";
       
        int vectorSize;
        int pushInt;
        double pushDouble;


        cout << "\nEnter number of elements to be put in a vector (between 2 and 20): ";
        cin >> vectorSize;
        cout << "\n A vector of integers will be created" << endl;
        SimpleVector<int> intVector(vectorSize); //create a vector using the simpleVector class template


        cout << "\nVector created, the contents of the array are:\n";
        for (int count = 0; count < vectorSize; count++) {
            cout << " " << intVector.getElementAt(count);
        };
        cout << "\nEnter a whole number to insert at the end of the vector: ";
        cin >> pushInt;

        cout << "\nCalling push_back function";
        intVector.push_back(pushInt);
        cout << "\nThe new vector is:\n";
        for (int count = 0; count < vectorSize + 1; count++) {
            cout << " " << intVector.getElementAt(count);
        };

        cout << "\n\n Calling pop_back function to remove the last added value";
        intVector.pop_back();
        cout << "\nThe new vector is:\n";
        for (int count = 0; count < vectorSize; count++) {
            cout << " " << intVector.getElementAt(count);
        };

        cout << "\n\nThe exercise will now be repeated with a decimal vector.";
        cout << "\nEnter number of elements to be put in a vector (between 2 and 20): ";
        cin >> vectorSize;
        cout << "\n A vector of integers will be created" << endl;
        SimpleVector<double> doubleVector(vectorSize); //create a vector using the simpleVector class template


        cout << "\nVector created, the contents of the array are:\n";
        for (int count = 0; count < vectorSize; count++) {
            cout << " " << doubleVector.getElementAt(count);
        };
        cout << "\nEnter a decimal number to insert at the end of the vector: ";
        cin >> pushDouble;

        cout << "\nCalling push_back function";
        doubleVector.push_back(pushDouble);
        cout << "\nThe new vector is:\n";
        for (int count = 0; count < vectorSize + 1; count++) {
            cout << " " << doubleVector.getElementAt(count);
        };

        cout << "\n\n Calling pop_back function to remove the last added value";
        doubleVector.pop_back();
        cout << "\nThe new vector is:\n";
        for (int count = 0; count < vectorSize; count++) {
            cout << " " << doubleVector.getElementAt(count);
        };
        cout << endl;

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
