#include <iostream>
using namespace std;
struct Node
{
	int Data;
	Node* Link;
};
typedef Node* NodePtr;
class LinkedList
{
private:
	NodePtr head;
public:
	LinkedList();
	NodePtr getHead();
	void setHead(NodePtr newHead);
	void headInsert(int Data);
	void tailInsert(int Data);
	void insertSort(int Data);
	void display();
};
//This function will insert and sort simultaneously new item into Linked List
void LinkedList::insertSort(int Data)
{
	if(head == nullptr)
	{
		headInsert(Data);
	}
	else if(head->Data >= Data)
	{
		headInsert(Data);
	}
	else
	{
		NodePtr check = head;
		while(check->Link != nullptr)
		{
			if(check->Link->Data >= Data)
				break;
			else
				check = check->Link;
		}
		NodePtr temp = new Node;
		temp->Data = Data;
		temp->Link = check->Link;
		check->Link = temp;
	}
}
//This function will display all elements in Linked List
void LinkedList::display()
{
	if(head == nullptr)
	{
		cout << "Linked list is empty. " << endl;
		return;
	}
	else
	{
		NodePtr temp = head;
		while(temp != nullptr)
		{
			cout << temp->Data << " ";
			temp = temp->Link;
		}
		cout << endl;
	}

}
//This is default constructor
LinkedList::LinkedList()
{
	head = nullptr;
}
//This function will return value of Pointer head
NodePtr LinkedList::getHead()
{
	return head;
}
//This function will set new value to Pointer head
void LinkedList::setHead(NodePtr newHead)
{
	head = newHead;
}
//This function will insert new item into the head of linked list
void LinkedList::headInsert(int Data)
{
	NodePtr temp = new Node;
	temp->Data = Data;
	temp->Link = head;
	head = temp;
}
//This function will insert new item into the tail of linked list
void LinkedList::tailInsert(int Data)
{
	if(head == nullptr)
	{
		headInsert(Data);
		return;
	}
	else
	{
		NodePtr checking = head;
		while(checking->Link != nullptr)
		{
			checking = checking->Link;
		}
		NodePtr temp = new Node;
		temp->Data = Data;
		temp->Link = nullptr;
		checking->Link = temp;
	}
}
//This function will merge two sorted linked list into large Linked List
LinkedList MergeTwoSortedLinkedList(LinkedList&L1, LinkedList&L2)
{
	LinkedList L;
	NodePtr first = L1.getHead();
	NodePtr second = L2.getHead();
	while(first != nullptr)
	{
		L.insertSort(first->Data);
		first = first->Link;
	}

	while(second != nullptr)
	{
		L.insertSort(second->Data);
		second = second->Link;
	}
	return L;
}

int main()
{
	//Question only asks for SORTED LINKEDLISTS, so I will create two sorted linked lists in this main function.
	cout << "Two sorted linked list: " << endl;
	LinkedList L1;
	L1.tailInsert(2);
	L1.tailInsert(5);
	L1.tailInsert(7);
	L1.tailInsert(12);
	L1.display();
	LinkedList L2;
	L2.tailInsert(2);
	L2.tailInsert(8);
	L2.tailInsert(10);
	L2.tailInsert(24);
	L2.display();
	cout << "After merging two sorted lists: " << endl;
	LinkedList L3 = MergeTwoSortedLinkedList(L1,L2);
	L3.display();
	system("pause");
	return 0;
}