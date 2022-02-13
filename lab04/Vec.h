/* Vec.h provides a simple vector class named Vec.
 * Student Name:ellie sand ens27
 * Date:9/28/21
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */


#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;

template<class Item>

class Vec {
public:
	Vec();
	virtual ~Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	Vec& operator=(const Vec& original);
	unsigned getSize() const {return mySize;}
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	Vec operator+(const Vec& v1);
	Item& operator[](unsigned index);
	Item& operator[](unsigned index) const;
	Vec operator-(const Vec& v1);
	bool operator!=(const Vec<Item>& v2) const;
	Vec<Item> operator*(const Vec<Item>& v1);

private:
	unsigned mySize;
	Item *   myArray;
	friend class VecTester;
};




template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = nullptr;
}

template<class Item>
Vec<Item>::~Vec() {
	delete [] myArray;
	mySize = 0;
	myArray = nullptr;
}

template<class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	if (size == 0) {
		myArray = nullptr;
	} else {
		myArray = new Item[size]();
	}
}

template<class Item>
Vec<Item>::Vec(const Vec<Item>& original) {
	mySize = original.mySize;
	if (mySize > 0) {
		myArray = new Item[mySize]();
		for(unsigned i = 0; i < mySize; ++i){
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = nullptr;
	}
}

template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
	if (myArray != original.myArray){
		if (mySize != original.mySize){
			delete [] myArray;
			myArray = nullptr;
			mySize = original.mySize;
			if (mySize > 0) {
				myArray = new Item[mySize]();
			}
		}
		for(unsigned i = 0; i < mySize; ++i){
			myArray[i] = original.myArray[i];
		}
	}
	return *this;
}

template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if(index >= mySize) {
		throw range_error("setItem index too large");
	}else{
		myArray[index] = it;
	}
}

template<class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if(index >= mySize) {
		throw range_error("getItem index too large");
	}else{
		return myArray[index];
	}
}

template<class Item>
void Vec<Item>::setSize(unsigned newSize) {
	if (mySize != newSize){
		if (newSize == 0) {
			delete [] myArray;
			myArray = nullptr;
			mySize = 0;
		} else  {
			Item* newArray = new Item[newSize]();
			if(mySize < newSize){
				for(unsigned i = 0; i < mySize; ++i){
					newArray[i] = myArray[i];
				}
				for(unsigned i = mySize; i < newSize; ++i){
					newArray[i] = 0;
				}
			}else {
				for(unsigned i = 0; i < newSize; ++i){
					newArray[i] = myArray[i];
				}
			}
			mySize = newSize;
			delete [] myArray;
			myArray = newArray;
		}


	}
}

template<class Item>
bool Vec<Item>::operator==(const Vec<Item>& v2) const {
	if(mySize == v2.mySize){
		for(unsigned i = 0; i < mySize; ++i){
			if (myArray[i] != v2.myArray[i]){
				return false;
			}
		}
		return true;
	}else{
		return false;
	}
}

template<class Item>
bool Vec<Item>::operator!=(const Vec<Item>& v2) const {
	return !((*this)==v2);

}

template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for(unsigned i = 0; i < mySize; ++i){
		out << myArray[i] << endl;
	}
}

template<class Item>
void Vec<Item>::readFrom(istream& in) {
	for(unsigned i = 0; i < mySize; ++i){
		in >> myArray[i];
	}

}
//take in an index and return the item at that index
template<class Item>
Item& Vec<Item>::operator[](unsigned index) {
	if (index >= mySize) {
		throw range_error("index out of range");
	}
	return myArray[index];
}

template<class Item>
Item& Vec<Item>::operator[](unsigned index) const{
	if (index >= mySize) {
		throw range_error("index out of range");
	}
	return myArray[index];
}

//take in a vec, add each index of them together, return a vec with the added values
template<class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& v1){
	if(mySize == v1.mySize){
		Vec v2(mySize);
		for(unsigned i = 0; i < mySize; ++i){
			v2.myArray[i] = myArray[i] + v1.myArray[i] ;
		}
		return v2;
	}else{
		throw invalid_argument("not same size vecs");
	}
}
//take in a vec, subtract each index of them, return a vec with the subtracted values
template<class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& v1){
	if(mySize == v1.mySize){
		Vec v2(mySize);
		for(unsigned i = 0; i < mySize; ++i){
			v2.myArray[i] = myArray[i] - v1.myArray[i] ;
		}
		return v2;
	}else{
		throw invalid_argument("not same size vecs");
	}
}


#endif /*VEC_H_*/
