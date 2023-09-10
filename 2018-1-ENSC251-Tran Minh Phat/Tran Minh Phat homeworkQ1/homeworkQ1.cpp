/**  
* @homeworkQ1.cpp  
* @author Phat Minh Tran 
* @Date   June 1, 2018  
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


//This question I use time.h library to generate random numbers
#include<iostream>
#include<string>
#include<time.h>
using namespace std;

class Computer //Create class Computer
{
private: //Memeber variable
	int computerChoice; 
public: //Member functions
	Computer();
	int getcomputerChoice()const;
	string Changing (const int&computerChoice) const;
};
Computer::Computer()       //Constructor
{
	this->computerChoice=1+rand()%(3);
}

int Computer::getcomputerChoice()const  //Accessor
{
	return this->computerChoice;
}

string Computer::Changing (const int&computerChoice) const //This function is used to convert from random numbers to words (rock, paper, or scissors).
{
	string temp;
	if(this->getcomputerChoice() == 1)
	{
		temp="rock";
	}
	else if(this->getcomputerChoice() == 2)
	{
		temp="paper";
	}
	else if(this->getcomputerChoice() == 3)
	{
		temp="scissors";
	}
	return temp;
}
void Comparing(string A, string B) //This is not member function of class Computer and it is used to compare choices of user and computer. Also, it determines the winner.
{
	if(A=="rock" && B=="rock")
	{
		cout<<"Please play game again to determine the winner !"<<endl;
	}
	else if(A=="rock" && B=="scissors")
	{
		cout<<"User wins since the rock smashes the scissors !"<<endl;
	}
	else if(A=="rock" && B=="paper")
	{
		cout<<"Computer wins since paper wraps rock !"<<endl;
	}
	else if(A=="scissors" && B=="rock")
	{
		cout<<"Computer wins since the rock smashes the scissors !"<<endl;
	}
	else if(A=="scissors" && B=="scissors")
	{
		cout<<"Please play game again to determine the winner !"<<endl;
	}
	else if(A=="scissors" && B=="paper")
	{
		cout<<"User wins since scissors cuts paper !"<<endl;
	}
	else if(A=="paper" && B=="rock")
	{
		cout<<"User wins since paper wraps rock !"<<endl;
	}
	else if(A=="paper" && B=="scissors")
	{
		cout<<"Computer wins since scissors cuts paper !"<<endl;
	}
	else if(A=="paper" && B=="paper")
	{
		cout<<"Please play game again to determine the winner !"<<endl;
	}
}

int main()
{
	srand(time(NULL));
	string answer;
	Computer Dell;
	string userChoice;
	while(true)
	{
		answer=Dell.Changing(Dell.getcomputerChoice());

		cout<<"Please enter you choice (rock, paper, or scissors): ";
	
		cin>>userChoice;
	
		cout<<"The choice of computer is: "<< answer <<endl;

		Comparing(userChoice,answer);
	
		cout<<endl;
		if (userChoice!=answer)
			break;
	}
	system("pause");
	return 0;
}

