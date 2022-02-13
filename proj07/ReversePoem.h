/*
 * ReversePoem.h
 *
 *  Created on: Oct 28, 2021
 *      Author: gy24
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_
#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

class ReversePoem {
public:
	ReversePoem(string filename);
	string getTitle();
	string getAuthor();
	string getBody();
	string getBodyReversed();


private:
	string myTitle;
	string myAuthor;
	string myBody;
	string myBodyReversed;


};

#endif /* REVERSEPOEM_H_ */
