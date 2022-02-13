/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 *student1 : Ellie Sand(ens27)
 *student2: David Yoo(gy24)
 * Date:9/28/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Matrix.h"

class Application {
public:
	Application();
	void run();

private:
	void displayMenu() const;
	char getChoice() const;
	void processChoice(char choice);
	Matrix<int> myMatrix;
};

#endif /* APPLICATION_H_ */

