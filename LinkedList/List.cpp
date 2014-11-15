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
                m_root = m_head;
	}

	List::~List() {
		// TODO Auto-generated destructor stub
	}


void List::insert(int value) {
     Node* newnode = new Node(value);
 
     if (m_head == NULL) {
         m_head = newnode;
     } else {
         Node* current = m_head;
         Node* next = current->m_next;
         while(current->m_val < value) {
              if (next == NULL) {
                 break;
              } else {
                 current = current->m_next;
                 next = current->m_next;
              }
         }
         if(current == m_head && m_head->m_val > value) {
           newnode->m_next = m_head;
           m_head = newnode;
         } else {
           current->m_next = newnode;
           newnode->m_next = next;
         }
     }

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

int List::isPalindrome(Node* m_root, Node* node2) {
      if (node2 == NULL) {
         return 1;
         m_root = m_head;
      }

      int res = isPalindrome(m_root,node2->m_next);
 
      if(res == 0) {
        return 0;
      } else {
        if (m_root->m_val == m_root->m_val) {
           res = 1;
        } else {
           res = 0;
        }
        m_root = m_root->m_next;
        return res;
      }
}

void List::InOrderInsert(int value) {
       Node* newnode = new Node(value);
       if (m_head == NULL) {
          m_head = newnode;
       } else {
          Node* current = m_head;
          while (current->m_next != NULL) {
                current = current->m_next;
          }
          current->m_next = newnode;
      }
} 
