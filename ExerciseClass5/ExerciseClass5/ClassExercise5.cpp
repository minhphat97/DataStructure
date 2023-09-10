#include <iostream>
#include <string>
#include "ClassExercise5.h"
#include <queue>
using namespace std;

//Pre: Nothing is changed.
//Post: This function will return the address which is pointed by pointer root.
Node* AVL::getRoot()
{
	return root;
}
//Pre: Nothing is changed.
//Post: This function will return the height of AVL tree.
int AVL::height(Node* N)//In lecture notes, the height of empty tree is -1, but the sample code in AVL lecture is 0 ???
{
	if(N == nullptr)
	{
		return -1;
	}
	return N->height;
}
//Pre: Nothing is changed.
//Post: This function will return the max value between 2 variables.
int AVL::max(int a, int b)
{
	if(a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
//Pre: Nothing is changed.
//Post: This function will return the balance factor of one node in the AVL tree.
int AVL::getBalance(Node* N)
{
	if(N == nullptr)
	{
		return 0;
	}
	return (height(N->left) - height(N->right));
}
//Pre: Nothing is changed.
//Post: This function will create the new node which will be inserted into AVL tree.
Node*AVL::newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->height = 0;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}
//Pre: Nothing is changed.
//Post: This function will insert a new node into AVL tree. 
Node*AVL::insert(int data, Node* root)
{
	//Step 1: Perform the normal BST insertion
	if(root == nullptr)
	{
		return newNode(data);
	}
	if(data < root->data)
	{
		root->left = insert(data, root->left);
	}
	else if(data > root->data)
	{
		root->right = insert(data, root->right);
	}
	else
	{
		return root;
	}
	//Step 2: Update height of this ancestor node
	root->height = 1 + max(height(root->left), height(root->right));
	//Step 3: Get the balance factor of this ancestor node to check whether this node became unbalanced
	int balance = getBalance(root);
	//Left Left Case, then single right rotate
	if(balance > 1 && data < root->left->data)
	{
		return singleRightRotate(root);
	}
	//Right Right Case, then single left rotate
	if(balance < -1 && data > root->right->data)
	{
		return singleLeftRotate(root);
	}
	//Left Right Case, then single left rotate then single right rotate 
	if(balance > 1 && data > root->left->data)
	{
		//root->left = singleLeftRotate(root->left);
		return doubleLeftRightRotate(root);
	}
	//Right Left Case, then single right rotate then single left rotate
	if (balance < -1 && data < root->right->data)
	{
		//root->right = singleRightRotate(root->right);
		return doubleRightLeftRotate(root);
	}
	return root;
}
//Pre: Nothing is changed.
//Post: This function will do single right rotate to make sure AVL tree is balanced. 
Node* AVL::singleRightRotate(Node*&y)
{
	Node* x = y->left;
	Node* T2 = x->right;
	//Rotate process 
	x->right = y;
	y->left = T2;
	//Update new heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	return x;
}
//Pre: Nothing is changed.
//Post: This function will do single left rotate to make sure AVL tree is balanced. 
Node*AVL::singleLeftRotate(Node*&x)
{
	Node* y = x->right;
	Node* T2 = y->left;
	//Rotate process
	y->left = x;
	x->right = T2;
	//Update new heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	return y;
}
//Pre: The balance factor is not between -1 and 1.
//Post : The balance factor will be between -1 and 1.
Node* AVL::doubleRightLeftRotate(Node*& node)//Similar Right Left Case
{
	node->right = singleRightRotate(node->right);
	return singleLeftRotate(node);
}
//Pre: The balance factor is not between -1 and 1.
//Post : The balance factor will be between -1 and 1.
Node* AVL::doubleLeftRightRotate(Node*& node)//Similar Left Right Case
{
	node->left = singleLeftRotate(node->left);
	return singleRightRotate(node);
}
//Pre: Nothing is changed.
//Post: This function will find the minimum node in the AVL tree. 
Node* AVL::findMin(Node* node)
{
	Node* current = node;
	while(current->left != nullptr)
	{
		current = current->left;
	}
	return current;
}
//Pre: Nothing is changed.
//Post: This function will find the maximum in the AVL tree.
Node*AVL::findMax(Node* node)
{
	Node* current = node;
	while(current->right != nullptr)
	{
		current = current->right;
	}
	return current;
}
//Pre: Nothing is changed.
//Post: This function will remove a node from AVL tree.
Node*AVL::remove(int data, Node* root)
{
	//Step 1: Perform standard BST delete
	if(root == nullptr)
	{
		return root;
	}
	if(data < root->data)
	{
		root->left = remove(data, root->left);
	}
	else if(data > root->data)
	{
		root->right = remove(data, root->right);
	}
	else
	{
		if((root->left == nullptr) || (root->right == nullptr))//Case has one child or no child
		{
			Node* temp = root->left? root->left:root->right; //root->right will be assigned to temp if root->left is nullptr
			if(temp == nullptr) //Case has no child
			{
				temp = root;
				root = nullptr;
			}
			else //Case has one child, we have to copy contents of non-empty child to the root node and delete the pointer of child node 
			{
				*root = *temp;
			}
			delete temp;
		}
		else//Case has two children
		{
			Node* temp = findMin(root->right);
			root->data = temp->data; //Copy the inorder successor's data to this node
			root->right = remove(temp->data,root->right);
		}
	}
	if(root == nullptr)
	{
		return root;
	}
	//Step 2: Update height of this ancestor node
	root->height = 1 + max(height(root->left), height(root->right));
	//Step 3: Get the balance factor of this ancestor noe to check whether this node became unbalanced
	int balance = getBalance(root);
	//Left Left Case, then single right rotate
	if(balance > 1 && data < root->left->data)
	{
		return singleRightRotate(root);
	}
	//Right Right Case, then single left rotate
	if(balance < -1 && data > root->right->data)
	{
		return singleLeftRotate(root);
	}
	//Left Right Case, then single left rotate then single right rotate 
	if(balance > 1 && data > root->left->data)
	{
		//root->left = singleLeftRotate(root->left);
		return doubleLeftRightRotate(root);
	}
	//Right Left Case, then single right rotate then single left rotate
	if (balance < -1 && data < root->right->data)
	{
		//root->right = singleRightRotate(root->right);
		return doubleRightLeftRotate(root);
	}
	return root;
}
//Pre: Nothing is changed.
//Post: This function will return address of a node's parent.
Node*AVL::parent(Node* root, int data)//I assume that this function will find the parent of node which has the given data.
{
	if(root == nullptr)
	{
		return root;
	}
	else if(root->right == nullptr && root->left == nullptr)//root->height == 0 does not work ???!!!
	{
		return nullptr;
	}
	else if(root->left != nullptr && root->left->data == data)
	{
		return root;
	}
	else if(root->right != nullptr && root->right->data == data)
	{
		return root;
	}
	else if(data < root->data)
	{
		return parent(root->left,data);
	}
	else if(data > root->data)
	{
		return parent(root->right,data);
	}
	else
	{
		cout << "Something wrong happen ! You are trying to find parent of root node or given data does not exist in this AVL tree !" << endl;
	}
}
//Pre: Nothing is changed.
//Post: This function will return the number of children of a node.
int AVL::childCount(Node* root, int data)//I assume that this function will count the number of children of node which has the given data.
{
	if(root == nullptr)
	{
		return -1;
	}
	else if(root->data == data && root->left == nullptr && root->right == nullptr)
	{
		return 0;
	}
	else if(root->data == data && root->left == nullptr && root->right != nullptr)
	{
		return 1;
	}
	else if(root->data == data && root->left != nullptr && root->right == nullptr)
	{
		return 1;
	}
	else if(root->data == data && root->left != nullptr && root->right != nullptr)
	{
		return 2;
	}
	else if(data < root->data)
	{
		return childCount(root->left,data);
	}
	else if(data > root->data)
	{
		return childCount(root->right,data);
	}
	else
	{
		cout << "Something wrong happen ! Given data does not exist in this AVL tree !" << endl;
	}
}
//Pre: Nothing is changed.
//Post: This funtion will find the node has the same data with parameter.
bool AVL::search(Node* root, int data)
{
	if(root == nullptr)
	{
		return false;
	}
	else if(root->data == data)
	{
		return true;
	}
	else if(data < root->data)
	{
		return search(root->left, data);
	}
	else
	{
		return search(root->right, data);
	}
}
//Pre: Nothing is changed.
//Post: This function will return the height of tree and this function does not have any parameters. This is useful for isRoot function.
int AVL::originalHeight()
{
	return height(root);
}
//Pre: Nothing is changed.
//Post: This function will check a node whether it is a root or not.
bool AVL::isRoot(Node* root, int data)//Firstly, I will search the node has the given data, then I will check its height to know that it is root node or not
{
	if(root == nullptr)
	{
		return false;
	}
	else if(root->data == data && root->height == originalHeight())
	{
		return true;
	}
	else if(root->data == data && root->height != originalHeight())
	{
		return false;
	}
	else if(data < root->data)
	{
		return isRoot(root->left, data);
	}
	else if(data > root->data)
	{
		return isRoot(root->right, data);
	}
}

//Pre: Nothing is changed.
//Post: This function will check a node is internal or not.
bool AVL::isInternal(Node* root, int data)
{
	if(root == nullptr)
	{
		return false;
	}
	else if(isRoot(root, data) == true)
	{
		return false;
	}
	else if(root->data == data && root->left == nullptr && root->right == nullptr)
	{
		return false;
	}
	else if(root->data == data && root->left == nullptr && root->right != nullptr)
	{
		return true;
	}
	else if(root->data == data && root->left != nullptr && root->right == nullptr)
	{
		return true;
	}
	else if(root->data == data && root->left != nullptr && root->right != nullptr)
	{
		return true;
	}
	else if(data < root->data)
	{
		return isInternal(root->left,data);
	}
	else if(data > root->data)
	{
		return isInternal(root->right,data);
	}
	else
	{
		return false;
	}
}
//Pre: Nothing is changed.
//Post: This function will check a node is external or not.
bool AVL::isExternal(Node* root, int data)
{
	if(root == nullptr)
	{
		return false;
	}
	else if(isRoot(root, data) == true)
	{
		return false;
	}
	else if(root->data == data && root->left == nullptr && root->right == nullptr)
	{
		return true;
	}
	else if(root->data == data && root->left == nullptr && root->right != nullptr)
	{
		return false;
	}
	else if(root->data == data && root->left != nullptr && root->right == nullptr)
	{
		return false;
	}
	else if(root->data == data && root->left != nullptr && root->right != nullptr)
	{
		return false;
	}
	else if(data < root->data)
	{
		return isExternal(root->left,data);
	}
	else if(data > root->data)
	{
		return isExternal(root->right,data);
	}
	else
	{
		return false;
	}	
}
//Pre: Nothing is changed.
//Post: This function will return the size of AVL tree.
int AVL::size(Node* root)
{
	if(root == nullptr)
	{
		return 0;
	}
	else if(root != nullptr)
	{
		return (1 + size(root->left) + size(root->right));
	}
}
//Pre: Nothing is changed.
//Post: All nodes will be printed of order Left, Root, Right.
void AVL::inOrder(Node* root)
{
	if(root != nullptr)
	{
		inOrder(root->left);
		cout << root->data << " " << endl;
		inOrder(root->right);
	}
	return;
}
//Pre: Nothing is changed.
//Post: All nodes will be printed of order Left, Right, Root.
void AVL::postOrder(Node* root)
{
	if(root != nullptr)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " " << endl;
	}
	return;
}
//Pre: Nothing is changed.
//Post: All nodes will be printed of order Root, Left, Right.
void AVL::preOrder(Node* root)
{
	if(root != nullptr)
	{
		cout << root->data << " " << endl;
		preOrder(root->left);
		preOrder(root->right);
	}
	return;
}
//Pre: Nothing is changed.
//Post: We can initialize a new AVL tree with root = nullptr.
AVL::AVL()
{
	root = nullptr;
}
//Pre: Dynamic variables still exist in memory.
//Post: Dynamic variables are deallocated in memory.
void AVL::DestroyRecursive(Node* node)
{
	if(node)
	{
		DestroyRecursive(node->left);
		DestroyRecursive(node->right);
		delete node;
	}
}
//Pre: Dynamic variables still exist in memory.
//Post: Dynamic variables are deallocated in memory.
AVL::~AVL()
{
	DestroyRecursive(root);
}
//Pre: Nothing is changed.
//Post: Copy all data of source object to the this object.
Node* AVL::copyTree_helper(const Node* source)
{
	if(source == nullptr)
	{
		return nullptr;
	}
	Node* result = new Node;
	result->data = source->data;
	result->left = copyTree_helper(source->left);
	result->right = copyTree_helper(source->right);
	return result;
}
//Pre: We cannot assign the values of old AVL tree to the new AVL tree.
//Post: We can assign the values of old AVL tree to the new AVL tree.
AVL::AVL(const AVL& rhs)
{
	root = copyTree_helper(rhs.root);
}
//Pre: We cannot assign the values of old AVL tree to the new AVL tree.
//Post: We can assign the values of old AVL tree to the new AVL tree.
const AVL& AVL::operator=(const AVL& rhs)
{
	if(this != &rhs)
	{
		if(root != nullptr)
		{
			DestroyRecursive(root);
		}
		if(rhs.root == nullptr)
		{
			root = nullptr;
		}
		else
		{
			root = copyTree_helper(rhs.root);
		}
	}
	return *this;
}
//Pre: Nothing is changed.
//Post: This function will check a AVL tree is full or not.
bool AVL::isFull(Node* root)
{
	if(root == nullptr)
	{
		return true;
	}
	else if(root->left == nullptr && root->right == nullptr)
	{
		return true;
	}
	else if(root->left != nullptr && root->right != nullptr)
	{
		return (isFull(root->left) && isFull(root->right));
	}
	else
	{
		return false;
	}
}

bool AVL::isComplete(Node* root) 
{ 
    if (root == NULL) 
	{
        return true;  
	}
    queue<Node*>queue; 
    queue.push(root); 
    bool flag = false; 
    while(queue.empty() == false) 
    { 
        Node* temp =queue.front(); 
        queue.pop(); 
        if(temp->left != nullptr) 
        { 
			if (flag == true)
			{
				return false;
			}
			queue.push(temp->left);
        } 
        else if(temp->left == nullptr)
		{
			flag = true;
		} 
        if(temp->right != nullptr) 
        { 
			if(flag == true) 
			{
				return false; 
			}
			queue.push(temp->right);
        } 
        else if(temp->right == nullptr)
		{
			flag = true;
		}
    } 
	return true;
}

//Pre: Nothing is changed.
//Post: This function will check a AVL tree is AVL or not. Besides, after you inserting, you have already done rotates to make tree balance. So, isAVL will always show the result of true.
bool AVL::isAVL(Node* root)
{
	/*if(root == nullptr)
	{
		return true;
	}
	int left = height(root->left);
	int right = height(root->right);
	if(abs(left-right) <= 1 && isAVL(root->left) == true && isAVL(root->right) == true)
	{
		return true;
	}
	return false;*/
	if(root == nullptr)
	{
		return true;
	}
	else if(root != nullptr)
	{
		isAVL(root->left);
		if(abs(getBalance(root)) > 1)
		{
			return false;
		}
		isAVL(root->right);
	}
	return true;
}
//Pre: Nothing is change.
//Post: We can call insert function without root parameter.
void AVL::insert(int data)
{
	root = insert(data, root);
}
//Pre: Nothing is change.
//Post: We can call remove function without root parameter.
void AVL::remove(int data)
{
	root = remove(data, root);
}





