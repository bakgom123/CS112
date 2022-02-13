/* tester.cpp drives the testing of the Queue classes.
 * Joel Adams, for CS 112 at Calvin University.
 */

#include "ArrayQueueTester.h"
#include "LinkedQueueTester.h"
#include "PalindromeDetector.h"
#include "PalindromeDetectorTester.h"

int main() {
	ArrayQueueTester aqt;
	aqt.runTests();
	LinkedQueueTester lqt;
	lqt.runTests();
	PalindromeDetectorTester pdt;
	pdt.runTests();
}

