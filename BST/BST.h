#ifndef BST_H
#define BST_H

#include <iostream>
#include "Node.h"

class BST {

 public :
     BST();
     void insert(int value);
     void preorder(Node* tnode);
     void inorder(Node* tnode);
     void postorder(Node* tnode);
     Node* root;
};

#endif
