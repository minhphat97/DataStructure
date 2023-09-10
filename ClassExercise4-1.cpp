#include <iostream>
#include <string>
using namespace std;

struct Student
{
	int Data;
	string Name;
};
struct Node
{
	Student student;
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
	void pushFront(Student newStudent);
	void pushBack(Student newStudent);
	void popFront();
	void popBack();
	Student peekFront();
	Student peekBack();
	void clear();
	bool isEmpty();
	int count();
	void display();
};
//This is default constructor.
Deque::Deque()
{
	front = nullptr;
	back = nullptr;
}
//Pre-condition: Before calling this function, double-linked list is unchanged.
//Post-condition: After calling this function, it will return the first number in double-linked list.
NodePtr Deque::getFront()
{
	return front;
}
//Pre-condition: Before calling this function, double-linked list is unchanged.
//Post-condition: After calling this function, it will return the last number in double-linked list.
NodePtr Deque::getBack()
{
	return back;
}
//Pre-condition: Before calling this function, double-linked list is unchanged.
//Post-condition: After calling this function, it will set the new value to the first node in double-linked list.
void Deque::setFront(NodePtr newFront)
{
	front = newFront;
}
//Pre-condition: Before calling this function, double-linked list is unchanged.
//Post-condition: After calling this function, it will set the new value to the last node in double-linked list.
void Deque::setBack(NodePtr newBack)
{
	back = newBack;
}
//Pre-condition: Before calling this function, double-linked list is unchanged.
//Post-condition: After calling this function, it will push the new node at the beginning of double-linked list.
void Deque::pushFront(Student newStudent)
{
	NodePtr temp = new Node;
	temp->student.Data = newStudent.Data;
	temp->student.Name = newStudent.Name;
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
//Pre-condition: Before calling this function, double-linked list is unchanged.
//Post-condition: After calling this function, it will push the new node at the ending of double-linked list.
void Deque::pushBack(Student newStudent)
{
	NodePtr temp = new Node;
	temp->student.Data = newStudent.Data;
	temp->student.Name = newStudent.Name;
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
//Pre-condition: Before calling this function, double-linked list is unchanged.
//Post-condition: After calling this function, it will pop the node at the beginning of double-linked list.
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
//Pre-condition: Before calling this function, double-linked list is unchanged.
//Post-condition: After calling this function, it will pop the node at the ending of double-linked list.
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
//Pre-condition: Before calling this function, double-linked list is unchanged.
//Post-condition: After calling this function, it will return the value stored in the first node of double-linked list.
Student Deque::peekFront()
{
	if(front == nullptr || back == nullptr)
	{
		Student temp;
		temp.Name = "NAME IS BLANK";
		temp.Data = -1;
		return temp;
	}
	else
	{
		return (front->student);
	}
}
//Pre-condition: Before calling this function, double-linked list is unchanged.
//Post-condition: After calling this function, it will return the value stored in the last node of double-linked list.
Student Deque::peekBack()
{
	if(front == nullptr || back == nullptr) 
	{
		Student temp;
		temp.Name = "NAME IS BLANK";
		temp.Data = -1;
		return temp;
	}
	else
	{
		return (back->student);
	}
}
//Pre-condition: Before calling this function, double-linked list is unchanged.
//Post-condition: After calling this function, it will clear all nodes of double-linked list.
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
//Pre-condition: Before calling this function, double-linked list is unchanged.
//Post-condition: After calling this function, it will return true if all double-linked list is empty,
//it will return false if double-linked list is not empty.  
bool Deque::isEmpty()
{
	if(front == nullptr || back == nullptr)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
//Pre-condition: Before calling this function, double-linked list is unchanged.
//Post-condition: After calling this function, it will return the number of nodes in the double-linked list.
int Deque::count()
{
	if(front == nullptr || back == nullptr)
	{
		return 0;
	}
	int count = 1;
	NodePtr temp = front;
	while (temp != back)
	{
		count = count + 1;
		temp = temp->tail;
	}
	return count;
}
//Pre-condition: Before calling this function, double-linked list is unchanged.
//Post-condition: After calling this function, it will display all data in the double-linked list.
void Deque::display()
{
	NodePtr temp = front;
	if(front == nullptr || back == nullptr)
	{
		cout << "The double-linked list is empty now !" << endl;
		return;
	}
	
	while (temp != back)
	{
		cout << "Name: " << temp->student.Name << " " << "Student number: " << temp->student.Data << endl;
		temp = temp->tail;
	}
	cout << "Name: " << temp->student.Name << " " << "Student number: " << temp->student.Data << endl;
}
int main()
{
	Deque temp;
	cout << "Check to see if the double-linked list is empty or not before inserting" << endl;
	cout << temp.isEmpty() << endl;
	Student student1 = {12,"Jack"};
	temp.pushFront(student1);
	Student student2 = {27,"Peter"};
	temp.pushFront(student2);
	Student student3 = {30, "Eric"};
	temp.pushBack(student3);
	Student student4 = {45, "Henry"};
	temp.pushBack(student4);
	Student student5 = {54, "Richard"};
	temp.pushFront(student5);
	cout << "Check to see if the double-linked list is empty or not after inserting" << endl;
	cout << temp.isEmpty() << endl;
	cout << "The front student information in double-linked list is: " << endl;
	Student front = temp.peekFront();
	cout << "Name: " << front.Name << endl;
	cout << "Student number: " << front.Data << endl;
	cout << "The back number in double-linked list is: " << endl;
	Student back = temp.peekBack();
	cout << "Name: " << back.Name << endl;
	cout << "Student number: " << back.Data << endl;
	cout << "Double-linked list is: " << endl;
	temp.display();
	cout << "Size of double-linked list is: " << endl;
	cout << temp.count() << endl;
	cout << "The double-linked list after pop front: " << endl;
	temp.popFront();
	temp.display();
	cout << "The double-linked list after pop back: " << endl;
	temp.popBack();
	temp.display();
	cout << "Size of double-linked list at this time is: " << endl;
	cout << temp.count() << endl;
	temp.clear();
	cout << "The double-linked list after clearing all number in list: " << endl;
	temp.display();
	cout << "Check to see if the double-linked list is empty or not at this time" << endl;
	cout << temp.isEmpty() << endl;
	cout << "Size of double-linked list at this time is: " << endl;
	cout << temp.count() << endl;
	system("pause");
	return 0;
}