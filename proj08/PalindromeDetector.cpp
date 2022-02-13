/*
 * PalindromeDetector.cpp defines the methods for class PalindromeDetector.
 *
 * Student name: David Yoo (gy24)
 * Date: 11/15/2021
 */

#include "PalindromeDetector.h"
#include <cctype>
#include <cassert>
using namespace std;


PalindromeDetector::PalindromeDetector(const string& inputFile, const string& outputFile) {
	myInFile = inputFile;
	myOutFile = outputFile;
}


void PalindromeDetector::detectPalindromes() const {
	ifstream fin(myInFile);
	assert(fin.is_open());
	ofstream fout(myOutFile);
	assert(fout.is_open());
	while(!fin.eof()) {
		string line;
		getline(fin, line);
		fout << line;

		if (isPalindrome(line)){
			fout << "***";
		}
		fout << "\n";
	}
	fin.close();
	fout.close();
}



bool PalindromeDetector::isPalindrome(string str) const {
	Stack<char> s1(1);
	ArrayQueue<char> q1(1);
	if (str.size() == 0) {
		return false;
	}
	for (unsigned i = 0; i < str.size(); i++) {
		char c = str[i];
		if (isalpha(c)) {
			c = tolower(c);
			try {
				s1.push(c);
			}
			catch (StackException& se) {
				s1.setCapacity(s1.getCapacity() * 2);
				s1.push(c);
			}
			try {
				q1.append(c);
			}
			catch (QueueException& qe) {
				q1.setCapacity(q1.getCapacity() * 2);
				q1.append(c);
			}
		}
	}
	while(!s1.isEmpty() && !q1.isEmpty()) {
		char c1 = s1.pop();
		char c2 = q1.remove();
		if (c1 != c2) {
			return false;
		}
	}
	return true;
};
