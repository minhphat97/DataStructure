//Implementation File for Sequence
#include <iostream>
#include "ClassExercise1.h"
using namespace std;
//This function is called to print all datas stored in Sequence
void Sequence::printSequence()
{
	if (head == nullptr)
	{
		cout << "The sequence is empty !" << endl;
		return;
	}
	else
	{
		NodePtr temp = head;
		while(temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->link;
		}
		cout << endl; 
	}
}

//This is default constructor
Sequence::Sequence()
{
	head = nullptr;
}
//This is getter to get the first Node pointed by Head
NodePtr Sequence::getHead()
{
	return head;
}
//This is setter of Head
void Sequence::setHead(NodePtr newHead)
{
	head = newHead;
}
//This is to insert a new Node to the tail of Sequence
void Sequence::insert(double newData)
{
	if(head == nullptr)
	{
		NodePtr temp = new Node;
		head = temp;
		temp->data = newData;
		temp->link = nullptr;
	}
	else
	{
		NodePtr check = head;
		while(check->link != nullptr)
		{
			check = check->link;
		}
		NodePtr temp = new Node;	
		temp->data = newData;
		temp->link = nullptr;
		check->link = temp;
	}
}

//This is to clear whole the Sequence
void Sequence::clear()
{
	while(head != nullptr)
	{
		NodePtr temp = head;
		head = head->link;
		delete temp;
	}
}
//This is to return the size of Sequence
int Sequence::size()
{
	if(head == nullptr)
	{
		return 0;
	}
	else if(head != nullptr)
	{
		int counter = 0;
		NodePtr temp = head;
		while(temp != nullptr)
		{
			counter = counter + 1;
			temp = temp->link;
		}
		return counter;
	}
}
//This is to return the standard deviation of all datas in the Sequence
double Sequence::stdDeviation()
{
	if(head == nullptr)
	{
		return 0;
	}
	else
	{
		double Sum = 0;
		
		NodePtr temp = head;
		while(temp != nullptr)
		{
			Sum = Sum + (temp->data);
			temp = temp->link;
		}
		double Average = Sum/(this->size());
		double Square = 0;
		NodePtr check = head;
		while(check != nullptr)
		{
			Square = Square + ((check->data - Average)*(check->data - Average));
			check = check->link;
		}
		double stdDeviation = sqrt(Square/(this->size()));
		return stdDeviation;
	}
}
