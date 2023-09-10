#include <iostream>
#include "Assignment1Question2.h"
using namespace std;
//This is default constructor
Queue::Queue()
{
	front = -1;
	rear = -1;
}
//This function will display all elements in Deque
void Queue::display()
{
	if(empty())
	{
		cout << "Queue is empty " << endl;
	}
	else
	{
		for (int i = front; i <= rear; i++)
		{
			cout << A[i] << " ";
		}
		cout << endl;
	}
}
//This function will set the new value of Pointer front
void Queue::setFront(int newFront)
{
	front = newFront;
}
//This function will set the new value of Pointer rear
void Queue::setRear(int newRear)
{
	rear = newRear;
}
//This function will return the value of Pointer front
int Queue::getFront()
{
	return front;
}
//This function will return the value of Pointer rear
int Queue::getRear()
{
	return rear;
}
//This function will push new item into Queue
void Queue::push(char Data)
{
	if(rear == SIZE-1)
	{
		cout << "Queue is full " << endl;
	}
	else
	{
		if(front == -1)
		{
			front = 0;
		}
		rear = rear + 1;
		A[rear] = Data;
	}
}
//This function will check Queue is empty or not
bool Queue::empty()
{
	if(front == -1 && rear == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//This function will pop the back element of Queue followed rule FIFO
void Queue::pop()
{
	if(empty())
	{
		cout << "Queue is empty " << endl;
	}
	else
	{
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front = front + 1;
		}
	}
}
//This function will show the value at front of the Queue
void Queue::peek()
{
	if(empty())
	{
		cout << "Queue is empty " << endl;
	}
	else
	{
		cout << "Element at front is: " << A[front] << endl;
	}
}
//This function will check the Queue is full or not
bool Queue::full()
{
	return (rear == SIZE - 1);
}
