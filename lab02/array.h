/* array.h declares "C style" array operations.
 * Name: David Yoo (gy24)
 * Date: Sep 14, 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */
 
#include <iostream>
#include <cassert>
using namespace std;

void initialize(double *a, unsigned size);

void print(double *a, unsigned size);

double average(double *a, unsigned size);
