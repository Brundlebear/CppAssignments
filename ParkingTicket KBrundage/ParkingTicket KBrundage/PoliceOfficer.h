#pragma once

#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include <string>
#include <iostream>

using namespace std;

#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H

class PoliceOfficer {

private:
	string badgeNum;
	string officerName;

public:
	//Constructors
	PoliceOfficer() {
		badgeNum = " ";
		officerName = " ";
	}

	PoliceOfficer(string b, string n) {
		badgeNum = b;
		officerName = n;
	}

	//Mutators
	void setBadge(string b) {
		badgeNum = b;
	}
	void setName(string n) {
		officerName = n;
	}

	//Accessors
	string getBadge() const {
		return badgeNum;
	}
	string getName() const {
		return officerName;
	}

	void print() {
		cout << "\n\nOfficer Information: " << endl;
		cout << "\tName: " << PoliceOfficer(badgeNum, officerName).getName() << endl; 
		cout << "\tBadge Number: " << PoliceOfficer(badgeNum, officerName).getBadge() << endl;
	}

	// Patrol Function
	void patrol(ParkedCar C, ParkingMeter M) {
		if (C.getTimeParked() > M.getTime()) {
			PoliceOfficer(badgeNum, officerName).print();
			ParkingTicket(C, M).print();
		}
		else {
			cout << "\n\tNo Violation";
		}
	}
};


#endif // !POLICEOFFICER_H
