/*
 * Node.h
 *
 *  Created on: Nov 14, 2014
 *      Author: ntilak
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	Node();
	Node(int value);
	virtual ~Node();
	int m_val;
	Node* m_next;
};

#endif /* NODE_H_ */
