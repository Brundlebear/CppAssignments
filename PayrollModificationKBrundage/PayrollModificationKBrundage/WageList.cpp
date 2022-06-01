#include "WageList.h"
#include <iostream>

using namespace std;

void WageList::appendNode(double num) {
	WageNode* newNode; // Point to new node
	WageNode* nodePTR; // Move through the list

	// Allocate new node and store num there
	newNode = new WageNode;
	newNode->value = num;
	newNode->next = nullptr;

	// If no nodes in list, make newNode the first
	if (!head) {
		head = newNode;
	}
	// Insert newNode at end otherwise
	else {
		nodePTR = head;

		// Find last node in the list
		while (nodePTR->next) {
			nodePTR = nodePTR->next;
		}

		// Insert newNode as last node
		nodePTR->next = newNode;
	}
}

void WageList::displayList() const {
	WageNode* nodePTR; //To move through the list

	//Position nodePTR at head
	nodePTR = head;

	while (nodePTR) {
		cout << nodePTR->value << endl;
		nodePTR = nodePTR->next;
	}
}

void WageList::insertNode(double num) {
	WageNode* newNode; // Point to new node
	WageNode* nodePTR; // Move through the list
	WageNode* previousNode = nullptr; // The previous node

	// Allocate newNnode and store num there
	newNode = new WageNode;
	newNode->value = num;

	// If no nodes in list, make newNode the first
	if (!head) {
		head = newNode;
	}
	else {

		nodePTR = head;
		previousNode = nullptr;

		// Find last node in the list
		while (nodePTR != nullptr && nodePTR->value < num) {
			previousNode = nodePTR;
			nodePTR = nodePTR->next;
		}

		// If new node is to be first in the list, insert before all other nodes
		if (previousNode == nullptr) {
			head = newNode;
			newNode->next = nodePTR;
		}
		else { // Otherwise insert after the previous one
			previousNode->next = newNode;
			newNode->next = nodePTR;
		}

	}
}

void WageList::deleteNode(double num) {
	WageNode* nodePTR; // Move through the list
	WageNode* previousNode = nullptr; // The previous node

	//If list is empty, do nothing
	if (!head) {
		return;
	}

	// Determine if first node is the one to delete
	if (head->value == num) {
		nodePTR = head->next;
		delete head;
		head = nodePTR;
	}
	else {
		//intialize nodePTR to head of list
		nodePTR = head;

		// Skip all nodes whose value does not match num
		while (nodePTR != nullptr && nodePTR->value != num) {
			previousNode = nodePTR;
			nodePTR = nodePTR->next;
		}

		//if nodePTR is not at the end of the list, link previous node to the node after nodePTR, then delete nodePTR
		if (nodePTR) {
			previousNode->next = nodePTR->next;
			delete nodePTR;
		}
	}
}

WageList::getValue() const {

}

WageList::~WageList() {
	WageNode* nodePTR;
	WageNode* nextNode;

	nodePTR = head;

	while (nodePTR != nullptr) {
		nextNode = nodePTR->next;
		delete nodePTR;
		nodePTR = nextNode;
	}
}