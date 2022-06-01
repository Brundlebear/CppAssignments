#pragma once
#include <string>

using namespace std;

#ifndef PARKEDCAR_H
#define PARKEDCAR_H

class ParkedCar {

private:
// Characteristics of the Vehicle: make, model, color, plate number, and time parked
	string make, model, color, licensePlate;
	int timeParked;

public:
//Constructors
	ParkedCar();

	ParkedCar(string, string, string, string, int);

// Mutators
	void setMake(string);
	void setModel(string);
	void setColor(string);
	void setPlate(string);
	void setTimeParked(int);
// Accessors
	string getMake() const;
	string getModel() const;
	string getColor() const;
	string getPlate() const;
	int getTimeParked() const;
};


	//Defining Constructors
ParkedCar::ParkedCar() {
	make = " ";
	model = " ";
	color = " ";
	licensePlate = " ";
	timeParked = 0;
}


	// Defining mutators
void ParkedCar::setMake(string m) {
	make = m;
}

void ParkedCar::setModel(string mo) {
	model = mo;
}

void ParkedCar::setColor(string c) {
	color = c;
}

void ParkedCar::setPlate(string p) {
	licensePlate = p;
}

void ParkedCar::setTimeParked(int t) {
	timeParked = t;
}

	// Defining Accessors
string ParkedCar::getMake() const {
	return make;
}

string ParkedCar::getModel() const {
	return model;
}

string ParkedCar::getColor() const {
	return color;
}

string ParkedCar::getPlate() const {
	return licensePlate;
}

int ParkedCar::getTimeParked() const {
	return timeParked;
}




#endif // !PARKEDCAR_H