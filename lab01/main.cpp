/* main.cpp tests the classes in our project.
 *
 * Student 1 Name and UserId: David Yoo (gy24)
 * Student 2 Name and UserId:
 * Date: Sep 4, 2021
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "SongTester.h"
#include "PlayListTester.h"

int main() {
	SongTester sTester;
	sTester.runTests();
	PlayListTester plTester;
	plTester.runTests();
}

