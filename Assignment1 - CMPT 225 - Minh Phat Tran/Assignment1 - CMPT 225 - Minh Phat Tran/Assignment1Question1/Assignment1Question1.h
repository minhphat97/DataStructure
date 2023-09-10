#include <iostream>
using namespace std;
struct Node
{
	int Data;
	Node* Link;
};
typedef Node* NodePtr;
class Stack
{
private:
	NodePtr top;
public:
	Stack();
	NodePtr getTop();
	void setTop(NodePtr newTop);
	void push(int newData);
	void pop();
	int peek();
	int empty();
	int size();
	void display();
};