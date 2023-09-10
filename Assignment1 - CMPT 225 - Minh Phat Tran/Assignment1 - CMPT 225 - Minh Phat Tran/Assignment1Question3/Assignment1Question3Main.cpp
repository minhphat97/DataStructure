#include <iostream>
#include <string>
#include "Assignment1Question3.h"
using namespace std;
int main()
{
	Deque temp;
	cout << "Deque is empty or not: " << temp.empty() << endl;
	temp.push_front("david");
	temp.push_front("minh");
	temp.push_front("tran");
	temp.push_front("phat");
	temp.push_back("mom");
	cout << "Front string is: " << temp.peek_front() << endl;
	cout << "Back string is: " << temp.peek_back() << endl;
	cout << "Deque is full or not: " << temp.full() << endl;
	temp.display();
	temp.pop_front();
	temp.pop_back();
	cout << "After popping front and back elements " << endl;
	cout << "Deque is empty or not: " << temp.empty() << endl;
	temp.display();
	cout << "Deque is full or not: " << temp.full() << endl;
	system("pause");
	return 0;
}