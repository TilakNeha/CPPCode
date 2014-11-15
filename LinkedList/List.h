/*
 * List.h
 *
 *  Created on: Nov 14, 2014
 *      Author: ntilak
 */

#ifndef LIST_H_
#define LIST_H_
#include "Node.h"
class List {
public:
	List();
	virtual ~List();
	void insert(int value);
        void InOrderInsert(int value);
	void display();
        void reverse();
        int isPalindrome(Node* node1, Node* node2);
	Node* m_head;
        Node* m_root;
};

#endif /* LIST_H_ */
