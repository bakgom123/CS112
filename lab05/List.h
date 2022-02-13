/*
 * List.h
 * student1 : Austin Duimstra(amd 83)
 * student2: David Yoo(gy24)
 * Date:10/5/21
 */

#ifndef LIST_H_
#define LIST_H_
typedef double Item;

class List {
public:
	List();
	virtual ~List();
	friend class ListTester;
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	List(const List& original);
	List& operator=(const List& rhs);


private:
	struct Node {
		Node();
		Item myItem;
		Node *myNext;
		Node(Item it, Node *next);
		~Node();
	};

	Node * myFirst;
	Node * myLast;
	unsigned mySize;


};


#endif /* LIST_H_ */
