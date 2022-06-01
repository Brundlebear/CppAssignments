#pragma once
#ifndef EMPLOYEEID_H
#define EMPLOYYEID_H

#include <iostream>

using namespace std;

class EmployeeID {

private:
	int iDNum;

public:
	//Constructor
	EmployeeID(int id) {
		iDNum = id;
	}

	//Mutator
	void setID(int id) {
		iDNum = id;
	}

	//Accessor
	int getID() {
		return iDNum;
	}

	//Destructor
	~EmployeeID() {
	}
};


#endif // !EMPLOYEEID_H
