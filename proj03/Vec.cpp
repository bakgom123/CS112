/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: David Yoo (gy24)
 * Date: Sep 21, 2021
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#include "Vec.h"
#include <stdexcept>
#include <iostream>
#include <fstream>

// The Default constructor
Vec::Vec() {
	mySize = 0;
	myArray = nullptr;
}

//The Explicit-value constructor
Vec::Vec(unsigned size) {
	mySize = size;
	if (size > 0){
		myArray = new Item[size]();
	}
	else{
		myArray = nullptr;
	}
}

// The Copy constructor
Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (mySize > 0){
		myArray = new Item[mySize]();
		for (unsigned i = 0; i < mySize; ++i){
			myArray[i] = original.myArray[i];
		}
	}
	else{
		myArray = nullptr;
	}
}

// The Destructor
Vec::~Vec() {
	delete [] myArray;
	myArray = nullptr;
	mySize = 0;
}


// The Assignment operator
Vec& Vec::operator=(const Vec& original) {
	if (this != &original){
		if (mySize != original.mySize){
			if (mySize > 0){
				delete [] myArray;
				myArray = nullptr;
			}
			if(original.mySize > 0){
				myArray = new Item[original.mySize]();
			}
			mySize = original.mySize;
		}
	}
	for (unsigned i = 0; i < mySize; ++i){
		myArray[i] = original.myArray[i];
	}
	return *this;
}


// Getting a Vec's Size
unsigned Vec::getSize() const {
	return mySize;
}


// Setting the Value of an Item
void Vec::setItem(unsigned index, const Item& it) {
	if (index >= mySize){
		throw range_error("Invalid index!");
	}
	else{
		myArray[index] = it;
	}
}


// Getting the Value of an Item
Item Vec::getItem(unsigned index) const {
	if (index >= mySize){
		throw range_error("Invalid index!");
	}
	else{
		return myArray[index];
	}
}


// Setting a Vec's Size
void Vec::setSize(unsigned newSize){
	if (mySize != newSize){
		if (newSize == 0){
			delete [] myArray;
			myArray = nullptr;
			mySize = 0;
		}
		else{
			Item *newArray = new Item[newSize]();
			if (mySize < newSize){
				for (unsigned i = 0; i < mySize; ++i){
					newArray[i] = myArray[i];
				}
				for (unsigned i = mySize; i < newSize; ++i){
					newArray[i] = 0;
				}
			}
			else{
				for (unsigned i = 0; i < newSize; ++i){
					newArray[i] = myArray[i]; //copy newSize values from myArray into newArray.
				}
			}
			mySize = newSize;
			delete []myArray;
			myArray = newArray;
		}
	}
}


// Equality
bool Vec::operator==(const Vec& v2) const {
	if (mySize == v2.mySize){
		for (unsigned i = 0; i < mySize; i++){
			if (myArray[i] != v2.myArray[i]){
				return false;
			}
		}
		return true;
	}
	return false;
}



// ostream Output
void Vec::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; ++i){
		out << myArray[i] << endl;
	}
}


// istream Input
void Vec::readFrom(istream& in) {
	for (unsigned i = 0; i < mySize; ++i){
		in >> myArray[i];
	}
}


// index operator change the item
Item& Vec::operator[](unsigned index) {
	if (index >= mySize){
		throw range_error("Invalid index!");
	}
	else{
		return myArray[index];
	}

}

// index operator get the item
Item& Vec::operator[](unsigned index) const {
	if (index >= mySize){
		throw range_error("Invalid index!");
	}
	else{
		return myArray[index];
	}

}

// Vector addition
Vec Vec::operator +(const Vec& v){
	if (mySize != v.mySize){
		throw invalid_argument("Bad!");
	}
	Vec v3;
	v3.mySize = mySize;
	v3.myArray = new Item[mySize];
	for (unsigned i = 0; i < v3.mySize; ++i){
		v3.myArray[i] = myArray[i] + v.myArray[i];
	}
	return v3;
}

// Substraction
Vec Vec::operator -(const Vec& v){
	if (mySize != v.mySize){
		throw invalid_argument("Bad!");
	}
	Vec v3;
	v3.mySize = mySize;
	v3.myArray = new Item[mySize];
	for (unsigned i = 0; i < v3.mySize; ++i){
		v3.myArray[i] = myArray[i] - v.myArray[i];
	}
	return v3;
}






