#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
public:
     Node();
     Node(int value);
     int val;
     Node* left;
     Node* right;
};
#endif
