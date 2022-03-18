/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: David Yoo (gy24)
 * Date: 11/18/2021
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == nullptr ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;

typedef int Item;
template <class Item>

class BST {
public:
	BST();
	virtual ~BST();
	bool isEmpty() const;
	unsigned getNumItems() const;

	void traverseInorder();
	void traversePreorder();
	void traversePostorder();
	void insert(const Item& it);
	bool contains(const Item& it) const;
	unsigned getHeight() const;

private:
	struct Node {
	    Node(const Item& it);
            virtual ~Node();

            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            void processItem();
            void insert(const Item& it);
            bool contains(const Item& it) const;
            unsigned getHeight() const;
		
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};

template <class Item>
BST<Item>::BST(){
	myRoot = nullptr;
	myNumItems = 0;
}

template <class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = nullptr;
	myNumItems = 0;
}

template <class Item>
BST<Item>::Node::Node(const Item& it) {
	myItem = it;
	myLeft = nullptr;
	myRight = nullptr;
}

template <class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}

template <class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

template <class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

template <class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

template <class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != nullptr) {
		myLeft->traversePreorder();
	}
	if (myRight != nullptr) {
		myRight->traversePreorder();
	}
}

template <class Item>
void BST<Item>::Node::processItem() {
	cout << ' ' << myItem;
}

template <class Item>
void BST<Item>::insert(const Item& it){
	if (isEmpty()){
		myRoot = new Node(it);
	}
	else{
		try{
			myRoot -> insert(it);
		}
		catch(Exception& ex){
			throw ex;
		}
	}
	++myNumItems;

}

template <class Item>
void BST<Item>::Node::insert(const Item& it){
	if (it < myItem){
		if(myLeft == nullptr){
			myLeft = new Node(it);
		}
		else{
			myLeft -> insert(it);
		}
	}
	else if(it > myItem){
		if (myRight == nullptr){
			myRight = new Node(it);
		} else{
			myRight -> insert(it);
		}
	}
	else if (it == myItem){
		throw Exception ("insert()", "Error!");
	}
}

template <class Item>
bool BST<Item>::contains(const Item& it) const{
	if(isEmpty()){
		return false;
	}
	else if (myRoot -> myItem == it){
		return true;
	}
	else{
		return myRoot -> contains(it);
	}
}

template <class Item>
bool BST<Item>::Node::contains(const Item& it) const{
	if (myItem == it){
		return true;
	}
	else{
		if(it < myItem){
			if (myLeft == nullptr){
				return false;
			}
			return myLeft -> contains(it);
		}
		if (myRight == nullptr){
			return false;
		}
		return myRight -> contains(it);
	}
}


template <class Item>
void BST<Item>::traversePostorder(){
	if (!isEmpty()){
		myRoot -> traversePostorder();
	}
}

template <class Item>
void BST<Item>::Node::traversePostorder(){
	if(myLeft != nullptr){
		myLeft -> traversePostorder();
	}
	else if (myRight != nullptr){
		myRight -> traversePostorder();
	}
	processItem();
}


template <class Item>
void BST<Item>::traverseInorder(){
	if (!isEmpty()){
		myRoot ->traverseInorder();
	}
}

template <class Item>
void BST<Item>::Node::traverseInorder(){
	if(myLeft != nullptr){
		myLeft -> traverseInorder();
	}
	processItem();
	if (myRight != nullptr){
		myRight -> traverseInorder();
	}
	processItem();
}

template <class Item>
unsigned BST<Item>::getHeight() const {
	if (isEmpty()){
		return 0;
	} else{
		return myRoot -> getHeight();
	}
}

template <class Item>
unsigned BST<Item>::Node::getHeight() const{
	if (myLeft == nullptr && myRight == nullptr){
		return 1;
	}
	unsigned left = 0;
	unsigned right = 0;
	if (myLeft != nullptr){
		left += myLeft -> getHeight();
	}
	if (myRight != nullptr){
		right += myRight -> getHeight();
	}
	return max(left, right)+1;
}


#endif /*BST_H_*/

