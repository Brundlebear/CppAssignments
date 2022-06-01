
#include "IDList.h"
#include "WageList.h"
#include "HoursList.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main()
{
    bool repeat = true;

    vector<int> hours;
    vector<double> payRate;
    int const NUM_EMPLOYEES = 999999; //set number of employees
    int empID, empHours = 0;
    double empPayRate = 0;

    IDList EmployeeIDList;
    HoursList EmployeeHoursList;
    WageList  EmployeePayRateList;
    
    while (repeat == true) { //beginning of loop
        string looper = "a";
        string yesNo = "y";

        while (yesNo == "y" || yesNo == "Y" && yesNo != "n" && yesNo != "N") {
            cout << "\nEnter an employee ID number(0-999999): ";
            cin >> empID;
            EmployeeIDList.appendNode(empID);
            cout << "\nWould you like to enter another employee? (y/n):";
            cin >> yesNo;
            while (yesNo != "y" && yesNo != "n" && yesNo != "Y" && yesNo != "N")
            {
                cout << "\nPlease choose a valid input" << endl;
                cout << "Would you like to enter another employee? (y/n):";
                cin >> yesNo;
            }
            cout << "\n\nEnter the following information for employee #" << empID;
            cout << "\n\t\tHours worked: ";
            cin >> empHours;
            EmployeeHoursList.appendNode(empHours);
            //EmployeeHours Hours(empHours);
            //HoursList.appendNode(Hours);
            cout << "\n\t\tPay rate: $";
            cin >> empPayRate;
            EmployeePayRateList.appendNode(empPayRate);
            //EmployeePayRate Wage(empPayRate);
            //PayRateList.appendNode(Wage);
        }

        cout << "\n\n--------------------------------" << endl;
        cout << "Employee                   Wages";
        cout << "\n--------------------------------" << endl;
        //cout << "\nEmployee #" << empID << "\t$ " << empPayRate * empHours << endl;
        EmployeeIDList.displayList();
        EmployeeHoursList.displayList();
        EmployeePayRateList.displayList();

        //IDList.displayList();
        
        //Looping inputs to determine if program is to be run again
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

