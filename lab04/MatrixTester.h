/* MatrixTester.h declares test-methods for class Matrix.
 * students: Ellie Sand(ens27) and David Yoo(gy24)
 * Date:9/28/21
 * Joel C. Adams, for CS 112 at Calvin University.
 */
 
#ifndef MATRIXTESTER_H_
#define MATRIXTESTER_H_

#include "Matrix.h"

class MatrixTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testExplicitConstructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testSubscripts();
	void testReadSubscript(const Matrix& mat);
	void testTranspose();
	void testAddition();
	void testSubtraction();
	void testMultiply();
	void testReadFromStream();
	void testReadFromFile();
	void testWriteToStream();
	void testWriteToFile();
};

#endif /*MATRIXTESTER_H_*/
