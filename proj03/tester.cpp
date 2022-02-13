/* tester.cpp drives the testing of our Vec class.
 * Student: David Yoo (gy24)
 * Date: Sep 21, 2021
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#include "VecTester.h"
#include "App.h"

int main() {
	VecTester vt;
	vt.runTests();
	App app;
	app.run();
}
