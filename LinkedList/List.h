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
	void display();
        void reverse();
	Node* m_head;
};

#endif /* LIST_H_ */
