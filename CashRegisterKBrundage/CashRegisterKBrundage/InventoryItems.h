#pragma once
#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include <string>

using namespace std;

class InventoryItem {

private:
	string description;
	double cost;
	int units;
public:
	InventoryItem() { //constructor #1
		description = "";
		cost = 0.0;
		units = 0;
	}

	InventoryItem(string desc) { //assign value to description
		description = desc;

		//initialize cost and units
		cost = 0.0;
		units = 0;
	}

	InventoryItem(string desc, double c, int u) { //assign value to description, cost, and units
		description = desc;
		cost = c;
		units = u;
	}

	//Mutator Functions
	void setDescription(string d) {
		description = d;
	}

	void setCost(double c) {
		cost = c;
	}

	void setUnits(int u) {
		units = u;
	}

	//Accessor Functions
	string getDescription() const {
		return description;
	}

	double getCost() const {
		return cost;
	}

	int getUnits() const {
		return units;
	}

};

#endif // !INVENTORYITEM_H
