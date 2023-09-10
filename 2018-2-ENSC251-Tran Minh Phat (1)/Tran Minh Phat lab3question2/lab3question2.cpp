/**  
* @lab3question2.cpp  
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


#include<iostream>
#include<string>
using namespace std;
class Car //Create class Car
{
private: //Create member variables
	int yearModel;
	string Make;
	int Speed;
public: //Create constructor, mutator, accessor and member functions 
	Car(const int& theyearModel, const string& theMake);
	int getyearModel()const;
	string getMake()const;
	int getSpeed()const;
	void Accelerate();
	void Brake();
};
Car::Car(const int& theyearModel, const string& theMake)
{
	this->yearModel = theyearModel;
	this->Make = theMake;
	this->Speed = 0;
}
int Car::getyearModel()const
{
	return this->yearModel;
}
string Car::getMake()const
{
	return this->Make;
}
int Car::getSpeed()const
{
	return this->Speed;
}
void Car::Accelerate()
{
	this->Speed = this->Speed + 5;
}
void Car::Brake()
{
	this->Speed = this->Speed - 5;
}
int _tmain(int argc, _TCHAR* argv[])
{
	Car First(2018,"Ford");
	cout<<"The year model of car is: "<<First.getyearModel()<<endl;
	cout<<"The make of car is: "<<First.getMake()<<endl;
	cout << "The current speed is:" <<First.getSpeed()<<endl;
	
	cout << "The car is accelerating! " << endl;

	for(int i = 0; i < 5; i++) //This car accelerates 5 times
	{
		First.Accelerate();
		cout << "The current speed is:" <<First.getSpeed()<<endl;
	}
	cout<<"AFTER ACCELERATING 5 TIMES, the speed of car is: "<<First.getSpeed()<<endl;
	cout<<endl;
	
	cout << "The car speed is braking! " << endl; //This car brakes 5 times
	for(int i = 0; i < 5; i++)
	{
		First.Brake();
		cout<< "The current speed is:" <<First.getSpeed()<<endl;
	}
	cout<<"AFTER BRAKING 5 TIMES, the speed of car is: "<<First.getSpeed()<<endl;
	cout<<endl;
	system("pause");
	return 0;
}

