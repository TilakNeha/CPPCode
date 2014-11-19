#include "BST.h"
#include <iostream>
#include <stack>
#include <queue>
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
     cout << tnode->val << " ";
     if (tnode->left != NULL) 
        preorder(tnode->left);
     if (tnode->right != NULL)
        preorder(tnode->right);
}

void BST::inorder(Node* tnode) {
     if (tnode->left != NULL)
        preorder(tnode->left);
     cout << tnode->val << " " ;
     if (tnode->right != NULL)
        preorder(tnode->right);
}

void BST::postorder(Node* tnode) {
     if (tnode->left != NULL)
        preorder(tnode->left);
     if (tnode->right != NULL)
        preorder(tnode->right);
     cout << tnode->val << " ";
}


/*##########################################
Function returns the least common ancestor 
of two nodes.
#########################################*/
int BST::lca(Node* tnode, int val1, int val2) {
      if (val1 < tnode->val && val2 > tnode->val) {
         return tnode->val;
      } else if (val1 < tnode->val && val2 < tnode-> val) {
         return lca(tnode->left,val1,val2);
      } else {
         return lca(tnode->right,val1,val2);
      }
}

void BST::iterative_preorder() {
    stack<Node*> nodestack;
    nodestack.push(root);
    Node* temp;
    cout << endl << "Preorder Traversal: " << endl;
    temp = nodestack.top();
    while(!nodestack.empty()) {
       temp = nodestack.top();
       nodestack.pop();         
       cout << temp->val << " " ;
       if(temp->right) {
          nodestack.push(temp->right);
       }
       if(temp->left) {
          nodestack.push(temp->left);
       }
    }  
    cout << endl; 
}

void BST::BFS() {
    cout << "BFS traversal of tree : " << endl;
    queue<Node*> nodequeue;
    if (root == NULL) {
       cout << "Tree is empty." << endl;
    } else {
       nodequeue.push(root);
       Node* temp;
       while(!nodequeue.empty()) {
            temp = nodequeue.front();
            nodequeue.pop();
            cout << temp->val <<" " ; 
            if (temp->left != NULL) {
               nodequeue.push(temp->left);
            }
            if (temp->right != NULL) {
               nodequeue.push(temp->right);
            }
       }
    }
}

         
