//Note: Please check the original text file before you run this program. ***********************************************************************************
//The original file SHOULD NOT have line "The average of all numbers is... " at the beginning. *************************************************************#include <iostream>
//Assume the file named "content.txt" has the same address with CPP files in computer.
#include <fstream>
#include <string>
#include <exception>
#include "ClassExercise2.h"
using namespace std;
void writingFile(ofstream& outStream, int&size, Student*store);
void readingFile(ifstream& inStream, int&size, Student*store);
int main()
{
	try
	{
		ifstream fin("content.txt"); // This is input stream
		if(fin.fail())
		{
			throw checkInStream();
		}
	
		int size = 0;
		string line;
		while(getline(fin,line))
		{
			size = size + 1;
		}
		
		fin.clear();              //This will move fin to the beginning of text file 
		fin.seekg(0,ios::beg);

		Student * store = new Student[size];
		readingFile(fin,size,store);   //This function is to read data from text file and store them into a class named "store"

		ofstream fout("content.txt");
		int Throw;
		if(fout.fail())
		{
			cout << "Error output stream" << endl;
		} 
	
		writingFile(fout,size,store); // This function is to write Average and data to text file

		fout.close();
		fin.close();
	}
	catch(checkInStream) //This catch block is to check input file stream exception
	{
		cout << "Your input file stream had problem. Please check your input stream again. Thank you " << endl; 
	}
	catch(invalid_argument &e) //This catch block is to check invalid_argument exception
	{
		cout << "The text file maybe empty. Please check you text file again. Thank you " << endl;
	}
	system("pause");
	return 0;
}