#include <iostream>
#include <string>
#include "Assignment1Question3.h"
using namespace std;
//This is defaut constructor of Deque
Deque::Deque()
{
	front = -1;
	rear = -1;
}
//This function will display all elements in Deque
void Deque::display()
{
	if(front == -1 && rear == -1)
	{
		cout << "Deque is empty " << endl;
	}
	else if (front == rear)
	{
		cout << A[front] << endl;
	}
	else
	{
		if(front < rear)
		{
			for (int i = front; i <= rear; i++)
			{
				cout << A[i] << endl;
			}
		}
		else if (rear < front)
		{
			for (int i = front; i < SIZE; i++)
			{
				cout << A[i] << endl;
			}
			for (int i = 0; i <= rear; i++)
			{
				cout << A[i] << endl;
			}
		}
	}
}
//This function will return the value of element at the front of Deque
string Deque::peek_front()
{
	if(front == -1 && rear == -1)
	{
		cout << "Deque is empty " << endl;
		return "";
	}
	return A[front];
}
//This function will return the value of element at the back of Deque
string Deque::peek_back()
{
	if(front == -1 && rear == -1)
	{
		cout <<"Deque is empty " << endl;
		return "";
	}
	return A[rear];
}
//This function will check the Deque is empty or not
bool Deque::empty()
{
	if (front == -1 && rear == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//This function will check the Deque is full or not
bool Deque::full()
{
	if (front == ((rear + 1) % SIZE))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//This function will set the value for the Pointer front
void Deque::setFront(int newFront)
{
	front = newFront;
}
//This function will set the value for the Pointer rear
void Deque::setRear(int newRear)
{
	rear = newRear;
}
//This function will return the value of Pointer front
int Deque::getFront()
{
	return front;
}
//This function will return the value of Pointer rear
int Deque::getRear()
{
	return rear;
}
//This function will push new item to the back of Deque
void Deque::push_back(string Data)
{
	if(front == ((rear + 1) % SIZE))
	{
		cout << "Deque is full " << endl;
	}
	else
	{
		if(front == -1 && rear == -1)
		{
			front = 0;
			rear = 0;
		}
		else
		{
			rear = (rear + 1) % SIZE;
		}
		A[rear] = Data;
	}
}
//This function will push new item to the front of Deque
void Deque::push_front(string Data)
{
	if(front == ((rear + 1) % SIZE))
	{
		cout << "Deque is full " << endl;
	}
	else
	{
		if(front == -1 && rear == -1)
		{
			front = 0;
			rear = 0;
		}
		else
		{
			front = (SIZE + front - 1) % SIZE;
		}
		A[front] = Data;
	}
}
//This function will pop item from the front of Deque
void Deque::pop_front()
{
	if(front == -1 && rear == -1)
	{
		cout << "Deque is empty " << endl;
	}
	else
	{
		if(front == rear)
		{
			front = -1;
			rear = -1;
		}
		else 
		{
			front = (front + 1) % SIZE;
		}
	}
}
//This function will pop item from the back of Deque
void Deque::pop_back()
{
	if(front == -1 && rear == -1)
	{
		cout << "Deque is empty " << endl;
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
			rear = (SIZE + rear - 1) % SIZE;
		}
	}
}

