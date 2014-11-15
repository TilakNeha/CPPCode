#include "List.h"
#include <iostream>
using namespace std;

int main() {
	List* mylist = new List();
	mylist->InOrderInsert(1);
	mylist->InOrderInsert(2);
	mylist->InOrderInsert(3);
	mylist->InOrderInsert(4);
	mylist->InOrderInsert(3);
        mylist->InOrderInsert(2);
        mylist->InOrderInsert(1);
	mylist->display();
        //mylist->reverse();
        if (mylist->isPalindrome(mylist->m_head,mylist->m_head) == 1) {
           cout << "List is a Palindrome" << endl;
        } else {
           cout << "List is not a Palindrome." << endl;
        }
//        cout << mylist->m_root->m_val << endl;
//        cout << mylist->m_root->m_next->m_val << endl; 
        mylist->reverse();
        mylist->display();
	return 1;

}
