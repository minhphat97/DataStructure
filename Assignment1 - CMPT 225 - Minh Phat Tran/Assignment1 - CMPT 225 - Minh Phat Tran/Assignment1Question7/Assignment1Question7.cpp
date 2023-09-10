#include <iostream>
#include <string>
using namespace std;
struct Node
{
	char c;
	Node* head;
	Node* tail;
};
typedef Node* NodePtr;
class Deque
{
private:
	NodePtr front;
	NodePtr back;
public:
	Deque();
	NodePtr getFront();
	NodePtr getBack();
	void setFront(NodePtr newFront);
	void setBack(NodePtr newBack);
	void pushFront(char Data);
	void pushBack(char Data);
	void popFront();
	void popBack();
	char peekFront();
	char peekBack();
	void clear();
	void display();
};
//This is default constructor
Deque::Deque()
{
	front = nullptr;
	back = nullptr;
}
//This function will return value of pointer front
NodePtr Deque::getFront()
{
	return front;
}
//This function will return value of pointer back
NodePtr Deque::getBack()
{
	return back;
}
//This function will set new value to the pointer front
void Deque::setFront(NodePtr newFront)
{
	front = newFront;
}
//This function will set new value to the pointer back
void Deque::setBack(NodePtr newBack)
{
	back = newBack;
}
//This function will push new item into the front of deque
void Deque::pushFront(char Data)
{
	NodePtr temp = new Node;
	temp->c = Data;
	temp->head = nullptr;
	temp->tail = nullptr;
	if(front == nullptr || back == nullptr)
	{
		front = temp;
		back = temp;
	}
	else
	{
		temp->tail = front;
		front->head = temp;
		front = temp;
	}
}
//This function will push new item into the back of deque
void Deque::pushBack(char Data)
{
	NodePtr temp = new Node;
	temp->c = Data;
	temp->head = nullptr;
	temp->tail = nullptr;
	if(front == nullptr || back == nullptr)
	{
		front = temp;
		back = temp;
	}
	else
	{
		temp->head = back;
		back->tail = temp;
		back = temp;
	}
}
//This function will pop item from the front of deque
void Deque::popFront()
{
	NodePtr temp = front;
	if(front == nullptr || back == nullptr)
	{
		return;
	}
	if(front == back)
	{
		front = nullptr;
		back = nullptr;
	}
	else
	{
		front = front->tail;
		front->head = nullptr;
		delete temp;
	}
}
//This function will pop item from the back of deque
void Deque::popBack()
{
	NodePtr temp = back;
	if (front == nullptr || back == nullptr)
	{
		return;
	}
	if(front == back)
	{
		front = nullptr;
		back = nullptr;
	}
	else
	{
		back = back->head;
		back->tail = nullptr;
		delete temp;
	}
}
//This function will return the value of front element from the deque
char Deque::peekFront()
{
	if(front == nullptr || back == nullptr)
	{
		cout << "Deque is empty " << endl;
		return '\0';
	}
	else
	{
		return (front->c);
	}
}
//This function will return the value of back element from the deque
char Deque::peekBack()
{
	if(front == nullptr || back == nullptr) 
	{
		cout << "Deque is empty " << endl;
		return '\0';
	}
	else
	{
		return (back->c);
	}
}
//This function will clear whole the deque
void Deque::clear()
{
	while(front != back)
	{
		NodePtr temp = front;
		front = front->tail;
		delete temp;
	}
	NodePtr last = front;
	front = nullptr;
	back = nullptr;
	delete last;
}
//This function will display all elements in Deque
void Deque::display()
{
	NodePtr temp = front;
	if(front == nullptr || back == nullptr)
	{
		cout << "The deque is empty " << endl;
		return;
	}
	
	while (temp != back)
	{
		cout << temp->c << " ";
		temp = temp->tail;
	}
	cout << temp->c << endl;
}
//This function will check the string is Palindrom or not
bool checkPalindrome(string Temp)
{
	Deque deque;
	int size = Temp.length();
	for (int i = 0; i < size; i++)
	{
		deque.pushBack(Temp[i]);
	}
	int counter = 0;
	for (int i = 0; i < size/2; i++)
	{
		if(deque.peekFront() == deque.peekBack())
		{
			counter = counter + 1;
		}
		deque.popFront();
		deque.popBack();
	}
		
	if(counter == size/2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	string s1 = "abccba";
	string s2 = "abcba";
	string s3 = "minh";
	string s4 = "phattran";
	Deque d1, d2, d3, d4;
	cout << "s1 is palindrome or not: ";
	cout << checkPalindrome(s1) << endl;

	cout << "s2 is palindrome or not: ";
	cout << checkPalindrome(s2) << endl;

	cout << "s3 is palindrome or not: ";
	cout << checkPalindrome(s3) << endl;

	cout << "s4 is palindrome or not: ";
	cout << checkPalindrome(s4) << endl;

	system("pause");
	return 0;
}