///* part1.cpp
// * Name: David Yoo (gy24)
// * Date: Sep 13, 2021
// * Begun by: Joel Adams, for CS 112 at Calvin University.
// */
//
//#include <iostream>
//using namespace std;
//
//int main() {
//	long double   ldoubleVal;
//	double        doubleVal;
//	float         floatVal;
//	long          longVal;
//	int           intVal;
//	short         shortVal;
//	char          charVal1;
//	char          charVal2;
//	bool          boolVal;
//
//	long double * ldPtr;
//	double *      dPtr;
//	float *       fPtr;
//	long *        lPtr;
//	int *         iPtr;
//	short *       sPtr;
//	char *        cPtr;
//	bool *        bPtr;
//
/*
 * Get the addresses and sizes of the variables
 */
//	cout << "long double" << " " << &ldoubleVal << " " << sizeof(ldoubleVal) << endl;
//	cout << "double" << " " << &doubleVal << " " << sizeof(doubleVal) << endl;
//	cout << "float" << " " << &floatVal << " " << sizeof(floatVal) << endl;
//	cout << "long" << " " << &longVal << " " << sizeof(longVal) << endl;
//	cout << "int" << " " << &intVal << " " << sizeof(intVal) << endl;
//	cout << "short" << " " << &shortVal << " " << sizeof(shortVal) << endl;
//	cout << "charVal1: " << static_cast<void*>(&charVal1) << " " << sizeof(charVal1) << endl;
//	cout << "charVal2: " << static_cast<void*>(&charVal2) << " " << sizeof(charVal2) << endl;
//	cout << "bool" << " " << &boolVal << " " << sizeof(boolVal) << endl;
//
//	cout << endl;
//
//	cout << "long double" << " " << &ldPtr << " " << sizeof(ldPtr) << endl;
//	cout << "double" << " " << &dPtr << " " << sizeof(dPtr) << endl;
//	cout << "float" << " " << &fPtr << " " << sizeof(fPtr) << endl;
//	cout << "long" << " " << &lPtr << " " << sizeof(lPtr) << endl;
//	cout << "int" << " " << &iPtr << " " << sizeof(iPtr) << endl;
//	cout << "short" << " " << &sPtr << " " << sizeof(sPtr) << endl;
//	cout << "char: " << static_cast<void*>(&cPtr) << " " << sizeof(cPtr) << endl;
//	cout << "bool" << " " << &bPtr << " " << sizeof(bPtr) << endl;
//
//
//}
