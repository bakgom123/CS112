/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: David Yoo (gy24)
 * Date: 11/15/2021
 */

#include "BST.h"


BST::~BST() {
	delete myRoot;
	myRoot = nullptr;
	myNumItems = 0;
}

BST::Node::Node(const Item& it) {
	myItem = it;
	myLeft = nullptr;
	myRight = nullptr;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}

void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != nullptr) {
		myLeft->traversePreorder();
	}
	if (myRight != nullptr) {
		myRight->traversePreorder();
	}
}

void BST::Node::processItem() {
	cout << ' ' << myItem;
}

void BST::insert(const Item& it){
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

void BST::Node::insert(const Item& it){
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

bool BST::contains(const Item& it) const{
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

bool BST::Node::contains(const Item& it) const{
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


void BST::traversePostorder(){
	if (!isEmpty()){
		myRoot -> traversePostorder();
	}
}

void BST::Node::traversePostorder(){
	if(myLeft != nullptr){
		myLeft -> traversePostorder();
	}
	else if (myRight != nullptr){
		myRight -> traversePostorder();
	}
	processItem();
}


void BST::traverseInorder(){
	if (!isEmpty()){
		myRoot ->traverseInorder();
	}
}

void BST::Node::traverseInorder(){
	if(myLeft != nullptr){
		myLeft -> traverseInorder();
	}
	processItem();
	if (myRight != nullptr){
		myRight -> traverseInorder();
	}
	processItem();
}




reverse(){
    //반대로 go right first, visit, and then go left
    
}

// destructor, the order of release of memory is in post-order
