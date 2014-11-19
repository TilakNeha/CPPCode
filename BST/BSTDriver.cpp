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
   cout << endl << "Preorder :" << endl;
   tree.preorder(tree.root);
   cout << endl << "Postorder :" << endl;
   tree.postorder(tree.root);
   cout << endl << "Inorder :" << endl;
   tree.inorder(tree.root);
   tree.iterative_preorder();
   cout << "lca(5,7) = " << tree.lca(tree.root,5,7) << endl;
   tree.BFS();
   return 1;
}
