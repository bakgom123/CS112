/*
 * PalindromeDetector.h declares a PalindromeDetector class.
 *
 * Student name: David Yoo (gy24)
 * Date: 11/15/2021
 */

#ifndef PALINDROMEDETECTOR_H_
#define PALINDROMEDETECTOR_H_

#include <iostream>
#include <fstream>
#include "Stack.h"
#include "ArrayQueue.h"
#include <string>
using namespace std;

class PalindromeDetector {
public:
	PalindromeDetector(const string& inputFile, const string& outputFile);
	void detectPalindromes() const;
	bool isPalindrome(string str) const;
	string getInputfileTitle() {return myInFile;}
	string getOutputfileTitle() {return myOutFile;}
private:
	string myInFile;
	string myOutFile;
};

#endif /* PALINDROMEDETECTOR_H_ */
