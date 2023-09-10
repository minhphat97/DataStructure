#include <iostream>
#include <string>
using namespace std;
#define SIZE 5
class Deque
{
private:
	string A[SIZE];
	int front;
	int rear;
public:
	Deque();
	void setFront(int newFront);
	void setRear(int newRear);
	int getFront();
	int getRear();
	void push_back(string Data);
	void push_front(string Data);
	void pop_front();
	void pop_back();
	string peek_front();
	string peek_back();
	bool empty();
	bool full();
	void display();
};