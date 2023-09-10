#include <iostream>
#include <string>
#include <exception>
#include "ClassExercise3.h"
using namespace std;
//This function will notify the error of Stack Overflow
const char* MyException1::what() const throw()
{
	return "Stack Overflow was happened ! ";
}
//This function will notify the error of Stack Underflow
const char* MyException2::what() const throw()
{
	return "Stack Underflow was happened ! ";
}
//This function will notify the Empty Stack
const char* MyException3::what() const throw()
{
	return "Stack Empty was happened ! ";
}
//Default constructor sets top = -1
template <class T>
Stack<T>::Stack()
{
	top = -1;
}
//Pre-condition: Before calling this function, the Stack is unchanged.
//Post-condition: After calling this function, new item will be added to the Stack.
template <class T>
void Stack<T>::push(T x)
{
	
	try
	{
		if(top >= (MAX-1))
		{
			throw MyError1;
		}
		else
		{
			a[++top] = x;
			cout << x << " pushed into stack\n";
		}
	}
	catch(exception&error)
	{
		cout << error.what() << endl;
	}
}
//Pre-condition: Before calling this function, the Stack is unchanged.
//Post-condition: After calling this function, one item will be put out from the Stack.
template <class T>
T Stack<T>::pop()
{
	try
	{
		if(top < 0)
		{
			throw MyError2;
		}
		else
		{
			T x = a[top--];
			return x;
		}
	}
	catch(exception&error)
	{
		cout << error.what() << endl;
		return 0;
	}
}
//Pre-condition: Before calling this function, the Stack is unchanged.
//Post-condition: After calling this function, it will show you the item at the top of Stack.
template <class T>
T Stack<T>::peek()
{
	try
	{
		if(top < 0)
		{
			throw MyError3;
		}
		else
		{
			T x = a[top];
			return x;
		}
	}
	catch(exception&error)
	{
		cout << error.what() << endl;
		return T();
	}
}
//Pre-condition: Before calling this function, the Stack is unchanged.
//Post-condition: After calling this function, it will show whether the Stack is empty or not.
template <class T>
bool Stack<T>::isEmpty()
{
	return (top < 0);
}
//===================================================================================================
int main()
{
	//Initialize stack of type String
	cout << "Stack of type String: " << endl;
	class Stack <string> s;
	s.push("Minh");
	s.push("Phat");
	s.push("Tran");
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.peek() << endl;
	cout << s.isEmpty () << endl;
	cout << endl;
	//Initilize stack of type Integer
	cout << "Stack of type Int: " << endl;
    class Stack <int> m;
	m.push(3);
	m.push(1);
	m.push(2);
	cout << m.pop() << endl;
	cout << m.pop() << endl;
	cout << m.peek() << endl;
	cout << m.isEmpty() << endl;
	system("pause");
	return 0;
}

