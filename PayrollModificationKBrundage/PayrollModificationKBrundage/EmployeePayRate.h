#pragma once
#ifndef EMPLOYEEPAYRATE_H
#define EMPLOYEEPAYRATE_H

#include <iostream>

using namespace std;

class EmployeePayRate {

private:
	double wage;

public:
	//Constructor
	EmployeePayRate(double w) {
		wage = w;
	}

	//Mutator
	void setPayRate(double w) {
		wage = w;
	}

	//Accessor
	double getPayRate() {
		return wage;
	}

	//Destructor
	~EmployeePayRate() {
	}
};

#endif // !EMPLOYEEPAYRATE_H
