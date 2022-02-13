/*
 * ReversePoem.cpp
 *
 *  Created on: Oct 28, 2021
 *      Author: gy24
 */

#include "ReversePoem.h"
#include <fstream>
#include <cassert>
using namespace std;

ReversePoem::ReversePoem(string filename) {
	ifstream fin(filename);
	assert(fin.is_open());
	getline(fin, myTitle);
	getline(fin, myAuthor);

	Stack<string> body(1);
	string line;
	getline(fin, line);
	while (!fin.eof()) {
		getline(fin, line);
		try {
			body.push(line);
		} catch (StackException& re) {
			body.setCapacity(body.getCapacity() * 2);
			body.push(line);
		}
		myBody += line + '\n';
	}

	unsigned size = body.getSize();
	for (unsigned i = 0; i < size; ++i) {
		string currentline = body.pop();
		myBodyReversed += currentline + '\n';
	}
}

string ReversePoem::getTitle(){
	return myTitle;
}

string ReversePoem::getAuthor(){
	return myAuthor;
}

string ReversePoem::getBody(){
	return myBody;
}

string ReversePoem::getBodyReversed(){
	return myBodyReversed;
}







