#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;
class Student
{
private:
	string Name;
	double Number;
public:
	string getName();
	double getNumber();
	void setName(string newName);
	void setNumber(double newNum);
};
class checkInStream:public exception // This class is inherited from class Student and used as exception class to check the input file stream, though it is not 
{};                                // necessary to be inherited.
