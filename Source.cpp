#include <iostream>  
#include "Header.h"
using namespace std;

//adds a value to the end of the list

void LinkedList::appendNode(double num)
{
	ListNode* newNode;  // To point to a new node
	ListNode* nodePtr;  // To move through the list

	// Create a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	//if there are no nodes then make a new first node 
	if (!head)
		head = newNode;
	else  // Otherwise insert at end.
	{
		// start at the first node
		nodePtr = head;

		// find the last node 
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// insert newNode as the last node.
		nodePtr->next = newNode;
	}
}

//disaply all the nodes

void LinkedList::displayList() const
{
	ListNode* nodePtr;  

	
	nodePtr = head;

	
	while (nodePtr)
	{
		// print the value
		cout << nodePtr->value << endl;

		// move to the next node
		nodePtr = nodePtr->next;
	}
}



void LinkedList::insertNode(double num)
{
	ListNode* newNode;					
	ListNode* nodePtr;					
	ListNode* previousNode = nullptr;	

	
	newNode = new ListNode;
	newNode->value = num;

	
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else  
	{
		
		nodePtr = head;

		
		previousNode = nullptr;

		// skip all nodes whose value is less than num
		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else 
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}



void LinkedList::deleteNode(double num)
{
	ListNode* nodePtr;       
	ListNode* previousNode = nullptr; 

	// if the list is empty do nothing
	if (!head)
		return;

	// check if the first node is the one.
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// start at the beggining of the list
		nodePtr = head;

		//skip till the value matches
		while (nodePtr != nullptr && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

	
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}



LinkedList::~LinkedList()
{
	ListNode* nodePtr;   
	ListNode* nextNode;  

	
	nodePtr = head;

	
	while (nodePtr != nullptr)
	{
		
		nextNode = nodePtr->next;

		
		delete nodePtr;

		
		nodePtr = nextNode;
	}
}
