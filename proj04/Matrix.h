/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 *student1 : Ellie Sand(ens27)
 *student2: David Yoo(gy24)
 * Date:9/28/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"

template<class Item>

class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	unsigned getRows() const {return myRows;}
	unsigned getColumns() const {return myColumns;}
	const Vec<Item>& operator[](unsigned index) const;
	Vec<Item>& operator[](unsigned index);
	bool operator==(const Matrix& m2) const;
	bool operator!=(const Matrix& m2) const;
	void readFrom(istream& in);
	void readFrom(const string& a);
	void writeTo(ostream& fout);
	void writeTo(string a);
	Matrix operator+(const Matrix& m1);
	Matrix operator-(const Matrix& m1);
	Matrix getTranspose();


private:
	unsigned         myRows;
	unsigned         myColumns;
	Vec< Vec<Item> > myVec;
	friend class MatrixTester;
};

template<class Item>
Matrix<Item>::Matrix() {
	myRows = myColumns = 0;
}

template<class Item>
Matrix<Item>::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}

template<class Item>
const Vec<Item>& Matrix<Item>::operator[](unsigned index) const{
	return myVec[index];
}

template<class Item>
Vec<Item>& Matrix<Item>::operator[](unsigned index){
	return myVec[index];
}

template<class Item>
bool Matrix<Item>::operator==(const Matrix<Item>& m2) const {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return false;
	} else {
		return myVec == m2.myVec;
	}
}

//lets you check inequality in a matrix
template<class Item>
bool Matrix<Item>::operator!=(const Matrix<Item>& m2) const {
	return !((*this)==m2);
}

//take in an istream file name and read from it into a matrix
template<class Item>
void Matrix<Item>::readFrom(istream& in) {
	for(unsigned i = 0; i < myRows; ++i){
		for(unsigned j = 0; j < myColumns; ++j){
			in >> myVec[i][j];
		}
	}
}

template<class Item>
void Matrix<Item>::readFrom(const string& a) {
	ifstream in(a);
	in >> myRows >> myColumns;
	myVec.setSize(myRows);
	for(unsigned i = 0; i < myRows; ++i){
		myVec[i].setSize(myColumns);
		for(unsigned j = 0; j < myColumns; ++j){
			in >> myVec[i][j];
		}
	}
	in.close();
}

//take in an ostream file, and write to that file
template<class Item>
void Matrix<Item>::writeTo(ostream& fout) {

	myVec.setSize(myRows);
	for(unsigned i = 0; i < myRows; ++i){
		myVec[i].setSize(myColumns);
		for(unsigned j = 0; j < myColumns; ++j){
			cout<< myVec[i][j] << " " <<flush;
			fout << myVec[i][j] << " " << flush ;
		}
	}
}

//take in a string name of a file, and write to that file
template<class Item>
void Matrix<Item>::writeTo(string a){
	ofstream fout(a);
	fout << myRows << " " << myColumns << endl;
	myVec.setSize(myRows);
	for(unsigned i = 0; i < myRows; ++i){
		myVec[i].setSize(myColumns);
		for(unsigned j = 0; j < myColumns; ++j){
			cout<< myVec[i][j] << " " <<flush;
			fout << myVec[i][j] << " " << flush ;
		}
		fout << endl;
	}
}

//takes in a matrix and adds it to the matrix calling the function, returning a new matrix
template<class Item>
Matrix<Item> Matrix<Item>::operator+(const Matrix<Item>& m1){
	if(myRows == m1.myRows && myColumns == m1.myColumns){
		Matrix<Item> m2(myRows, myColumns);
		for(unsigned i = 0; i < myRows; ++i){
			for(unsigned j = 0; j < myColumns; ++j){
				m2.myVec[i][j] = myVec[i][j] + m1.myVec[i][j] ;
			}
		}
		return m2;
	}else{
		throw invalid_argument("not same size matricies");
	}
}

template<class Item>
Matrix<Item> Matrix<Item>::operator-(const Matrix<Item>& m1){
	if(myRows == m1.myRows && myColumns == m1.myColumns){
		Matrix<Item> m2(myRows, myColumns);
		for(unsigned i = 0; i < myRows; ++i){
			for(unsigned j = 0; j < myColumns; ++j){
				m2.myVec[i][j] = myVec[i][j] - m1.myVec[i][j] ;
			}
		}
		return m2;
	}else{
		throw invalid_argument("not same size matricies");
	}
}

//converts matrix rows to columns
template<class Item>
Matrix<Item> Matrix<Item>::getTranspose(){
	Matrix<Item> m(myColumns, myRows);
	for(unsigned i = 0; i < myRows; ++i){
		for(unsigned j = 0; j < myColumns; ++j){
			m[j][i] = myVec[i][j];
		}
	}
	return m;
}



#endif
