#pragma once

#ifndef HEADER_H
#define HEADER_H

class LinkedList
{
private:
	
	struct ListNode
	{
		double value;           // The value in this node
		struct ListNode* next;  // To point to the next node
	};

	ListNode* head;            // List head pointer

public:
	// Constructor
	LinkedList()
	{
		head = nullptr;
	}

	// Destructor
	~LinkedList();

	// Linked list operations
	void appendNode(double);
	void insertNode(double);
	void deleteNode(double);
	void displayList() const;
};
#endif
