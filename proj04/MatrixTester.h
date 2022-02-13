/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 *student1 : Ellie Sand(ens27)
 *student2: David Yoo(gy24)
 * Date:9/28/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
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
	void testReadSubscript(const Matrix<int>& mat);
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
