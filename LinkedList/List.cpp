/*
 * List.cpp
 *
 *  Created on: Nov 14, 2014
 *      Author: ntilak
 */

#include "List.h"
#include "Node.h"
#include <iostream>
using namespace std;

List::List() {
	m_head = NULL;

}

List::~List() {
	// TODO Auto-generated destructor stub
}

void List::insert(int value) {
	Node* temp = new Node(value);
	if (m_head == NULL) {
		m_head = temp;
	} else {
		Node* current = m_head;
		Node* prev = NULL;
		while(current->m_val <= value && current->m_next != NULL) {
			prev = current;
			current = current->m_next;
		}
		if(current == m_head) {
			temp->m_next = m_head;
			m_head = temp;
		} else if (current->m_next == NULL && current->m_val < value) {
		        current->m_next = temp;
                        temp->m_next = NULL;
                } else {
                        prev->m_next = temp;
                        temp->m_next = current;
		}

	}
cout << "Head =" << m_head->m_val << endl;
}

void List::display() {
	Node* current = m_head;
	if(m_head == NULL) {
		cout << "List is empty!" << endl;
	} else {
		while(current != NULL) {
			cout << current->m_val << "  --> " ;
			current = current->m_next;
		}
		cout << " NULL" << endl;
	}
}

void List::reverse() {
    if (m_head == NULL) {
        cout << "List is empty!" << endl;
    } else {
        Node* n1 = m_head;
        Node* n2 = m_head->m_next;
        Node* n3 = NULL;

        while (n2 != NULL) {
           n1 = m_head;
           n2 = n1->m_next;
           n1->m_next = n3;
           if(n2 != NULL) {m_head = n2;}
           n3 = n1; 
        }
     }
     display();
}
