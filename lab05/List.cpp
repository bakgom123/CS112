/*
 * List.cpp
 * student1 : Austin Duimstra(amd 83)
 * student2: David Yoo(gy24)
 * Date:10/5/21
 */

#include "List.h"
#include <stdexcept>
#include <iostream>
using namespace std;

List::List() {
	mySize = 0;
	myFirst = nullptr;
	myLast = nullptr;

}

List::~List() {
	delete myFirst;             // delete first node, invoking ~Node()
	//  (does nothing if myFirst == nullptr)
	myFirst = myLast = nullptr; // clear myFirst and myLast (optional)
	mySize = 0;                 // clear mySize (optional)
}


List::Node::Node() {
	myItem = Item();
	myNext = nullptr;

}

List::Node::Node(Item it, Node *next) {
	myItem = it;
	myNext = next;
}

List::Node::~Node() {
	//	cout << "~Node() is deallocating the node containing item "
	//			<< myItem << endl;
	delete myNext;       // delete the next node, invoking ~Node() in it
	// (does nothing if myNext == nullptr)
}

unsigned List::getSize() const {
	return mySize;
}

Item List::getFirst() const {
	if (mySize == 0) {
		throw underflow_error("Underflow Error");
	}
	return myFirst->myItem;
}


Item List::getLast() const {
	if (mySize == 0) {
		throw underflow_error("Underflow Error");
	}
	return myLast->myItem;
}

void List::append(const Item& it) {
	Node *newNode = new Node();
	newNode->myItem = it;
	if (mySize == 0){
		myFirst = newNode;
	}
	else{
		myLast -> myNext = newNode;
	}
	myLast = newNode;
	mySize ++;
}

List::List(const List& original) {
	myFirst = myLast = nullptr;    //  set pointers
	mySize = 0;                    //   and size to 'empty' values
	Node* oPtr = original.myFirst; //  start at original's first node
	while (oPtr != nullptr) {      //  while there are nodes to copy:
		append(oPtr->myItem);       //   append the item in that node
		oPtr = oPtr->myNext;        //   advance to next node
	}
}

List& List::operator=(const List& rhs) { // rhs == right hand side

	if (&rhs != this) {
		delete myFirst;
		myFirst = myLast = nullptr;
		mySize = 0;
		Node* nPtr = rhs.myFirst;
		while (nPtr != nullptr) {
			append(nPtr->myItem);
			nPtr = nPtr->myNext;
		}

	}
	return *this;
   }





