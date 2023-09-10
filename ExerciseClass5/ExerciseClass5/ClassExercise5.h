#include <iostream>
#include <string>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
	int height;
};
class AVL
{
private:
	Node* root;
	Node* insert(int data, Node* root);
	Node* remove(int data, Node* root);
	int getBalance(Node* N);
	int max(int a, int b);
	void DestroyRecursive(Node* node);
	Node* singleRightRotate(Node*&y);
	Node* singleLeftRotate(Node*&x);
	Node* doubleRightLeftRotate(Node*& node);
	Node* doubleLeftRightRotate(Node*& node);
	Node* copyTree_helper(const Node* source);
public:
	Node* getRoot();
	int height(Node* N);
	Node* newNode(int data);
	bool isComplete(Node* root);
	Node* findMin(Node* node);
	Node* findMax(Node* node);
	Node* parent(Node* root, int data);
	int childCount(Node* root, int data);
	bool search(Node* root, int data);
	int originalHeight();
	bool isRoot(Node* root, int data);
	bool isInternal(Node* root, int data);
	bool isExternal(Node* root, int data);
	int size(Node* root);
	void inOrder(Node* root);
	void postOrder(Node* root);
	void preOrder(Node* root);
	AVL();
	~AVL();
	AVL(const AVL& rhs);
	const AVL& operator=(const AVL& rhs);
	bool isFull(Node* root);
	bool isAVL(Node* root);
	void insert(int data);
	void remove(int data);
};
