
/**  
* @lab4.cpp  
* @author Phat Minh Tran 
* @Date   June 9, 2018  
* @version 1.0  
* @section LA01  
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the 
// work of others.  I acknowledged that I have read and followed the Academic Honesty and 
// Integrity related policies as outlined in the syllabus.
//
// _____ MINH PHAT TRAN ____      _____June 9, 2018______________ 
// 
// ____ 301297286 ______ 
// 

#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Pairs
{
public:
	Pairs( );                                         //Create default constructor
	Pairs(const int& first);                          //Create constructor
	Pairs(const int& first, const int& second);       //Create constructor
	//other members and friends
	Pairs operator+(const Pairs& r);                  //Overload (+) operator
	Pairs operator-(const Pairs& r);                  //Overload (-) operator
	Pairs operator*(const int& x);					  //Overload (*) operator
	friend istream& operator >>(istream& ins, Pairs& second);          //Overload input stream
	friend ostream& operator <<(ostream& outs, const Pairs& second);   //Overload output stream
private:
	int f;
	int s;
};
Pairs::Pairs()
{
	this->f = 0;
	this->s = 0;
}
Pairs::Pairs(const int& first)
{
	this->f = first;
	this->s = 0;	
}
Pairs::Pairs(const int& first, const int& second)
{
	this->f = first;
	this->s = second;	
}
Pairs Pairs::operator+(const Pairs& r)
{
	int a = this->f + r.f;
	int b = this->s + r.s;
	Pairs temp(a,b);
	return temp;
}
Pairs Pairs::operator-(const Pairs& r)
{
	int c = this->f - r.f;
	int d = this->s - r.s;
	Pairs temp(c,d);
	return temp;
}
Pairs Pairs::operator*(const int& x)
{
	int a = this->f * x;
	int b = this->s * x;
	Pairs temp(a,b);
	return temp;
}
istream& operator >>(istream& ins, Pairs& second) // Overload input stream to have format (a, b)
{
	char c;
	int a,b;
	ins >> c;
	ins >> second.f;
	ins >> c;
	ins >> second.s;
	ins >> c;
	return ins;
}
ostream& operator <<(ostream& outs, const Pairs& second) // Overload output stream to have format (a, b)
{
	outs << "("<<second.f<<", "<<second.s<<")"<<endl;
	return outs;
}

int main()
{
	cout << "Test constructors !" << endl;
	Pairs first, second(5), third(6,7);                                      //Test the constructors and default constructor
	
	cout << "The first pair is: " << first;
	cout << "The second pair is: " << second;
	cout << "The third pair is: " << third;
	Pairs user;
	cout << "Please enter your own pairs (entered pairs has type (a,b) or (a, b)): ";  
	cin >> user;
	if(cin.fail())                                                           //Test istream operator
	{
		cout<<"Your pairs is INVALID !"<<endl<<endl;
	}
	else
	{
		cout << "Your own pairs is: "<<user<<endl;
	}
	cout << "Test operators !" << endl;
	Pairs forth = first + user;                                               //Test (+) operator
	Pairs fifth = second - user;                                              //Test (-) operator
	Pairs sixth = user * 4;
	cout << "Sum of the first and your own pairs is: " << forth;              //Test ostream operator
	cout << "Deduction of the second and your own pairs is: " << fifth;       //Test ostream operator  
	cout << "Production of your own pairs and 4 is: " << sixth;               //Test ostream operator
	
	system("pause");
	return 0;
}
