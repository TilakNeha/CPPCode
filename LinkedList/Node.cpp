/*
 * Node.cpp
 *
 *  Created on: Nov 14, 2014
 *      Author: ntilak
 */

#include "Node.h"
#include <iostream>

Node::Node() {
	m_val = 0;
	m_next = NULL;

}
Node::Node(int value) {
	m_val = value;
	m_next = NULL;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}
