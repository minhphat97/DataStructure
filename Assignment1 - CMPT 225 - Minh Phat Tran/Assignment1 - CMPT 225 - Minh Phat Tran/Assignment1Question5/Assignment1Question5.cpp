//*******************************************************************************************************************************************************
//I have fixed 2 kinds of error: Firstly, functions should pass by pointer not pass by value. Secondly, I have deallocate dynamic memory in main function
//*******************************************************************************************************************************************************
#include <iostream>
#include <string>
#include "math.h"
using namespace std;
class Stack
{
	int capacity;
	int top;
	int* Array;
public:
	bool isFull();
	bool isEmpty();
	void push(int item);
	int pop();
	friend Stack* createStack(int capacity);
};
bool Stack::isFull()
{
	return (top == capacity - 1);
}
bool Stack::isEmpty()
{
	return (top == -1);
}
void Stack::push(int item)
{
	if(isFull())
		return;
	Array[++top] = item;
}
int Stack::pop()
{
	if(isEmpty())
		return -10;
	return Array[top--];
}
Stack* createStack(int capacity)
{
	Stack* stack = new Stack;
	stack->capacity = capacity;
	stack->top = -1;
	stack->Array = new int[capacity];
	return stack;
}

void moveDisk(char fromPeg, char toPeg, int disk)
{
	cout << "Move the disk " << disk << " from " << fromPeg << " to " << toPeg << endl;
}

void moveDisksBetweenTwoPoles(Stack *src, Stack *dest, char s, char d)
{
	int pole1TopDisk = src->pop();
	int pole2TopDisk = dest->pop();
	cout << pole1TopDisk << " " << pole2TopDisk << endl;

	if(pole1TopDisk == -10)
	{
		src->push(pole2TopDisk);
		moveDisk(d,s,pole2TopDisk);
	}
	else if(pole2TopDisk == -10)
	{
		dest->push(pole1TopDisk);
		moveDisk(s,d,pole1TopDisk);
	}
	else if(pole1TopDisk > pole2TopDisk)
	{
		src->push(pole1TopDisk);
		src->push(pole2TopDisk);
		moveDisk(d,s,pole2TopDisk);
	}
	else
	{
		dest->push(pole2TopDisk);
		dest->push(pole1TopDisk);
		moveDisk(s,d,pole1TopDisk);
	}
}

void tohlterative(int num_of_disks, Stack *src, Stack *aux, Stack *dest)
{
	int i, total_num_of_moves;
	char s = 'S', d = 'D', a = 'A';
	if (num_of_disks % 2 == 0)
	{
		char temp = d;
		d = a;
		a = temp;
	}
	total_num_of_moves = pow(2.0, num_of_disks) - 1;

	for (i = num_of_disks; i >= 1; i--)
	{
		src->push(i);
		cout << i << endl;
	}

	for (i = 1; i <= total_num_of_moves; i++)
	{
		if(i%3 == 1)
			moveDisksBetweenTwoPoles(src,dest,s,d);
		else if(i%3 == 2)
			moveDisksBetweenTwoPoles(src,aux,s,a);
		else if(i%3 == 0)
			moveDisksBetweenTwoPoles(aux,dest,a,d);
	}
}
int main()
{
	int num_of_disks = 2;
	Stack*src, *dest, *aux;
	src = createStack(num_of_disks);
	aux = createStack(num_of_disks);
	dest = createStack(num_of_disks);
	tohlterative(num_of_disks,src,aux,dest);
	delete src;//I added this
	delete dest;//I added this
	delete aux;//I added this
	system("pause");
	return 0;
}
