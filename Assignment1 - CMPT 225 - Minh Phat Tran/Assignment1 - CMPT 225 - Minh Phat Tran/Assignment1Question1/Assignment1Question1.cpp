#include <iostream>
#include "Assignment1Question1.h"
using namespace std;
//This is default constructor
Stack::Stack()
{
	top = nullptr;
}
//This function will return value of top element in Stack
NodePtr Stack::getTop()
{
	return top;
}
//This function will set the new value for Pointer top
void Stack::setTop(NodePtr newTop)
{
	top = newTop;
}
//This function will push new item into stack
void Stack::push(int newData)
{
	NodePtr temp = new Node;
	if (!temp)
	{
		cout << "\nStack Overflow";
		exit(1);
	}
	temp->Data = newData;
	temp->Link = top;
	top = temp;
}
//This function will pop the top item out of the stack
void Stack::pop()
{
	if(top == nullptr)
	{
		cout << "\nStackUnderflow" << endl;
		exit(1);
	}
	else
	{
		NodePtr temp = top;
		top = top->Link;
		delete temp;
	}
}
//This function will return value of the top element in the Stack
int Stack::peek()
{
	if(!empty())
	{
		return (top->Data);
	}
	else
	{
		exit(1);
	}
}
//This function will check the Stack is empty or not
int Stack::empty()
{
	return (top == nullptr);
}
//This function will return the size of Stack
int Stack::size()
{
	if(top == nullptr)
	{
		return 0;
	}
	else
	{
		int counter = 0;
		NodePtr temp = top;
		while(temp != nullptr)
		{
			counter = counter + 1;
			temp = temp -> Link;
		}
		return counter;
	}
}
//This function will display all items in Stack
void Stack::display()
{
	if(top == nullptr)
	{
		cout << "\nStack Underflow";
	}
	else
	{
		NodePtr temp = top;
		while(temp != nullptr)
		{
			cout << temp->Data << " ";
			temp = temp -> Link;
		}
	}
	cout << endl;
}
