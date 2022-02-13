/* array.cpp defines "C style" array operations
 * Name: David Yoo (gy24)
 * Date: Sep 14, 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "array.h"
#include <iostream>
#include <fstream>

void initialize(double *a, unsigned size) {
	int val = 0;
	for (unsigned i = 0; i < size; ++i) {
		val = i+1;
		a[i] = val;
	}
}

void print(double *a, unsigned size) {
	for (unsigned i = 0; i < size; ++i) {
		cout << *a << '\t';
		a++;
	}
}		


double average(double *a, unsigned size) {
	double avg = 0;
	double sum = 0;
	for (unsigned i = 0; i < size; i++){
		sum += *a;  // get the sum of all values in the pointer
		a++;  // increment a, so that we can move to next pointer
	}
	avg = sum / size;  // get the average the sum
	return avg;
}


double sum(double *a, unsigned size){
	double total = 0;
	for (unsigned i = 0; i < size; i++){
		total += *a;  // get the sum of all values in the pointer
		a++;  // increment a, so that we can move to next pointer
	}
	return total;
}


void read(istream& in, double *a, unsigned size){
	for (unsigned i = 0; i < size; i++){
		in >> *a; // read all the values in the pointer
		a++;  // increment a, so that we can move to next pointer
	}
}


void fill(const string& fileName, double *&a, unsigned &numValues){
	ifstream fin(fileName);
	fin >> numValues;
	double *Ptr = a;
	a = new double [numValues]; // dynamically allocate the array
	read(fin, a, numValues); // read the values of the numValues
	delete []Ptr; // return the dynamically allocated array to the system
	fin.close();
}



void resize(double *&a, unsigned oldSize, unsigned newSize){
	// if oldSize < newSize, then copy all values from the old array to new array
	if (oldSize < newSize){
		double *newArray = new double[newSize];  // dynamically allocate the array
		double *Ptr = a;
		for (unsigned i = 0; i < oldSize; i++){
			newArray[i] = a[i];
		}
		for (unsigned i = oldSize; i < newSize; i++){
			newArray[i] = 0;
		}
		delete []Ptr; // return the dynamically allocated array to the system
		a = newArray;

	}
	// if oldSize > newSize, then only the first elements of the array is copied
	if (oldSize > newSize){
		double *newArray = new double[newSize];
		double *Ptr = a;
		for (unsigned i = 0; i < newSize; i++){
			newArray[i] = a[i];
		}
		delete []Ptr; // return the dynamically allocated array to the system
		a = newArray;
	}
}



void concat(double *a1, unsigned size1, double *a2, unsigned size2, double *&a3, unsigned &size3){
	size3 = size1 + size2;
	double *Ptr = a3;
	double *newArray = new double [size3]; // dynamically allocate the array
	for (unsigned i = 0; i < size1; i++){ // pass those values from a1 into a3
		newArray[i] = a1[i];
	}
	for (unsigned i = 0; i < size2; i++){ // pass those values from a2 into a3
		newArray[size1 + i] = a2[i];
	}
	delete []Ptr; // return the dynamically allocated array to the system
	a3 = newArray;
}









