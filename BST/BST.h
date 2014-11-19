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
     int lca(Node* tnode, int val1, int val2);
     void iterative_preorder();
     void BFS();
     Node* root;
};

#endif
