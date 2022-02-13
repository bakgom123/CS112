/* ListTester.cpp defines the test methods for class List.
 * student1: Austin Duimstra(amd 83)
 * student2: David Yoo(gy24)
 * Date:10/7/21
 * Joel Adams, for CS 112 at Calvin University.
 */


#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
using namespace std;

void ListTester::runTests() {
	cout << "Running List tests..." << endl;
	//	testDefaultConstructor();
	//	testNodeDefaultConstructor();
	//	testNodeExplicitConstructor();
	//	testAppend();
	//	testDestructor();
	//	testCopyConstructor();
	//	testAssignment();
	//	testEquality();
	//	testReadFromStream();
	//	testWriteToFile();
	//	testPrepend();
	//	testInsert();
	//	testInequality();
	//	testWriteToStream();
	//	testReadFromString();
	//	testGetIndexOf();
	//	testRemove();
	testInsertBefore();
	testInsertAfter();
	cout << "All tests passed!" << endl;
}

//void ListTester::testDefaultConstructor() {
//	cout << "Testing List default constructor... " << flush;
//	List<double> aList;
//	assert( aList.mySize == 0 );
//	assert( aList.myFirst == nullptrptr );
//	assert( aList.myLast == nullptrptr );
//	cout << "Passed!" << endl;
//}
//
//void ListTester::testNodeDefaultConstructor() {
//	cout << "Testing Node default constructor... " << flush;
//	List<double>::Node aNode;
//	assert( aNode.myItem == 0 );
//	assert( aNode.myNext == nullptrptr );
//	cout << "Passed!" << endl;
//}
//
//void ListTester::testNodeExplicitConstructor() {
//	cout << "Testing Node explicit constructor... " << flush;
//	List<double>::Node n1(11, nullptrptr );
//	assert( n1.myItem == 11 );
//	assert( n1.myNext == nullptrptr );
//	cout << " 1 " << flush;
//
//	List<double>::Node *n3 = new List<double>::Node(33, nullptrptr);
//	List<double>::Node n2(22, n3);
//	assert( n2.myItem == 22 );
//	assert( n2.myNext == n3 );
//	cout << " 2 " << flush;
//	cout << "Passed!" << endl;
//}
//
//void ListTester::testAppend() {
//	cout << "Testing append()... " << flush;
//	// empty List
//	List<double> aList;
//	assert( aList.getSize() == 0 );
//	assert( aList.myFirst == nullptrptr );
//	assert( aList.myLast == nullptrptr );
//	try {
//		aList.getFirst();
//		cerr << "getFirst() worked on empty list" << endl;
//		exit(1);
//	} catch (underflow_error&) {
//		cout << " 0a " << flush;
//	}
//	try {
//		aList.getLast();
//		cerr << "getLast() worked on empty list" << endl;
//		exit(1);
//	} catch (underflow_error&) {
//		cout << " 0b " << flush;
//	}
//	// append to empty list
//	aList.append(11);
//	assert( aList.getSize() == 1 );
//	assert( aList.myFirst != nullptrptr );
//	assert( aList.myLast == aList.myFirst );
//	assert( aList.getFirst() == 11 );
//	assert( aList.getLast() == 11 );
//	assert( aList.myFirst->myNext == nullptrptr );
//	cout << " 1 " << flush;
//	// append to a list containing 1 Item
//	aList.append(22);
//	assert( aList.getSize() == 2 );
//	assert( aList.myFirst != nullptrptr );
//	assert( aList.myLast != nullptrptr );
//	assert( aList.myFirst != aList.myLast );
//	assert( aList.getFirst() == 11 );
//	assert( aList.getLast() == 22 );
//	assert( aList.myFirst->myNext != nullptrptr );
//	assert( aList.myLast->myNext == nullptrptr );
//	cout << " 2 " << flush;
//	// append to a list containing 2 Items
//	aList.append(33);
//	assert( aList.getSize() == 3 );
//	assert( aList.myFirst != nullptrptr );
//	assert( aList.myLast != nullptrptr );
//	assert( aList.getFirst() == 11 );
//	assert( aList.getLast() == 33 );
//	assert( aList.myFirst->myNext->myItem == 22 );
//	assert( aList.myLast->myNext == nullptrptr );
//	cout << " 3 " << flush;
//	cout << "Passed!" << endl;
//}
//
//void ListTester::testDestructor() {
//	cout << "Testing destructor... " << flush;
//	List<double> aList;
//	aList.~List();
//	assert( aList.getSize() == 0 );
//	assert( aList.myFirst == nullptrptr );
//	assert( aList.myLast == nullptrptr );
//	cout << " 1 " << flush;
//
//	aList.append(11);
//	aList.append(22);
//	aList.append(33);
//	aList.~List();
//	assert( aList.getSize() == 0 );
//	assert( aList.myFirst == nullptrptr );
//	assert( aList.myLast == nullptrptr );
//	cout << " 2 " << flush;
//	cout << "Passed!  But double-check for memory leaks!" << endl;
//}
//
//void ListTester::testCopyConstructor() {
//	cout << "Testing copy constructor... " << flush;
//	// copy empty list
//	List<double> list1;
//	List<double> list2(list1);
//	assert( list2.getSize() == 0 );
//	assert( list2.myFirst == nullptrptr );
//	assert( list2.myLast == nullptrptr );
//	cout << " 1 " << flush;
//
//	// copy nonempty list
//	List<double> list3;
//	list3.append(11);
//	list3.append(22);
//	list3.append(33);
//	List<double> list4(list3);
//	assert( list4.getSize() == 3 );
//	assert( list4.getFirst() == 11 );
//	assert( list4.getLast() == 33 );
//	assert( list4.myFirst->myNext->myItem == 22 );
//	assert( list4.myFirst != list3.myFirst );
//	assert( list4.myLast != list3.myLast );
//	cout << " 2 " << flush;
//	cout << "Passed!" << endl;
//}
//
//void ListTester::testAssignment() {
//	cout << "Testing assignment... " << flush;
//	// empty to empty assignment
//	List<double> list1;
//	List<double> list2;
//	list2 = list1;
//	assert( list2.getSize() == 0 );
//	assert( list2.myFirst == nullptrptr );
//	assert( list2.myLast == nullptrptr );
//	cout << " 1 " << flush;
//
//	// non-empty to empty assignment
//	List<double> list3;
//	list3.append(11);
//	list3.append(22);
//	list3.append(33);
//	List<double> list4;
//	list4 = list3;
//	assert( list4.getSize() == 3 );
//	assert( list4.getFirst() == 11 );
//	assert( list4.getLast() == 33 );
//	assert( list4.myFirst->myNext->myItem == 22 );
//	// check that nodes are distinct
//	assert( list4.myFirst != list3.myFirst );
//	assert( list4.myFirst->myNext != list3.myFirst->myNext );
//	assert( list4.myLast != list3.myLast );
//	cout << " 2 " << flush;
//
//	// equal-sized non-empty to non-empty assignment
//	List<double> list5;
//	list5.append(44);
//	list5.append(55);
//	list5.append(66);
//	list5 = list3;
//	assert( list5.getSize() == 3 );
//	assert( list5.getFirst() == 11 );
//	assert( list5.getLast() == 33 );
//	assert( list5.myFirst->myNext->myItem == 22 );
//	// check that nodes are distinct
//	assert( list5.myFirst != list3.myFirst );
//	assert( list5.myFirst->myNext != list3.myFirst->myNext );
//	assert( list5.myLast != list3.myLast );
//	cout << " 3 " << flush;
//
//	// empty to non-empty assignment
//	List<double> list6;
//	list6.append(44);
//	list6.append(55);
//	list6.append(66);
//	List<double> list7;
//	list6 = list7;
//	assert( list6.getSize() == 0 );
//	assert( list6.myFirst == nullptrptr );
//	assert( list6.myLast == nullptrptr );
//	cout << " 4 " << flush;
//
//	// unequal-sized non-empty to non-empty assignment
//	List<double> list8;
//	list8.append(44);
//	list8.append(55);
//	list8.append(66);
//	list8.append(77);
//	list8 = list3;
//	assert( list8.getSize() == 3 );
//	assert( list8.getFirst() == 11 );
//	assert( list8.getLast() == 33 );
//	assert( list8.myFirst->myNext->myItem == 22 );
//	// check that nodes are distinct
//	assert( list8.myFirst != list3.myFirst );
//	assert( list8.myFirst->myNext != list3.myFirst->myNext );
//	assert( list8.myLast != list3.myLast );
//	cout << " 5 " << flush;
//
//	// assignment chaining
//	List<double> list9;
//	list9.append(44);
//	list9.append(55);
//	list9.append(66);
//	list9.append(77);
//	List<double> list10;
//	list10 = list9 = list8;
//	assert( list10.getSize() == 3 );
//	assert( list10.getFirst() == 11 );
//	assert( list10.getLast() == 33 );
//	assert( list10.myFirst->myNext->myItem == 22 );
//	cout << " 6 " << flush;
//
//	// self-assignment (stupid, but possible)
//	List<double> list11;
//	list11.append(11);
//	list11.append(22);
//	list11.append(33);
//	list11 = list11;
//	assert( list11.getSize() == 3 );
//	assert( list11.getFirst() == 11 );
//	assert( list11.getLast() == 33 );
//	assert( list11.myFirst->myNext->myItem == 22 );
//	cout << " 7 " << flush;
//
//	cout << "Passed!  But double-check for memory leaks!" << endl;
//}
//
////Equality Test
//void ListTester::testEquality() {
//	cout << "Testing equality... " << flush;
//	// two empty lists
//	List<double> list1;
//	List<double> list2;
//	assert( list1 == list1 );
//	cout << " 0 " << flush;
//
//	// a non-empty list
//	List<double> list3;
//	list3.append(3);
//	assert( !(list3 == list1) );
//	cout << " 1 " << flush;
//
//	// equal lists
//	List<double> list4;
//	list4.append(3);
//	assert( list4 == list3 );
//	assert( list3 == list4 );
//	cout << " 2 " << flush;
//
//	// unequal lists
//	list3.append(5);
//	List<double> list5;
//	list5.append(4);
//	list5.append(5);
//	assert( !(list5 == list3) );
//	assert( !(list3 == list5) );
//	cout << " 3 " << flush;
//
//	// lists of different sizes
//	list4.append(4);
//	list4.append(5);
//	assert( !(list4 == list5) );
//	assert( !(list5 == list4) );
//	assert( !(list5 == list3) );
//	cout << " 4 " << flush;
//
//	cout << "Passed!" << endl;
//}
//
//// ReadFromStream test
//void ListTester::testReadFromStream() {
//
//	cout << "Testing ReadFromStream... " << flush;
//
//	ifstream fin("testB.txt");
//	assert( fin.is_open() );
//	List<double> list1;
//	list1.readFrom(fin);
//	assert (list1.mySize == 5);
//	assert( list1.myFirst->myItem == 1);
//	assert( list1.myLast->myItem == 5);
//	cout << " 0 " << flush;
//
//	ifstream fin1("testC.txt");
//	assert ( fin1.is_open() );
//	List<double> list2;
//	list2.readFrom(fin1);
//	assert( list2.mySize);
//	assert( list2.mySize == 3);
//	assert( list2.myFirst->myItem == 1);
//	assert( list2.myLast->myItem == 3);
//	assert( list2.getIndexOf(2) == 1);
//	cout << " 1 " << flush;
//
//	cout << "Passed!" << endl;
//}
//
//// WriteToFile test
//void ListTester::testWriteToFile() {
//
//	cout << "Testing WriteToFile... " << flush;
//
//	List<double> list1;
//	ifstream fin1("testD.txt");
//	assert(fin1.is_open());
//	list1.readFrom(fin1);
//	list1.writeTo("testDCopy.txt");
//	fin1.close();
//
//	List<double> list2;
//	ifstream fin2("testDCopy.txt");
//	assert(fin2.is_open());
//	list2.readFrom(fin2);
//	assert(list2.mySize == 6);
//	assert(list2.myFirst->myItem == 1);
//	assert(list2.myLast->myItem == 6);
//	fin2.close();
//
//	cout << "Passed!" << endl;
//}
//
////Prepend test
//void ListTester::testPrepend() {
//
//	cout << "Testing Prepend... " << flush;
//
//	// empty case
//	List<double> list1;
//	list1.append(1);
//	assert( list1.getSize() == 1 );
//	assert( list1.myFirst != nullptrptr );
//	assert( list1.myLast == list1.myFirst );
//	assert( list1.getFirst() == 1 );
//	assert( list1.getLast() == 1 );
//	assert( list1.myFirst->myNext == nullptrptr );
//	cout << " 0 " << flush;
//
//	// 1 Item case
//	list1.append(2);
//	assert( list1.getSize() == 2 );
//	assert( list1.myFirst != nullptrptr );
//	assert( list1.myLast != nullptrptr );
//	assert( list1.myFirst != list1.myLast );
//	assert( list1.getFirst() == 1 );
//	assert( list1.getLast() == 2 );
//	assert( list1.myFirst->myNext != nullptrptr );
//	assert( list1.myLast->myNext == nullptrptr );
//	cout << " 1 " << flush;
//
//	// 2 Items case
//	list1.append(3);
//	assert( list1.getSize() == 3 );
//	assert( list1.myFirst != nullptrptr );
//	assert( list1.myLast != nullptrptr );
//	assert( list1.getFirst() == 1 );
//	assert( list1.getLast() == 3 );
//	assert( list1.myFirst->myNext->myItem == 2 );
//	assert( list1.myLast->myNext == nullptrptr );
//	cout << " 2 " << flush;
//
//	cout << "Passed!" << endl;
//}
//
////Insert test
//void ListTester::testInsert() {
//
//	cout << "Testing Insert... " << flush;
//
//	//Insert to an empty list
//	List<double> list1;
//	list1.insert(9, 0);
//	assert (list1.mySize == 1);
//	assert (list1.myFirst->myItem == 9);
//	assert (list1.myFirst->myNext == nullptrptr);
//	cout << " 0 " << flush;
//
//	//Insert to 1 Item list (front)
//	List<double> list2;
//	list2.append(1);
//	list2.insert(0, 0);
//	assert(list2.mySize == 2);
//	assert(list2.myFirst->myItem == 0);
//	assert(list2.myFirst->myNext == list2.myLast);
//	assert(list2.myLast->myItem == 1);
//	cout << " 1 " << flush;
//
//	// Insert to 1 Item list (end)
//	List<double> list3;
//	list3.append(5);
//	list3.insert(2, 1);
//	assert(list3.mySize == 2);
//	assert(list3.myFirst->myItem == 5);
//	assert(list3.myFirst->myNext == list3.myLast);
//	assert(list3.myLast->myItem == 2);
//	cout << " 2 " << flush;
//
//	cout << "Passed!" << endl;
//
//}
//
//// Inequality method test written by David Yoo (gy24)
//void ListTester::testInequality() {
//	cout << "Testing inequality... " << flush;
//
//	// two empty lists
//	List<double> list1;
//	List<double> list2;
//	assert( !(list1 != list1) );
//	cout << " 0 " << flush;
//
//	// one non-empty list
//	List<double> list3;
//	list3.append(1);
//	assert( list3 != list1);
//	cout << " 1 " << flush;
//
//	// equal lists
//	List<double> list4;
//	list4.append(1);
//	assert( !(list4 != list3) );
//	assert( !(list3 != list4) );
//	cout << " 2 " << flush;
//
//	// unequal lists
//	list3.append(2);
//	List<double> list5;
//	list5.append(3);
//	list5.append(2);
//	assert( list5 != list3);
//	assert( list3 != list5);
//	cout << " 3 " << flush;
//
//	// lists of different sizes
//	list4.append(3);
//	list4.append(5);
//	assert( list4 != list5);
//	assert( list5 != list4);
//	assert( list5 != list3);
//	cout << " 4 " << flush;
//
//	cout << "Passed!" << endl;
//}
//
//// writeToStream method test written by David Yoo (gy24)
//void ListTester::testWriteToStream() {
//	cout << "Testing writeTo(ostream)... " << flush;
//
//	List<double> list1;
//	for (unsigned i = 0; i < 5; i++) {
//		list1.append(i + 1);
//	}
//
//	ofstream fout("testA.txt");
//	assert( fout.is_open() );
//	list1.writeTo(fout);
//	fout.close();
//
//	ifstream fin("testA.txt");
//	assert(fin.is_open());
//	double value;
//	for (unsigned i = 0; i < 5; i++) {
//		fin >> value;
//		assert(value == i + 1);
//	}
//
//	cout << "Passed!" << endl;
//}
//
//// readFromString method test written by David Yoo (gy24)
//void ListTester::testReadFromString() {
//	cout << "Testing readFrom(string)... " << flush;
//
//	List<double> list1;
//	list1.readFrom("testB.txt");
//	assert( list1.mySize == 5);
//	assert( list1.myFirst->myItem == 1);
//	assert( list1.myLast->myItem == 5);
//	assert( list1.getIndexOf(2) == 1);
//	assert( list1.getIndexOf(3) == 2);
//
//	cout << "Passed!" << endl;
//}
//
//// getIndexOf method test written by David Yoo (gy24)
//void ListTester::testGetIndexOf() {
//	cout << "Testing getIndexOf(Item)... " << flush;
//
//	// empty list
//	List<double> list1;
//	assert( list1.getIndexOf(1) == -1);
//	cout << " 0 " << flush;
//
//	// non-empty list
//	List<double> list2;
//	list2.append(1);
//	list2.append(2);
//	assert( list2.getIndexOf(1) == 0);
//	assert( list2.getIndexOf(2) == 1);
//	assert( list2.getIndexOf(3) == -1);
//	cout << " 1 " << flush;
//
//	// search for the index of two same elements
//	List<double> list3;
//	list3.append(1);
//	list3.append(1);
//	assert( list3.getIndexOf(1) == 0);
//	cout << " 2 " << flush;
//
//	cout << "Passed!" << endl;
//}
//
//// remove method test written by David Yoo (gy24)
//void ListTester::testRemove() {
//	cout << "Testing remove(index)... " << flush;
//
//	List<double> list1;
//	list1.append(1);
//	list1.append(2);
//	list1.append(3);
//	list1.append(4);
//	list1.remove(2);
//	assert(list1.myFirst->myItem == 1);
//	assert(list1.myFirst->myNext->myItem == 2);
//	assert(list1.myFirst->myNext->myNext->myItem == 4);
//	cout << " 0 " << flush;
//
//	List<double> list2;
//	list2.append(1);
//	list2.append(2);
//	list2.append(3);
//	list2.append(4);
//	list2.remove(0);
//
//	assert(list2.myFirst->myItem == 2);
//	assert(list2.myFirst->myNext->myItem == 3);
//	assert(list2.myFirst->myNext->myNext->myItem == 4);
//	cout << " 1 " << flush;
//
//	cout << "Passed!" << endl;
//}

void ListTester::testInsertBefore() {
	cout << "insertBefore... " << flush;
	List<string> l1;
	List<string>::Node * currPtr = l1.myFirst;
	l1.append("A");
	try {
		l1.insertBefore("A", "B");
		cerr << "ooh aah" << flush;
		exit(1);
	} catch (range_error& e) {
		cout << " 0 " << flush;
	}

	assert(l1.mySize == 1);
	assert(l1.getFirst() == "A");
	cout << " 0 " << flush;

	// case of two people in the list, insert before the first person
	l1.insertBefore("A", "B");
	assert(l1.myFirst != l1.myLast);
	assert(l1.getFirst() == "B");
	assert(l1.getLast() == "A");
	cout << " 1 " << flush;

	// case of three people in the list, insert before the second person
	l1.insertBefore("A", "C");
	assert(l1.mySize == 3);
	assert(currPtr->myItem == "B");
	currPtr = currPtr->myNext;
	assert(currPtr->myItem == "C");
	currPtr = currPtr->myNext;
	assert(currPtr->myItem == "A");
	assert(currPtr == l1.myLast);
	cout << " 2 " << flush;

	// case of four people in the list, insert before the first person
	l1.insertBefore("B", "D");
	assert(l1.mySize == 4);
	currPtr = l1.myFirst;
	assert(currPtr->myItem == "D");
	currPtr = currPtr->myNext;
	assert(currPtr->myItem == "B");
	currPtr = currPtr->myNext;
	assert(currPtr->myItem == "C");
	currPtr = currPtr->myNext;
	assert(currPtr->myItem == "A");
	assert(currPtr == l1.myLast);
	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}


void ListTester::testInsertAfter() {
	cout << "insertAfter... " << flush;
	List<string> l1;

	try {
		l1.insertAfter("A", "B");
		cerr << "ooh aah" << flush;
		exit(1);
	} catch (range_error& e) {
		cout << " 0 " << flush;
	}

	List<string>::Node * currPtr = l1.myFirst;
	l1.append("A");

	assert(l1.mySize == 1);
	assert(l1.getFirst() == "A");
	cout << " 1 " << flush;


	// case of two people in the list, insert after the first person
	l1.insertAfter("A", "B");
	assert(l1.mySize == 2);
	//check the items
	assert(l1.getFirst() == "A");
	assert(l1.getLast() == "B");
	//check the pointers
	assert(l1.myFirst != l1.myLast);
	assert(l1.myFirst->myNext == l1.myLast);
	cout << " 2 " << flush;


	// case of three people in the list, insert after the second person
	l1.insertAfter("B", "C");
	assert(l1.mySize == 3);
	//check the items
	assert(currPtr->myItem == "A");
	currPtr = currPtr->myNext;
	assert(currPtr->myItem == "B");
	currPtr = currPtr->myNext;
	assert(currPtr->myItem == "C");
	assert(currPtr == l1.myLast);
	cout << " 3 " << flush;


	// case of four people in the list, insert after the first person
	l1.insertAfter("A", "D");
	assert(l1.mySize == 4);
	//check the items
	assert(currPtr->myItem == "A");
	currPtr = currPtr->myNext;
	assert(currPtr->myItem == "D");
	currPtr = currPtr->myNext;
	assert(currPtr->myItem == "B");
	currPtr = currPtr->myNext;
	assert(currPtr->myItem == "C");
	assert(currPtr == l1.myLast);
	cout << " 4 " << flush;

	cout << " Passed!" << endl;
}


