#pragma once
#ifndef WAGELIST_H
#define WAGELIST_H



class WageList
{
private:
	//Structure Declaration
	struct WageNode {
		int value;
		struct WageNode* next;
	};

	WageNode* head;

public:
	// Constructor
	WageList() {
		head = nullptr;
	}

	// Destructor
	~WageList();

	// Operations
	void appendNode(double);
	void insertNode(double);
	void deleteNode(double);
	void displayList() const;
	void getValue() const;

};


#endif // !WAGELIST_H