#pragma once

#include "ParkedCar.h"
#include "ParkingMeter.h"
#include <string>
#include <iostream>

using namespace std;

#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

const int BASE_FINE = 25;
const int HOURLY_FINE = 10;

class ParkingTicket {

private:
	ParkedCar Car;
	ParkingMeter Meter;
	int timeInViolation;
	int fine;

public:
	ParkingTicket() {
		timeInViolation = 0;
		fine = 0;
	}

	ParkingTicket(ParkedCar C, ParkingMeter M) {
		Car = C;
		Meter = M;
		timeInViolation = C.getTimeParked() - M.getTime();
		fine = BASE_FINE + (timeInViolation / 60) * 10;

	}

	void setCar(ParkedCar C) {
		Car = C;
	}


	void setMeter(ParkingMeter M) {
		Meter = M;
	}

	void setTimeInViolation() {
		timeInViolation = Car.getTimeParked() - Meter.getTime();
	}

	void setFine() {  //Calculate fine based on time spent parked
		fine = BASE_FINE + (timeInViolation / 60) * 10;
	}

	int getTimeInViolation() const {
		return timeInViolation;
	}

	int getFine() const {
		return fine;
	}

	void print() {
		cout << "Vehicle Information" << endl;
		cout << "\tMake: " << Car.getMake() << endl;
		cout << "\tModel: " << Car.getModel() << endl;
		cout << "\tColor: " << Car.getColor() << endl;
		cout << "\tLicense Plate: " << Car.getPlate() << endl;
		cout << "\tMinutes Parked: " << Car.getTimeParked() << endl;
		cout << "Ticket Information: " << endl;
		cout << "\tMinutes in Violation: " << ParkingTicket(Car, Meter).getTimeInViolation() << endl;
		cout << "\tFine: $" << ParkingTicket(Car, Meter).getFine() << endl;
	}
};

#endif // !PARKINGTICKET_H