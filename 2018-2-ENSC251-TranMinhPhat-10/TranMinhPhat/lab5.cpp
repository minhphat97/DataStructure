/**  
* @lab5.cpp  
* @author Phat Minh Tran 
* @Date   June 1, 2018  
* @version 1.0  
* @section LA01  
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the 
// work of others.  I acknowledged that I have read and followed the Academic Honesty and 
// Integrity related policies as outlined in the syllabus.
//
// _____ MINH PHAT TRAN ____      _____June 22, 2018______________ 
// 
// ____ 301297286 ______ 
// 


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void wordLadder(string Start, string End, string* A, int size, int index) //Create recursion function
{
	if(Start == End) //Recursion will stop when start word is same with end word
		return;
	else if(Start != End) //Recursion will occur when start word is not same with end word
	{
		int counter = 0;
		string originalStart = Start;
		if(Start[index] != End[index])
		{
			Start[index] = End[index];
		}
		for(int i = 0; i < size; i++)
		{
			if(Start == A[i] && originalStart[index] != End[index])
			{
				counter = counter + 1;
				cout << Start << endl;
			}
			else
			{
				counter = counter;
			}
		}
		if(counter != 0)
		{
			Start = Start;
		}
		else
		{
			Start = originalStart;
		}
		if(index == Start.length()-1)
		{
			wordLadder(Start,End,A,size,0); //Function is called recursively
		}
		else 
		{
			wordLadder(Start,End,A,size,index+1); //Function is called recursively
		}
	}
}
int main()
{
	ifstream fin("C:/Users/DELL/Desktop/words.txt"); //This is to connect to the text file. You can change the path which depends on file location in your PC.
	if(fin.fail()) 
	{
		cout << "Input file stream failed. " << endl;
		return 0;	
	}
	string x;
	string* A = new string[87314]; //This is to create the array to store all the value of text file
	for(int i = 0;i<87314;i++)
	{
		fin >> x;
		A[i] = x;
	}
	string Start,End;
	string originalStart;
	cout << "Please enter the start word which exits in the text file: "; //Input the start word
	cin >> Start;
	cout << "Please enter the end word which exits in the text file: "; //Input the end word
	cin >> End;
	int index = 0;
	wordLadder(Start,End,A,87314,index);
	fin.close(); //This is disconnect to text file
	system("pause");
	return 0;
}

