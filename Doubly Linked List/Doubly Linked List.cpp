
#include "stdafx.h"
#include <memory>
#include "DoublyLinkedList.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	// Pointer Knowledge Check
	cout << "Pointer Testing" << endl;
	int num = 5;
	int * foo = &num;
	int bar = *foo;

	cout << foo << endl;
	cout << num << endl;
	cout << bar << endl;
	system("pause");

	// Int Node Test
	cout << endl << "Int Node Test: " << endl;
	Node <int> MyFirstIntNode(5);
	Node <int> MySecondIntNode(10);
	cout << MyFirstIntNode.getData() << endl;
	cout << MySecondIntNode.getData() << endl;
	system("pause");

	// Char Node Test
	cout << endl << "Char Node Test: " << endl;
	Node<char> MyFirstCharNode('H');
	Node<char> MySecondCharNode('E');
	cout << MyFirstCharNode.getData() << endl;
	cout << MySecondCharNode.getData() << endl;
	system("pause");

	// Linked List Test
	DoublyLinkedList<int> MyFirstLinkedList;

	// Insert Test
	cout << endl << "Insert Node Test: " << endl;
	for (int i = 0; i < 10; i++)
	{
		MyFirstLinkedList.insertNode(i);
	}
	MyFirstLinkedList.displayList();
	system("pause");

	// Find Test
	cout << endl << "Find Node Test: " << endl;
	auto foundNode = *MyFirstLinkedList.find(5);
	cout << foundNode.getData() << endl;
	system("pause");



	return 0;
}
