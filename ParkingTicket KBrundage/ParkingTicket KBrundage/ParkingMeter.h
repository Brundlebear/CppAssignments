#pragma once

#include <string>

using namespace std;

#ifndef PARKINGMETER_H
#define PARKINGMETER_H

class ParkingMeter {

private:
	// Class Characteristics
	int timePurchased;
public:
	ParkingMeter();

	ParkingMeter(int);
	// Function to set Characteristics
	void setTime(int);
	// Function to get characteristics
	int getTime() const;
};

// Constructor
ParkingMeter::ParkingMeter() {
	timePurchased = 0;
}

ParkingMeter::ParkingMeter(int t) {
	timePurchased = t;
}


// Mutators
void ParkingMeter::setTime(int t) {
	timePurchased = t;
}
// Accessors
int ParkingMeter::getTime() const {
	return timePurchased;
}



#endif // !PARKINGMETER_H