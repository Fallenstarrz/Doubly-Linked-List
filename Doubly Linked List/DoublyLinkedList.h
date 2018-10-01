#pragma once
#include "stdafx.h"
#include <memory>
#include <iostream>

using namespace std;

// Templated class used to create a generic class, so we can create different types using its blueprint.
// This class is a node, who is responsible for holding and setting the values of the node itself.
template <typename genericType>
class Node
{
private:
	genericType data;
	shared_ptr <Node> nextNode = nullptr;
	shared_ptr <Node> previousNode = nullptr;

public:
	// Constructors
	Node()
	{
		data = NULL;
	}
	Node(genericType newData)
	{
		data = newData;
	}
	Node(genericType newData, shared_ptr<Node> next, shared_ptr<Node> prev)
	{
		data = newData;
		nextNode = next;
		previousNode = prev;
	}

	~Node()
	{
		nextNode = nullptr;
		previousNode = nullptr;
	}

	// Methods
	// Get data from the node
	genericType getData()
	{
		return data;
	}

	// Change/set data in the node
	void setData(genericType newData)
	{
		data = newData;
	}

	// Get the node next in the list
	shared_ptr<Node> getNext()
	{
		return nextNode;
	}

	// Set the node next in the list
	void setNext(shared_ptr<Node> next)
	{
		this->nextNode = next;
	}

	// Get the node previous to this node in the list
	shared_ptr<Node> getPrev()
	{
		return previousNode;
	}

	// Set the node previous to this node in the list
	void setPrev(shared_ptr<Node> prev)
	{
		this->previousNode = prev;
	}
};

// Templated class used to create a generic class, so we can create different types using its blueprint.
// This is a DoublyLinkedList Class responsible for the structure of the list. It will find, insert, delete and print information about the nodes within it. See Methods.
// This class will also maintain sentinel nodes to assist in controlling potential error messages.
template <typename genericType>
class DoublyLinkedList
{
private:
	shared_ptr<Node<genericType>> head = nullptr;
	shared_ptr<Node<genericType>> tail = nullptr;

public:
	// Constructor
	DoublyLinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	// Methods
	// Find data in list by looping through list and comparing the keys. Report to user if found (and where) or if not found.
	genericType find(genericType dataToFind)
	{
		Node <genericType> node1;
		node1 = head;
		while (node1->data != dataToFind)
		{
			node1 = node1->getNext();
		}
		return node1;
	}

	// Insert node into the list by disconnecting previous from first node and next from sentinel node and hooking the new node up in its place
	void insertNode(genericType newData)
	{

	}

	// Delete a node by removing its previous and next pointers and assigning the old previous and next nodes to eachother
	void deleteNode(genericType dataToDelete)
	{

	}

	// Display all data in the list by looping through and printing all data to the console
	void displayList()
	{

	}



	// Extra Credit: Worry about these last
	genericType findMinimum()
	{

	}
	genericType findMaximum()
	{

	}
};