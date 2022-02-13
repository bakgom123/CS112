/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 *student1 : Ellie Sand(ens27)
 *student2: David Yoo(gy24)
 * Date:9/28/21
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "Application.h"
#include "Matrix.h"

#include <iostream>
#include<string>
#include<cassert>
#include<vector>
#include<fstream>
using namespace std;

Application::Application() {
	string fname;
	cout << "Welcome to the matrix Manager" << endl << endl;
	cout << "Please enter a file containing a matrix:" << flush;
	getline(cin, fname);
	myMatrix.readFrom(fname);


}

/*
 * Run the application.
 */
void Application::run() {
	while (true) {
		displayMenu();
		char choice = getChoice();
		cout << "got choice " << choice << endl;
		if (choice == 'q') {
			break;
		}
		processChoice(choice);
	}
}

void Application::displayMenu() const {
	cout << "Please enter:" << endl;
	cout << "a - to add a matrix" << endl;
	cout << "s - to subtract a matrix" << endl;
	cout << "t - to transpose a matrix" << endl;
	cout << "q - to quit" << endl;
}

char Application::getChoice() const {
	cout << endl << "Please enter your choice: " << flush;
	char choice;
	cin >> choice;
	cin.get();
	return choice;
}

void Application::processChoice(char choice) {
	switch(choice) {
	case 'a': {
		string fname;
		Matrix<int> mat;
		cout << "Please enter a file containing a matrix:" << flush;
		getline(cin, fname);
		mat.readFrom(fname);
		Matrix<int> mat1 = myMatrix + mat;
		for(unsigned i = 0; i < mat1.getRows(); ++i){
			for(unsigned j = 0; j < mat1.getColumns(); ++j){
				cout << mat1[i][j] << " " << flush;
			}
			cout << endl;
		}
		break;
	}
	case 's': {
		string fname;
		Matrix<int> mat;
		cout << "Please enter a file containing a matrix:" << flush;
		getline(cin, fname);
		mat.readFrom(fname);
		Matrix<int> mat1 = myMatrix - mat;
		for(unsigned i = 0; i < mat1.getRows(); ++i){
			for(unsigned j = 0; j < mat1.getColumns(); ++j){
				cout << mat1[i][j] << " " << flush;
			}
			cout << endl;
		}

		break;
	}
	case 't': {
		string fname;
		Matrix<int> mat;

		Matrix<int> mat1 = myMatrix.getTranspose();
		for(unsigned i = 0; i < mat1.getRows(); ++i){
			for(unsigned j = 0; j < mat1.getColumns(); ++j){
				cout << mat1[i][j] << " " << flush;
			}
			cout << endl;
		}


		break;
	}
	}


}

