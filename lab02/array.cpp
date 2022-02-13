/* array.cpp defines "C style" array operations
 * Name: David Yoo (gy24)
 * Date: Sep 14, 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */
 
#include "array.h"

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




