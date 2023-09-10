/**  
* @Lab7.cpp  
* @author Phat Minh Tran 
* @Date   July 9, 2018  
* @version 1.0  
* @section LA01  
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the 
// work of others.  I acknowledged that I have read and followed the Academic Honesty and 
// Integrity related policies as outlined in the syllabus.
//
// _____ MINH PHAT TRAN ____      _____July9, 2018______________ 
// 
// ____ 301297286 ______ 
// 

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
class Book
{
private:
	string Name;
	string Date;
	string Title;
public:
	Book(string theName, string theDate, string theTitle);
	void setName(string theName);
	void setDate(string theDate);
	void setTitle(string theTitle);
	string getName();
	string getDate();
	string getTitle();
	bool operator < (Book theBook);
};
Book::Book(string theName, string theDate, string theTitle)
{
	Name = theName;
	Date = theDate;
	Title = theTitle;
}
bool Book::operator < (Book theBook)
{
	if(Name < theBook.Name)
		return true;
	else
		return false;
}

void Book::setName(string theName)
{
	Name = theName;
}
void Book::setDate(string theDate)
{
	Date = theDate;
}
void Book::setTitle(string theTitle)
{
	Title = theTitle;
}
string Book::getName()
{
	return Name;
}
string Book::getDate()
{
	return Date;
}
string Book::getTitle()
{
	return Title;
}

bool Compare(Book a, Book b)
{
	return a.getName() < b.getName();
}


int main()
{
	int Answer;
	vector<Book>theBook;
	while(true)
	{
		cout << "Select form the following choices:" << endl;
		cout << "1. Add the new book" << endl;
		cout << "2. Print listing sorted by author" << endl;
		cout << "3. Quit" << endl;
		cin >> Answer;
		if (Answer == 1)
		{
			char C;
			string Title1,Title2,Title;
			string Name1,Name2,Name;
			string Date1,Date2,Date;
			cout << "Enter title:" << endl;
			cin >> Title;
			getline(cin,Title);
			
			
			cout << "Enter author:" << endl;
			cin >> Name;
			getline(cin,Name);

			cout << "Enter date:" << endl;
			cin >> Date;
			
			

			theBook.push_back(Book(Name,Date,Title));
			
		}
		else if(Answer == 2)
		{
			sort(theBook.begin(),theBook.end(),Compare);
			cout << "The books entered so far, sorted alphabetically by author are:" <<endl;
			for (int i = 0; i< theBook.size();i++)
			{
				cout << "  "<<theBook[i].getName()<<". "<<theBook[i].getTitle()<<". " <<theBook[i].getDate()<<"."<<endl;
			}
		}
		else if(Answer == 3)
		{
			break;
		}
	}
	system("pause");
	return 0;
}

