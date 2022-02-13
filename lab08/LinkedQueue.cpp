/* LinkedQueue.cpp defines the methods for class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin University.
 * Student name: David Yoo (gy24)
 * Date: 11/09/2021
 */

#include "LinkedQueue.h"

LinkedQueue::LinkedQueue() {
	mySize = 0;
	myFirstPtr = myLastPtr = nullptr;
}

LinkedQueue::LinkedQueue(const LinkedQueue& original) {
	makeCopyOf(original);
}

void LinkedQueue::makeCopyOf(const LinkedQueue& original) {
	mySize = original.mySize;
	if ( mySize == 0 ) {
		myFirstPtr = myLastPtr = nullptr;
	} else {
		myFirstPtr = new Node(original.getFirst(), nullptr);
		Node * temp0 = original.myFirstPtr->myNextPtr;
		Node * temp1 = myFirstPtr;
		while (temp0 != nullptr) {
			temp1->myNextPtr = new Node(temp0->myItem, nullptr);
			temp1 = temp1->myNextPtr;
			temp0 = temp0->myNextPtr;
		}
		myLastPtr = temp1;
	}
}

LinkedQueue::~LinkedQueue() {
	delete myFirstPtr;
	myFirstPtr = myLastPtr = nullptr;
	mySize = 0;
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& aQueue) {
	if (this != &aQueue) {
		delete myFirstPtr;    // invokes recursive ~Node()
		makeCopyOf(aQueue);
	}
	return *this;
}


Item LinkedQueue::getFirst()const {
	if (isEmpty()) {
		throw EmptyQueueException("LinkedQueue is empty!");
	}
	return myFirstPtr->myItem;
}


Item LinkedQueue::getLast()const {
	if (isEmpty()) {
		throw EmptyQueueException("LinkedQueue is empty!");
	}
	return myLastPtr->myItem;
}


void LinkedQueue::append(const Item& it) {
	Node* nPtr = new Node(it, nullptr);
	try{
	} catch (bad_alloc const&){
		throw FullQueueException ("LinkedQueue is full!");
	}
	if (isEmpty()){
		myFirstPtr = nPtr;
	} else {
		myLastPtr->myNextPtr = nPtr;
	}
	myLastPtr = nPtr;
	mySize++;
}

Item LinkedQueue::remove() {
	if (isEmpty()){
		throw EmptyQueueException("LinkedQueue is empty!");
	} else {
		Item result = myFirstPtr->myItem;
		Node* nPtr = myFirstPtr;
		myFirstPtr = myFirstPtr->myNextPtr;
		nPtr->myNextPtr = nullptr;
		delete nPtr;
		mySize--;
		return result;
	}
}


