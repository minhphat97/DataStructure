/**  
* @homework2Question2.cpp  
* @author Phat Minh Tran 
* @Date   June 18, 2018  
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
#include <cstdlib>
#include <cstddef>
#include <ctime>
using namespace std;
struct QueueNode                                  //Create node by struct
{
	int number;
	long time;
	QueueNode* link;
};
typedef QueueNode* QueueNodePtr;                  //Use typedef
class Queue                                       //Create a queue to link node together 
{
private:                                          //Memeber variables  
	QueueNodePtr head;
	QueueNodePtr back;
public:                                           //Member functions
	Queue();
	QueueNodePtr getHead()const;                  
	QueueNodePtr getBack()const;
	int getNumberBack()const;
	int getNumberHead()const;
	long getTimeBack()const;
	long getTimeHead()const;
	void setWaitHead(int wait);
	void insert_tail(int number, long time);
	void remove_head();
	void print_head_node();
};
Queue::Queue()
{
	head = nullptr;
	back = nullptr;
}
QueueNodePtr Queue::getHead()const //This function is to return a node which head is pointing to.
{
	return head;
}
QueueNodePtr Queue::getBack()const //This function is to return a node which back is poiting to.
{
	return back;
}

int Queue::getNumberBack()const //This function is to return a value of member variable NUMBER 
{
	return back->number;
}
int Queue::getNumberHead()const //This function is to return a value of member variable NUMBER
{
	return head->number;
}
long Queue::getTimeBack()const //This function is to return a value of member variable TIME
{
	return back->time;
}
long Queue::getTimeHead()const //This function is to return a value of member variable 
{
	return head->time;
}
void Queue::insert_tail(int number, long time) //This function is to insert a node at the tail of Queue
{
	if(head == nullptr)
	{
		QueueNodePtr temp = new QueueNode;
		temp->number = number;
		temp->time = time;
		temp->link = head;
		head = temp;
		back = head;
	}
	else
	{
		QueueNodePtr temp = new QueueNode;
		temp->number = number;
		temp->time = time;
		temp->link = back->link;
		back->link = temp;
		back = temp;
	}
}
void Queue::remove_head() //This function is to remove a node a the head of queue
{
	if(head == nullptr)
	{
		return;
	}
	else if(head->link == nullptr)
	{
		QueueNodePtr temp = head;
		head = head->link;
		back = head;
		delete temp;
	}
	else
	{
		QueueNodePtr temp = head;
		head = head->link;
		delete temp;
	}
}

int main()
{
	Queue q;
	int option;
	int counter = 0;
	long timeTail;
	long timeHead;
	int size = 0;
	int index = 0;
	
	int Array[100];   //This array is to create to store the wait time of previous customers, and then use them to calculate the average wait time for the next customer.

	cout << "The line is empty." << endl;

	while(true)
	{
		cout << "Enter '1' to simulate a customer's arrival, '2' to help the next customer, or '3' to quit." << endl;
		cin >> option;
		if(option == 1) //This condition is to insert the new node at the tail of queue
		{
			counter = counter + 1; //This counter is to assign the ticket numbers to the customers
			timeTail = static_cast<long>(time(NULL)); //This is to calculate the total seconds from 1/1/1970
			q.insert_tail(counter,timeTail); //This is to insert a node to the tail of queue   
			cout << "Customer " << q.getNumberBack()<<" entered the queue at the time " << q.getTimeBack() << endl; 
		}
		else if(option == 3) //This condition is to stop the loop
		{
			break;
		}
		else if(option == 2) //This consition is to remove a node at the head from the queue. 
		{
			if(q.getHead() == nullptr)
			{
				cout << "The line is empty." << endl;
			}
			else
			{
				timeHead = static_cast<long>(time(NULL));
				int a = timeHead - q.getTimeHead();
				float Estimate = 0;
				Array[index] = a;
				size = size + 1;
				index = index + 1;
				cout << "Customer " << q.getNumberHead() << " is being helped at time " << timeHead <<". Wait time = " << a << " seconds." << endl; //This line is to display the number ticket and wait time of a consumer
				
				for (int i = 0; i < size; i++)
				{
					Estimate = Estimate + Array[i];
				}
				float Average = Estimate/size;
				cout << "The estimate wait time for customer " << q.getNumberHead()+1  <<" is " << Average <<" seconds." << endl; //This line is to display the estimate time of next consumer
				q.remove_head();
			}
		}
	}
	system("pause");
	return 0;
}

