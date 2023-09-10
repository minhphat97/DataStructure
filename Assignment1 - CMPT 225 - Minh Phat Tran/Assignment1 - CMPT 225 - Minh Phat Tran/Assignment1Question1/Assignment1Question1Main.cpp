#include <iostream>
#include "Assignment1Question1.h"
using namespace std;

int main()
{
	Stack s;
	s.push(3);
	s.push(4);
	s.push(5);
	s.display();
	s.pop();
	s.display();
	cout << "Check the stack is empty or not: " << s.empty() << endl;
	cout << "Size of stack now is: " << s.size() << endl;
	cout << "Peek element of stack is: " << s.peek() << endl;
	system("pause");
	return 0;
}
