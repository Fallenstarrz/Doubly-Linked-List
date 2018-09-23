#pragma once
#include <memory>


template <typename genericType>
class Node
{
private:
	genericType data;
	shared_ptr <Node> nextNode;
	shared_ptr <Node> previousNode;

public:
	// Constructors
	Node();
	Node(genericData newData);
	Node(genericData newData, shared_ptr next, shared_ptr prev);

	// Methods
	Node* getData();
	void setData(genericType newData);
	Node* getNext();
	void setNext(shared_ptr next);
	Node* getPrev();
	void setPrev(shared_ptr prev);
};

template <typename genericType>
class DoublyLinkedList
{
private:
	shared_ptr<Node> head;
	shared_ptr<Node> tail;
	Node LinkNode;

public:
	// Constructor
	DoublyLinkedList();

	// Methods
	genericType find(genericType dataToFind);
	void insertNode(newData);
	void deleteNode(dataToDelete);
	genericType findMinimum();
	genericType findMaximum();
};