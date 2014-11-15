#include<iostream>
#include "BST.h"
using namespace std;
int main() {

   BST tree = BST();
   tree.insert(4);
   tree.insert(6);
   tree.insert(2);
   tree.insert(3);
   tree.insert(7);
   tree.insert(5);
   cout << "Preorder :" << endl;
   tree.preorder(tree.root);
   cout << "Postorder :" << endl;
   tree.postorder(tree.root);
   cout << "Inorder :" << endl;
   tree.inorder(tree.root);
   return 1;
}
