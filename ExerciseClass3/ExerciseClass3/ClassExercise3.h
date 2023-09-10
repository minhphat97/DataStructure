#include <iostream>
#include <string>
#include <exception>
using namespace std;
#define MAX 3
class MyException1:public exception// This is for Overflow
{
	const char* what() const;
}MyError1;
class MyException2:public exception// This is for Underflow
{
	const char* what() const;
}MyError2;
class MyException3:public exception// This is for Empty Stack
{
	const char* what() const;
}MyError3;
template <class T>//Note to remind myself: I have fig it out that template <class T> only affects on the local scope (not global scope).
//Stack will follow FILO rule
class Stack
{
	int top;
	T a[MAX];
public:
	Stack();
	void push(T x);
	T pop();
	T peek();
	bool isEmpty();
};
