#include <iostream>
#include "Assignment1Question2.h"
using namespace std;

int main()
{
	Queue q;
	cout << "Check queue is empty or not at this time: " << q.empty() << endl;
	q.push('a');
	q.push('b');
	q.peek();
	cout << "Check queue is empty or not at this time: " << q.empty() << endl;
	q.push('c');
	q.display();
	cout << "Check queue is full or not at this time: " << q.full() << endl;
	q.push('d');
	q.push('e');
	q.display();
	cout << "Check queue is full or not at this time: " << q.full() << endl;
	q.pop();
	q.display();
	q.peek();
	system("pause");
	return 0;
}