//Note: Please check the original text file before you run this program. ***********************************************************************************
//The original file SHOULD NOT have line "The average of all numbers is... " at the beginning. *************************************************************
//Assume the file named "content.txt" has the same address with CPP files in computer.
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "ClassExercise2.h"
using namespace std;
//Pre-condition: Before calling this function, the original text file is still unchanged
//Post-condition: After calling this function, all the data in text file will be stored in the array of type Student
void readingFile(ifstream& inStream, int&size, Student*store)
{
	if(size == 0)
	{
		throw invalid_argument("size of zero is invalid");
	}

	string storedName;
	double storedNum;
	
	for (int i = 0; i < size; i++)
	{
		inStream >> storedName >> storedNum;
		store[i].setName(storedName);
		store[i].setNumber(storedNum);
	}
	cout << "Function readingFile worked successfully " << endl;
}
//Pre-condition: Before calling this function, there is no calculation average of all data in the text file.
//Post-condition: After calling this function, the average of all data in the text file has been calculated.
double calAverage(int&size, Student*store) 
{
	if(size == 0)
	{
		throw invalid_argument("size of zero is invalid");
	}
	double Sum = 0;
	for (int i = 0; i < size; i++)
	{
		Sum = Sum + store[i].getNumber();
	}

	double Average;
	Average = Sum / size;
	cout << "Function calAverage worked successfully " << endl;
	return Average;
}
//Pre-condition: Before calling this function, the original text file is still unchanged.
//Post-condition: After calling this function, the text file has a new line at the beginning with the average of all data.
void writingFile(ofstream& outStream, int&size, Student*store)
{
	if(size == 0)
	{
		throw invalid_argument("size of zero is invalid");
	}
	double Average = calAverage(size, store); 
	outStream << "The average of all the numbers is " << Average << endl; 
	for (int i = 0; i < size; i++)
	{
		outStream << store[i].getName() << " " << store[i].getNumber() << endl;
	}
	cout << "Function writingFile worked successfully " << endl;
}

string Student::getName()
{
	return Name;
}
double Student::getNumber()
{
	return Number;
}
void Student::setName(string newName)
{
	this->Name = newName;
}
void Student::setNumber(double newNum)
{
	this->Number = newNum;
}
