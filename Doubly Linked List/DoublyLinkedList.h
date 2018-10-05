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
	shared_ptr <Node<genericType>> nextNode = nullptr;
	//shared_ptr <Node> nextNode = nullptr;
	shared_ptr <Node<genericType>> previousNode = nullptr;
	//shared_ptr <Node> previousNode = nullptr;

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
		head = make_shared<Node<genericType>>();
		head->setData(NULL);
		head->setNext(tail);
		head->setPrev(nullptr);
		tail = make_shared<Node<genericType>>();
		tail->setData(NULL);
		tail->setNext(nullptr);
		tail->setPrev(head);
	}

	// Methods
	// Find data in list by looping through list and comparing the keys. Report to user if found (and where) or if not found.
	shared_ptr<Node<genericType>> find(genericType dataToFind)
	{
		//shared_ptr <Node <genericType>> node1();
		auto currentNode = head;
		//node1 = head;
		while (currentNode->getData() != dataToFind)
		{
			currentNode = currentNode->getNext();

			if (currentNode == tail)
			{
				return NULL;
			}
		}
		return currentNode;
	}

	// Insert node into the list by disconnecting previous from first node and next from sentinel node and hooking the new node up in its place
	void insertNode(genericType newData)
	{
		// Create a new node
		//auto nodeToInsert = make_shared<Node<genericType>>();
		shared_ptr <Node<genericType>> nodeToInsert = make_shared<Node<genericType>>();
		// Set data to the passed in value
		nodeToInsert->setData(newData);
		// Set previous of new node to the previous of tail
		nodeToInsert->setPrev(tail->getPrev());
		// Set next of new node to tail
		nodeToInsert->setNext(tail);
		// Set previous of this node's next node to this node
		nodeToInsert->getNext()->setPrev(nodeToInsert);
		// Set next of this node's previous node to this node
		nodeToInsert->getPrev()->setNext(nodeToInsert);
	}

	// Delete a node by removing its previous and next pointers and assigning the old previous and next nodes to eachother
	void deleteNode(genericType dataToDelete)
	{
		// 1. Empty Linked-List
		// 2. Removed node is head
		// 3. Removed node is tail
		// 4. Removed node is between head and tail
	}

	// Display all data in the list by looping through and printing all data to the console
	void displayList()
	{
		auto node1 = head->getNext();
		while (node1 != tail)
		{
			cout << node1->getData() << endl;
			node1 = node1->getNext();
		}
	}



	// Extra Credit: Worry about these last
	genericType findMinimum()
	{

	}
	genericType findMaximum()
	{

	}
};