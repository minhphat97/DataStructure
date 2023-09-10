/**  
* @homework3Question2.cpp  
* @author Phat Minh Tran 
* @Date   July 6, 2018  
* @version 1.0  
* @section LA01  
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the 
// work of others.  I acknowledged that I have read and followed the Academic Honesty and 
// Integrity related policies as outlined in the syllabus.
//
// _____ MINH PHAT TRAN ____      _____June 1, 2018______________ 
// 
// ____ 301297286 ______ 
// 


#include <iostream>
using namespace std;
class StackOverflowException //This class is defined if the application program tries to push data onto a stack that  is already full
{};
class StackEmptyException //This class is defined if the application program tries to pop data off an empty stack
{};
struct Node //Create node which is used for Stack list
{
	char data;
	Node* link;
};
typedef Node* NodePtr;
class Stack //Create Stack list which follows the rule "last in/first out"
{
private:
	int Size;
	NodePtr head;
public:
	Stack(int theSize);
	int getSize()const;
	char getdataHead()const;
	void setSize(int theSize);
	void head_insert(const char theData);
	void head_remove();
	void print_stack()const;
};
char Stack::getdataHead()const //This is to access to the element of head node
{
	return head->data;
}
void Stack::print_stack()const //This is to print the Stack list which follows the rule "last in/first out"
{
	if(head == nullptr)
	{
		cout << "Stack list is empty !" << endl;
		return;
	}
	else
	{
		NodePtr temp = head;
		while(temp != nullptr)
		{
			cout << temp->data << "  ";
			temp = temp->link;
		}
		cout << endl;
	}
}
void Stack::setSize(int theSize) //This is to create the fixed size for the Stack list
{
	Size = theSize;
}
Stack::Stack(int theSize) //Constructor which has size is a parameter
{
	head = nullptr;
	Size = theSize;
}
int Stack::getSize()const //Return the size of Stack list
{
	return Size;
}
void Stack::head_insert(const char theData) //This is to insert a new node to the head of Stack list
{
	NodePtr temp = new Node;
	temp->data = theData;
	temp->link = head;
	head = temp;
}
void Stack::head_remove() //This to remove the node at the head of Stack list
{
	NodePtr temp = head;
	head = head->link;
	delete temp;
}

int main()
{
	int theSize;
	char Element;
	char Answer;
	cout << "Please enter the size of stack list which is THE NUMBER OF ELEMENTS in your stack list: "; //Enter a number which demonstrate the size of Stack list
	cin >> theSize;
	cout << endl;
	Stack List(theSize);
	try //Create try block
	{
		int counter = 0;
		while(true)
		{
			cout << "Please enter 1 to push data, 2 to pop data, 3 to print the stack, and 4 to stop the program: "; //Enter a number to choose one option
			cin >> Answer;
			if(Answer == '1') //This condition is to push data into the Stack list
			{
				if(counter == List.getSize()) 
				{
					throw StackOverflowException(); //Create throw statement which use StackOverflowException class
				}
				else if(counter < List.getSize()) 
				{
					cout << "Please enter an character element: ";
					cin >> Element;
					List.head_insert(Element);
					counter = counter + 1;
					cout << endl;
				}
			}
			else if(Answer == '2') //This conditon is to pop data from the Stack list
			{
				if(counter == 0)
				{
					throw StackEmptyException(); //Create throw statement which use the StackEmptyException class
				}
				else if(counter > 0)
				{
					cout << "You have remove character: " << List.getdataHead() << endl;
					List.head_remove();
					counter = counter - 1;
					cout << endl;
				}
			}
			else if(Answer == '3') //This condition is to print the Stack list
			{
				cout << "Your elements in stack are: ";
				List.print_stack();
				cout << endl;
			}
			else if(Answer == '4') //This condition is to stop the program
			{
				cout << "Your program is stopped !" <<endl;
				break;
			}
			else
			{
				cout << "Your entered number answer is INVALID !" << endl;
			}
		}
	}
	catch (StackEmptyException e) //Create catch block which uses StackEmptyException class
	{
		cout << "You cannot pop the data off an empty stack, so your program is stopped !" << endl << endl;
	}
	catch (StackOverflowException e) //Create catch block which uses StackOverflowException class
	{
		cout << "You cannot push the data onto a stack that is already full, so your program is stopped !" << endl << endl;
	}
	system("pause");
	return 0;
}

