#include "List.h"
#include <iostream>
using namespace std;

int main() {
	List* mylist = new List();
	mylist->insert(4);
	mylist->insert(1);
	mylist->insert(7);
	mylist->insert(2);
	mylist->insert(6);
        mylist->insert(1);
	mylist->display();
        mylist->reverse();
	return 1;

}
