#include <iostream>
using namespace std;
#define SIZE 5
class Queue
{
private:
	char A[SIZE];
	int front;
	int rear;
public:
	Queue();
	void setFront(int newFront);
	void setRear(int newRear);
	int getFront();
	int getRear();
	bool empty();
	void push(char Data);
	void pop();
	void peek();
	bool full();
	void display();
};