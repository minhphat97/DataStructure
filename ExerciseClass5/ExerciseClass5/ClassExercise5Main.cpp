#include <iostream>
#include <string>
#include <queue>
#include "ClassExercise5.h"
using namespace std;

int main()
{
	AVL tree1;
    tree1.insert(20);
    tree1.insert(25);
    tree1.insert(27);
    tree1.insert(10);
	tree1.insert(18);
	tree1.insert(21);
	tree1.insert(15);
	tree1.insert(9);
	cout << "Display inorder tree 1: " << endl;
	tree1.inOrder(tree1.getRoot());
	cout << "Display preorder tree 1: " << endl;
	tree1.preOrder(tree1.getRoot());
	cout << "Display postorder tree 1: " << endl;
	tree1.postOrder(tree1.getRoot());
	tree1.remove(9);
	cout << "========================After removing======================== " << endl;
	cout << "Display inorder tree 1: " << endl;
	tree1.inOrder(tree1.getRoot());
	cout << "Display preorder tree 1: " << endl;
	tree1.preOrder(tree1.getRoot());
	cout << "Display postorder tree 1: " << endl;
	tree1.postOrder(tree1.getRoot());
	cout << "The size of tree 1: " << tree1.size(tree1.getRoot()) << endl;
	cout << "The height of tree 1: " << tree1.height(tree1.getRoot()) << endl;
	cout << "The number of children of node which has data 20:  " << tree1.childCount(tree1.getRoot(), 20) << endl; 
	cout << "The number of children of node which has data 25:  " << tree1.childCount(tree1.getRoot(), 25) << endl; 
	cout << "The number of children of node which has data 10:  " << tree1.childCount(tree1.getRoot(), 10) << endl; 
	cout << "The node which has data 21 is in the tree 1 or not: " << tree1.search(tree1.getRoot(), 21) << endl;
	cout << "The node which has data 18 is in the tree 1 or not: " << tree1.search(tree1.getRoot(), 18) << endl;
	cout << "The node which has data 30 is in the tree 1 or not: " << tree1.search(tree1.getRoot(), 30) << endl;
	cout << "The node which has data 20 is the root or not: " << tree1.isRoot(tree1.getRoot(), 20) << endl;
	cout << "The node which has data 25 is the root or not: " << tree1.isRoot(tree1.getRoot(), 25) << endl;
	cout << "The node which has data 18 is the root or not: " << tree1.isRoot(tree1.getRoot(), 18) << endl;
	cout << "The node which has data 20 is internal or not: " << tree1.isInternal(tree1.getRoot(), 20) << endl;
	cout << "The node which has data 15 is internal or not: " << tree1.isInternal(tree1.getRoot(), 15) << endl;
	cout << "The node which has data 25 is internal or not: " << tree1.isInternal(tree1.getRoot(), 25) << endl;
	cout << "The node which has data 20 is external or not: " << tree1.isExternal(tree1.getRoot(), 20) << endl;
	cout << "The node which has data 10 is external or not: " << tree1.isExternal(tree1.getRoot(), 10) << endl;
	cout << "The node which has data 18 is external or not: " << tree1.isExternal(tree1.getRoot(), 18) << endl;
	cout << "This tree is full or not: " << tree1.isFull(tree1.getRoot()) << endl;
	cout << "This tree is complete or not: " << tree1.isComplete(tree1.getRoot()) << endl;
	cout << "This tree is AVL or not: " << tree1.isAVL(tree1.getRoot()) << endl;

	AVL tree2 = tree1;
	cout << "Display inorder tree 2: " << endl;
	tree2.inOrder(tree2.getRoot());
	cout << "Display preorder tree 2: " << endl;
	tree2.preOrder(tree2.getRoot());
	cout << "Display postorder tree 2: " << endl;
	tree2.postOrder(tree2.getRoot());
	AVL tree3;
	tree3 = tree1;
	cout << "Display inorder tree 3: " << endl;
	tree3.inOrder(tree3.getRoot());
	cout << "Display preorder tree 3: " << endl;
	tree3.preOrder(tree3.getRoot());
	cout << "Display postorder tree 3: " << endl;
	tree3.postOrder(tree3.getRoot());

	system("pause");
	return 0;
}