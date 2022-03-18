
#include "BST_Tester.h"
#include "BST.h"
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

BST<long> analyze(const string& filename) {
	ifstream fin(filename.c_str());

	unsigned duplicate_num = 0;
	string currentline;
	BST<long> bst;
	unsigned loopcount = 0;
	while(true) {
		long insertNum;
		fin >> insertNum;
		if(!fin) break;
		try {
			bst.insert(insertNum);
		}
		catch (Exception& ex) {
			++duplicate_num;
		}
		++loopcount;
	}
	unsigned height = bst.getHeight();
	cout << "filename: " << filename << ", height: " << height << ", duplicates: " << duplicate_num << ", items:" << loopcount << endl;
	fin.close();
	return bst;
}

int main() {
	BST_Tester bstt;
	bstt.runTests();

	//testing analyze
	BST<long> bst1 = analyze("randomInts01.txt");
	assert(bst1.getHeight()==47);

	BST<long> bst2 = analyze("randomInts02.txt");
	assert(bst2.getHeight()==49);

	BST<long> bst3 = analyze("randomInts03.txt");
	assert(bst3.getHeight()==47);

	//prompting for user input
	cout << "Enter the name of an input file: " << flush;
	string filename;
	cin >> filename;
	analyze(filename);

}

