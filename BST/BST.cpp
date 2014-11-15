#include "BST.h"
#include <iostream>
using namespace std;

BST::BST() {
   root = NULL;
}

void BST::insert(int value) {

    Node* newnode = new Node(value);
    int rightflag = 0;
    if (root == NULL) {
        root = newnode;
    } else {
       Node* current = root;
       Node* prev = current;
        while (current != NULL) {
           if (value >= current->val) {
             prev = current;
             current = current->right;
             rightflag =1;
          } else {
             prev = current;
             current = current->left;
             rightflag =0;
          }
       }
       if (rightflag == 1 ) {
          prev->right = newnode;
       } else {
          prev->left = newnode;
       }
   }
}

void BST::preorder(Node* tnode) {
     cout << tnode->val << endl;
     if (tnode->left != NULL) 
        preorder(tnode->left);
     if (tnode->right != NULL)
        preorder(tnode->right);
}

void BST::inorder(Node* tnode) {
     if (tnode->left != NULL)
        preorder(tnode->left);
     cout << tnode->val << endl;
     if (tnode->right != NULL)
        preorder(tnode->right);
}

void BST::postorder(Node* tnode) {
     if (tnode->left != NULL)
        preorder(tnode->left);
     if (tnode->right != NULL)
        preorder(tnode->right);
     cout << tnode->val << endl;
}

