/* Matrix.cpp defines Matrix class methods.
 *students: Ellie Sand(ens27) and David Yoo(gy24)
 * Date:9/28/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "Matrix.h"

Matrix::Matrix() {
	myRows = myColumns = 0;
}

Matrix::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}

const Vec<Item>& Matrix::operator[](unsigned index) const{
		return myVec[index];
}

Vec<Item>& Matrix::operator[](unsigned index){
	return myVec[index];
}

bool Matrix::operator==(const Matrix& m2) const {
   if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
        return false;
   } else {
        return myVec == m2.myVec;
   }
}
