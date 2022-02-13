/* List.h provides a class for manipulating lists.
 * student: David Yoo(gy24)
 * Date:10/25/21
 */

#ifndef LIST_H_
#define LIST_H_
#include "List.h"
#include <stdexcept>
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;
template <class Item>

class List {
public:
	List();
	virtual ~List();
	friend class ListTester;
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	List(const List& original);
	List& operator=(const List& rhs);
	bool operator==(const List<Item> list2) const;
	bool operator!=(const List<Item> list2) const;
	void readFrom(istream& in);
	void writeTo(ostream& out, string ch) const;
	void readFrom(const string& filename);
	void writeTo(const string& filename) const;
	void prepend(const Item& it);
	int getIndexOf(const Item& it) const;
	void insert(const Item& it, unsigned index);
	void remove(unsigned index);
	bool insertBefore(string otherPersonsName, string yourName);
	bool insertAfter(string otherPersonsName, string yourName);


private:
	struct Node {
		Node();
		Item myItem;
		Node *myNext;
		Node(Item it, Node *next);
		~Node();
	};

	Node *myFirst;
	Node *myLast;
	unsigned mySize;
	friend class ListTester;


};

// Default Constructor
template<class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = nullptr;
	myLast = nullptr;

}

// Destructor
template<class Item>
List<Item>::~List() {
	delete myFirst;             // delete first node, invoking ~Node()
	//  (does nothing if myFirst == nullptr)
	myFirst = myLast = nullptr; // clear myFirst and myLast (optional)
	mySize = 0;                 // clear mySize (optional)
}

// Default Node Constructor
template<class Item>
List<Item>::Node::Node() {
	myItem = Item();
	myNext = nullptr;

}

// Explicit Node Constructor
template<class Item>
List<Item>::Node::Node(Item it, Node *next) {
	myItem = it;
	myNext = next;
}

// Destructor
template<class Item>
List<Item>::Node::~Node() {
	//	cout << "~Node() is deallocating the node containing item "
	//			<< myItem << endl;
	delete myNext;       // delete the next node, invoking ~Node() in it
	// (does nothing if myNext == nullptr)
}

// Method to return the size of the list
template<class Item>
unsigned List<Item>::getSize() const {
	return mySize;
}

// Method to return the first item of the list
template<class Item>
Item List<Item>::getFirst() const {
	if (mySize == 0) {
		throw underflow_error("Underflow Error");
	}
	return myFirst->myItem;
}

// Method to return the last item of the list
template<class Item>
Item List<Item>::getLast() const {
	if (mySize == 0) {
		throw underflow_error("Underflow Error");
	}
	return myLast->myItem;
}

// Method to append item to the list
template<class Item>
void List<Item>::append(const Item& it) {
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

// Copy Constructor
template<class Item>
List<Item>::List(const List& original) {
	myFirst = myLast = nullptr;    //  set pointers
	mySize = 0;                    //   and size to 'empty' values
	Node* oPtr = original.myFirst; //  start at original's first node
	while (oPtr != nullptr) {      //  while there are nodes to copy:
		append(oPtr->myItem);       //   append the item in that node
		oPtr = oPtr->myNext;        //   advance to next node
	}
}

// Assignment Operator
template<class Item>
List<Item>& List<Item>::operator=(const List<Item>& rhs) { // rhs == right hand side
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

// Equality
template<class Item>
bool List<Item>::operator==(const List<Item> list2) const {
	if (mySize != list2.mySize) {
		return false;
	}
	Node * aPtr = myFirst;
	Node * bPtr = list2.myFirst;
	if (aPtr == nullptr && bPtr == nullptr) {
		return true;
	}
	while (aPtr != nullptr && bPtr != nullptr) {
		if (aPtr->myItem != bPtr->myItem) {
			return false;
		}
		aPtr = aPtr->myNext;
		bPtr = bPtr->myNext;
	}
	return true;
}

// Inequality method written by David Yoo (gy24)
template<class Item>
bool List<Item>::operator!=(const List<Item> list2) const {
	if (mySize != list2.mySize) {
		return true;
	}
	Node* aPtr = myFirst;
	Node* bPtr = list2.myFirst;
	while (aPtr != nullptr && bPtr != nullptr) {
		if (aPtr->myItem != bPtr->myItem) {
			return true;
		}
		aPtr = aPtr->myNext;
		bPtr = bPtr->myNext;
	}
	return false;
}


// readFrom
template<class Item>
void List<Item>::readFrom(istream& in) {
	Item it;
	in >> it;
	while (in) {
		append(it);
		if (in.peek() == '\n') {
			break;
		}
		in >> it;
	}
}

// writeTo method written by David Yoo (gy24)
template<class Item>
void List<Item>::writeTo(ostream& out, string s) const {
	Node* tempPtr = myFirst;
	while (tempPtr) {
		out << s << tempPtr->myItem;
		tempPtr = tempPtr->myNext;
	}
	out << endl;
}

// readFrom method written by David Yoo (gy24)
template<class Item>
void List<Item>::readFrom(const string& a) {
	Item it;
	ifstream fin(a);
	while(fin){
		fin >> it;
		append(it);
		if (fin.peek() == '\n') {
			break;
		}
	}
	fin.close();
}

// writeTo method
template<class Item>
void List<Item>::writeTo(const string& filename) const {

	ofstream fout( filename );
	assert (fout.is_open());

	Node * aNode = myFirst;
	while (aNode != nullptr) {
		fout << " " << aNode->myItem;
		aNode = aNode->myNext;
	}
	fout.close();
}

// prepend
template<class Item>
void List<Item>::prepend(const Item& it) {
	Node * nPtr = myFirst->myNext;
	Node * newNode = new Node(it, nPtr);
	Node * currentNode = myFirst->myNext;

	if (mySize == 0) {
		myFirst = newNode;
	}
	else {
		while (currentNode != nullptr) {
			myFirst = newNode;
			currentNode = currentNode->myNext;
		}
	}
}


// getIndexOf method written by David Yoo (gy24)
// Get the index of the item in the list
template<class Item>
int List<Item>::getIndexOf(const Item& it) const {
	Node * aNode = myFirst;
	int i = 0;
	while (aNode != nullptr) {
		if (aNode->myItem == it) {
			return i;
		}
		aNode = aNode->myNext;
		i++;
	}
	return -1;
}


// insert an item to the list
template<class Item>
void List<Item>::insert(const Item& it, unsigned index) {

	Node * newNode = new Node(it, nullptr);
	if (index <= 0) {
		Node * aNode = myFirst;
		newNode->myNext = aNode;
		myFirst = newNode;
		mySize++;
	}

	else if (index >= mySize) {
		myLast->myNext = newNode;
		myLast = newNode;
		mySize++;
	}

	else {
		Node * cNode = myFirst;
		for (unsigned i = 0; i < index - 1; i++) {
			cNode = cNode->myNext;
		}
		newNode->myNext = cNode->myNext;
		cNode->myNext = newNode;
		mySize++;
	}
}


// Remove method written by David Yoo (gy24)
// Remove an item from the list
template<class Item>
void List<Item>::remove(unsigned index) {
	if (index == 0) {
		Node * newNode = new Node;
		newNode = myFirst;
		myFirst = myFirst->myNext;
		newNode->myNext = nullptr;
		delete newNode;
	}

	else if (index == (mySize - 1) && index != 0) {
		Node * bNode = new Node;
		Node * aNode = new Node;
		bNode = myFirst;
		while (bNode->myNext != nullptr) {
			aNode = bNode;
			bNode = bNode->myNext;
		}
		myLast = aNode;
		aNode->myNext = nullptr;
		delete bNode;
	}

	else if (index != 0 && index < (mySize - 1)) {
		Node * bNode = new Node;
		Node * aNode = new Node;
		bNode = myFirst;
		for (unsigned i = 0; i < index; ++i) {
			aNode = bNode;
			bNode = bNode->myNext;
		}
		aNode->myNext = bNode->myNext;
	}
	mySize++;
}


// Insert before method
template<class Item>
bool List<Item>::insertBefore(string otherPersonsName, string yourName){
	if (mySize == 0){
		throw range_error("It is empty!");
	} else {
		if (getFirst() == otherPersonsName){
			prepend(yourName);
			return true;
		}
		Node * prevPtr = myFirst;
		Node * currPtr = myFirst -> myNext;
		for (unsigned i = 0; i < mySize -1; i++){
			if (currPtr -> myItem == otherPersonsName){
				Node * newPerson = new Node(yourName, currPtr);
				prevPtr -> myNext = newPerson;
				mySize++;
				return true;
			}
			prevPtr = prevPtr -> myNext;
			currPtr = currPtr -> myNext;
		}
		return false;
	}
}

// Insert after method
template<class Item>
bool List<Item>::insertAfter(string otherPersonsName, string yourName){
	if (mySize == 0){
		throw range_error ("The line is empty.");
	} else {
		Node * currPtr = myFirst;
		for (unsigned i = 0; i < mySize; i++){
			if (currPtr -> myItem == otherPersonsName){
				Node * newPerson = new Node(yourName, currPtr -> myNext);
				currPtr -> myNext = newPerson;
				if (i == mySize - 1){
					myLast = newPerson;
				}
				mySize++;
				return true;
			}
			currPtr = currPtr -> myNext;
		}
		return false;
	}
}


#endif /* LIST_H_ */
