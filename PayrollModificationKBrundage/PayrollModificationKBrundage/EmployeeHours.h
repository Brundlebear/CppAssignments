#pragma once
#ifndef EMPLOYEEHOURS_H
#define EMPLOYYEHOURS_H

#include <iostream>

using namespace std;

class EmployeeHours {

private:
	int hours;

public:
	//Constructor
	EmployeeHours(int h) {
		hours = h;
	}

	//Mutator
	void setHours(int h) {
		hours = h;
	}

	//Accessor
	int getHours() {
		return hours;
	}

	//Destructor
	~EmployeeHours() {
	}
};

#endif // !EMPLOYEEHOURS_H
