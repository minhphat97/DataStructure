#include <iostream>
#include <string>
using namespace std;
struct Node
{
	string Data;
	Node* Link;
};
typedef Node* NodePtr;
class Queue
{
private:
	NodePtr head;
	NodePtr back;
public:
	Queue();
	NodePtr getHead();
	NodePtr getBack();
	void setHead(NodePtr newHead);
	void setBack(NodePtr newBack);
	void enque(string Data);
	void deque();
	string peekHead();
	string peekBack();
};
//This function will return value of head element in queue
string Queue::peekHead()
{
	if(head == nullptr && back == nullptr)
	{
		cout << "Queue is empty. " << endl;
		return "";
	}
	else
		return head->Data;
}
//This function will return value of back element in queue
string Queue::peekBack()
{
	if(head == nullptr && back == nullptr)
	{
		cout << "Queue is empty. " << endl;
		return "";
	}
	else
		return back->Data;
}
//This is default constructor
Queue::Queue()
{
	head = nullptr;
	back = nullptr;
}
//This will return the value of head pointer
NodePtr Queue::getHead()
{
	return head;
}
//This will return the value of back pointer
NodePtr Queue::getBack()
{
	return back;
}
//This will set new value into the pointer head
void Queue::setHead(NodePtr newHead)
{
	head = newHead;
}
//This will set new value into the pointer back
void Queue::setBack(NodePtr newBack)
{
	back = newBack;
}
//This function will insert nre item into queue
void Queue::enque(string Data)
{
	NodePtr temp = new Node;
	temp->Data = Data;
	temp->Link = nullptr;
	if(head == nullptr && back == nullptr)
	{
		head = temp;
		back = temp;
	}
	else
	{
		back->Link = temp;
		back = temp;
	}
}
//This function will remove item out of queue
void Queue::deque()
{
	NodePtr temp = head;
	if(head == nullptr)
		return;
	if(head == back)
	{
		head = nullptr;
		back = nullptr;
	}
	else
		head = head->Link;
	delete temp;
}
//This function will print sequence of binary type of a number
void BinaryNumber(int n)
{
	Queue q;
	q.enque("1");

	for (int i = 0; n > i; n--)
	{
		string First = q.peekHead();
		q.deque();
		cout << First << endl;

		string Second = First + "0";
		string Third = First + "1";
		q.enque(Second);
		q.enque(Third);
	}
}
int main()
{
	BinaryNumber(5);
	system("pause");
	return 0;
}