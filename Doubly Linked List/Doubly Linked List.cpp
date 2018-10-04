
#include "stdafx.h"
#include <memory>
#include "DoublyLinkedList.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int num = 5;
	int * foo = &num;
	int bar = *foo;

	cout << foo << endl;
	cout << num << endl;
	cout << bar << endl;
	system("pause");

	// Int Node Test
	Node <int> MyFirstIntNode(5);
	Node <int> MySecondIntNode(10);
	cout << MyFirstIntNode.getData() << endl;
	cout << MySecondIntNode.getData() << endl;
	system("pause");

	// Char Node Test
	Node<char> MyFirstCharNode('H');
	Node<char> MySecondCharNode('E');
	cout << MyFirstCharNode.getData() << endl;
	cout << MySecondCharNode.getData() << endl;
	system("pause");


	// Linked List Test
	DoublyLinkedList<int> MyFirstLinkedList;
	MyFirstLinkedList.insertNode(5);

	system("pause");
	return 0;
}
