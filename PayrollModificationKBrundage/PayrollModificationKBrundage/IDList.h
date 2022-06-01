#pragma once
#ifndef IDLIST_H
#define IDLIST_H



class IDList
{
private:
	//Structure Declaration
	struct IDNode {
		int value;
		struct IDNode *next;
	};

	IDNode* head;

public:
	// Constructor
	IDList() {
		head = nullptr;
	}

	// Destructor
	~IDList();

	// Operations
	void appendNode(int);
	void insertNode(int);
	void deleteNode(int);
	void displayList() const;

};


#endif // !IDLIST_H
