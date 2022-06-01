#pragma once
#ifndef CASHREGISTER_H
#define CASHREGISTER_H
#include <string>

using namespace std;

class CashRegister {

private:
	const double PROFIT_MARGIN = .3;
	const double TAX_RATE = .06;	
	double subtotal, tax, total, units;

public:

	CashRegister(double c, int u) { //populate values of class using cost and qty of inventory items
		subtotal = (c + (c * PROFIT_MARGIN)) * u;
		tax = subtotal * TAX_RATE;
		total = subtotal + tax;

	}


	//Accessor Functions
	double getSubtotal() const {
		return subtotal;
	}

	double getTax() const {
		return tax;
	}

	double getTotal() const {
		return total;
	}

};

#endif // !CASHREGISTER_H