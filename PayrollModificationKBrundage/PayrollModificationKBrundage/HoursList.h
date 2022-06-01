#pragma once
#ifndef HOURSLIST_H
#define HOURSLIST_H



class HoursList
{
private:
	//Structure Declaration
	struct HoursNode {
		int value;
		struct HoursNode* next;
	};

	HoursNode* head;

public:
	// Constructor
	HoursList() {
		head = nullptr;
	}

	// Destructor
	~HoursList();

	// Operations
	void appendNode(int);
	void insertNode(int);
	void deleteNode(int);
	void displayList() const;

};


#endif // !HOURSLIST_H