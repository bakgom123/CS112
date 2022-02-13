/* Matrix.cpp defines Matrix class methods.
 *student1 : Ellie Sand(ens27)
 *student2: David Yoo(gy24)
 * Date:9/28/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

//#include "Matrix.h"
//
//Matrix::Matrix() {
//	myRows = myColumns = 0;
//}
//
//Matrix::Matrix(unsigned rows, unsigned columns) {
//	myRows = rows;
//	myColumns = columns;
//	myVec.setSize(rows);
//	for (unsigned i = 0; i < rows; i++) {
//		myVec[i].setSize(columns);
//	}
//}
//
//const Vec<Item>& Matrix::operator[](unsigned index) const{
//	return myVec[index];
//}
//
//Vec<Item>& Matrix::operator[](unsigned index){
//	return myVec[index];
//}
//
//bool Matrix::operator==(const Matrix& m2) const {
//	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
//		return false;
//	} else {
//		return myVec == m2.myVec;
//	}
//}
//
////lets you check inequality in a matrix
//bool Matrix::operator!=(const Matrix& m2) const {
//	return !((*this)==m2);
//}
//
////take in an istream file name and read from it into a matrix
//void Matrix::readFrom(istream& in) {
//	for(unsigned i = 0; i < myRows; ++i){
//		for(unsigned j = 0; j < myColumns; ++j){
//			in >> myVec[i][j];
//		}
//	}
//}
//
//void Matrix::readFrom(const string& a) {
//	ifstream in(a);
//	in >> myRows >> myColumns;
//	myVec.setSize(myRows);
//	for(unsigned i = 0; i < myRows; ++i){
//		myVec[i].setSize(myColumns);
//		for(unsigned j = 0; j < myColumns; ++j){
//			in >> myVec[i][j];
//		}
//	}
//}
//
////take in an ostream file, and write to that file
//void Matrix::writeTo(ostream& fout) {
//
//	myVec.setSize(myRows);
//	for(unsigned i = 0; i < myRows; ++i){
//		myVec[i].setSize(myColumns);
//		for(unsigned j = 0; j < myColumns; ++j){
//			cout<< myVec[i][j] << " " <<flush;
//			fout << myVec[i][j] << " " << flush ;
//		}
//	}
//}
//
////take in a string name of a file, and write to that file
//void Matrix::writeTo(string a){
//	ofstream fout(a);
//	fout << myRows << " " << myColumns << endl;
//	myVec.setSize(myRows);
//	for(unsigned i = 0; i < myRows; ++i){
//		myVec[i].setSize(myColumns);
//		for(unsigned j = 0; j < myColumns; ++j){
//			cout<< myVec[i][j] << " " <<flush;
//			fout << myVec[i][j] << " " << flush ;
//		}
//	}
//}
//
////takes in a matrix and adds it to the matrix calling the function, returning a new matrix
//Matrix Matrix::operator+(const Matrix& m1){
//	if(myRows == m1.myRows && myColumns == m1.myColumns){
//		Matrix m2(myRows, myColumns);
//		for(unsigned i = 0; i < myRows; ++i){
//			for(unsigned j = 0; j < myColumns; ++j){
//				m2.myVec[i][j] = myVec[i][j] + m1.myVec[i][j] ;
//			}
//		}
//		return m2;
//	}else{
//		throw invalid_argument("not same size matricies");
//	}
//}
//
//Matrix Matrix::operator-(const Matrix& m1){
//	if(myRows == m1.myRows && myColumns == m1.myColumns){
//		Matrix m2(myRows, myColumns);
//		for(unsigned i = 0; i < myRows; ++i){
//			for(unsigned j = 0; j < myColumns; ++j){
//				m2.myVec[i][j] = myVec[i][j] - m1.myVec[i][j] ;
//			}
//		}
//		return m2;
//	}else{
//		throw invalid_argument("not same size matricies");
//	}
//}
//
////converts matrix rows to columns
//Matrix Matrix::getTranspose(){
//	Matrix m(myColumns, myRows);
//	for(unsigned i = 0; i < myRows; ++i){
//		for(unsigned j = 0; j < myColumns; ++j){
//			m[j][i] = myVec[i][j];
//		}
//	}
//	return m;
//}
//
//
