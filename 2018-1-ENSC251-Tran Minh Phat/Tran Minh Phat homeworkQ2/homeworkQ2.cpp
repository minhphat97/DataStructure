/**  
* @homeworkQ2.cpp  
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

class Movie //Create class Movie
{
private: //Member variables
	string Name;
	string MPAArating;
	double Terrible;
	double Bad;
	double OK;
	double Good;
	double Great;
public: //Member functions
	Movie(const string&theName, const string&Rating);
	string getName()const;
	string getMPAArating()const;
	double getTerrible()const;
	double getBad()const;
	double getOK()const;
	double getGood()const;
	double getGreat()const;
	void setName(const string&theName);
	void setMPAArating(const string&Rating);
	void addRating(const int&Vote);
	double getAverage()const;
};
Movie::Movie(const string&theName, const string&Rating) //Constructor
{
	this->setName(theName);
	this->setMPAArating(Rating);
	this->Terrible = 0;
	this->Bad = 0;
	this->OK = 0;
	this->Good = 0;
	this->Great = 0;
}

void Movie::setName(const string&theName)
{
	this->Name=theName;
}

void Movie::setMPAArating(const string&Rating)
{
	this->MPAArating=Rating;
}

string Movie::getName() const
{
	return this->Name;
}

string Movie::getMPAArating() const
{
	return this->MPAArating;
}

double Movie::getTerrible()const
{
	return this->Terrible;
}

double Movie::getBad()const
{
	return this->Bad;
}

double Movie::getOK()const
{
	return this->OK;
}

double Movie::getGood()const
{
	return this->Good;
}

double Movie::getGreat()const
{
	return this->Great;
}

void Movie::addRating(const int&Vote)
{
	if(Vote==1)
	{
		this->Terrible = this->Terrible + 1;
	}
	else if(Vote==2)
	{
		this->Bad = this->Bad + 1;
	}
	else if(Vote==3)
	{
		this->OK = this->OK + 1;
	}
	else if(Vote==4)
	{
		this->Good = this->Good + 1;
	}
	else if(Vote==5)
	{
		this->Great = this->Great + 1;
	}
}

double Movie::getAverage()const //Calculate the average value
{
	double Average = (this->Terrible*1 + this->Bad*2 + this->OK*3 + this->Good*4 + this->Great*5)/(this->Terrible + this->Bad + this->OK + this->Good + this->Great);
	return Average;
}

int main()
{
	int Vote;
	double Average1, Average2;
	
	Movie First("The Avengers", "PG-13");
	cout<<"Please vote for The Avengers with the MPAA of PG-13"<<endl;
	for(int i = 0; i < 5; i++)//There are 5 users to rate this movie
	{
		cout<<"Please enter the number to rate this movie (1: Terrible, 2: Bad, 3: OK, 4: Good, 5: Great): ";
	    cin>>Vote;
	    First.addRating(Vote);
	}
	Average1 = First.getAverage();
	cout<<endl;
	 
	Movie Second("Justice League", "PG");
	cout<<"Please vote for Justice League with the MPAA of PG"<<endl;
	for(int i = 0; i < 5; i++)//There are 5 users to rate this movie
	{
		cout<<"Please enter the number to rate this movie (1: Terrible, 2: Bad, 3: OK, 4: Good, 5: Great): ";
	    cin>>Vote;
	    Second.addRating(Vote);
	}
	Average2 = Second.getAverage();
	cout<<"The "<<First.getName()<< " with the MPAA rating of "<<First.getMPAArating()<< " has the average rating of: "<<Average1<<endl;
    cout<<endl;
	
	cout<<"The "<<Second.getName()<< " with the MPAA rating of "<<Second.getMPAArating()<< " has the average rating of: "<<Average2<<endl;
    cout<<endl;
	system("pause");
	return 0;
}