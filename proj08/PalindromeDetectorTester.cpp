/*
 * PalindromeDetectorTester.cpp defines the test-methods for class PalindromeDetector.
 *
 * Student name: David Yoo (gy24)
 * Date: 11/15/2021
 */

#include "PalindromeDetector.h"
#include "PalindromeDetectorTester.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;


void PalindromeDetectorTester::runTests() {
	cout << "testing class PalindromeDetector..." << endl;
	testConstructor();
	testDetectPalindromes();
	testIsPalindrome();
	cout << "All tests passed!" << endl;
}

void PalindromeDetectorTester::testConstructor() {
	cout << "- Testing constructor..." << flush;
	PalindromeDetector a("inFile.txt", "outFile.txt");
	assert(a.getInputfileTitle() == "inFile.txt");
	assert(a.getOutputfileTitle() == "outFile.txt");
	cout << " 0 " << flush;

	cout << "Passed!" << endl;
}

void PalindromeDetectorTester::testDetectPalindromes(){
	cout << "- Testing detectPalindromes()..." << flush;

	PalindromeDetector a("testPalindrome1.txt", "testDone1");
	a.detectPalindromes();
	cout << " 0 " << flush;

	PalindromeDetector b("testPalindrome2.txt", "testDone2");
	b.detectPalindromes();
	cout << " 1 " << flush;

	PalindromeDetector c("testPalindrome3.txt", "testDone3");
	c.detectPalindromes();
	cout << " 2 " << flush;

	PalindromeDetector d("testPalindrome4.txt", "testDone4");
	d.detectPalindromes();
	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}


void PalindromeDetectorTester::testIsPalindrome() {
	cout << "- Testing isPalindrome()..." << flush;
	PalindromeDetector a("infile.txt", "outfile.txt");

	assert(!a.isPalindrome(""));
	cout << " 0 " << flush;

	assert(a.isPalindrome("Nun"));
	cout << " 1 " << flush;

	assert(a.isPalindrome("Madam"));
	cout << " 2 " << flush;

	assert(a.isPalindrome("Civic"));
	cout << " 3 " << flush;

	assert(a.isPalindrome("Borrow or rob?"));
	cout << " 4 " << flush;

	cout << "Passed!" << endl;
}
