/* ListTester.h declares the test-class for class List.
 * student1: Austin Duimstra(amd 83)
 * student2: David Yoo(gy24)
 * Date:10/5/21
 * Joel Adams, for CS 112 at Calvin University.
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
};

#endif /*LISTTESTER_H_*/
