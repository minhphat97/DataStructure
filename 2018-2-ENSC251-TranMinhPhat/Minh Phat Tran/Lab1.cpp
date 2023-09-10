/**
 * @file lab1.cpp
 * @author FirstName LastName
 * @Date   9/12/2017
 * @version 1.0
 * @section DESCRIPTION 
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____MINH PHAT TRAN ____      _____18th May, 2018______________
//
// ____ 301297286 ______

#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void calculateCost(string Day, string Time, int Length);
	
int main()
{
	string Time;
	string Day;
	int Length; 
	
	string Statement;
	for (int i = 1; i > 0; i++)
	{
		cout << "Please enter your day: ";
		cin >> Day;
		cout<<"Please enter the input starting time: ";
		cin>>Time;
		cout << "Please enter your call length: ";
		cin >> Length;
		calculateCost(Day, Time, Length);
		
		cout<<"Are you done ? ";
		cin>>Statement;
		if (Statement == "Yes"||Statement=="yes")
		{
			break;
		}
		else if(Statement == "No"||Statement=="no")
		{
			continue;
		}
		else
		{
			cout<<"I cannot understand your answer but you can continue !"<<endl;
		}
	}
	system("pause");
	return 0;
}

/**
 * @brief DESCRIPTION
 *
 * @param a is 
 * @param b is 
 * @return void
 *
 */
void calculateCost(string Day, string Time, int Length)
{
	float cost;
	if (Day == "Mo" || Day == "Tu" || Day == "We" || Day == "Th" || Day == "Fr"||Day == "mo" || Day == "tu" || Day == "we" || Day == "th" || Day == "fr"||Day == "mO" || Day == "tU" || Day == "wE" || Day == "tH" || Day == "fR"||Day == "MO" || Day == "TU" || Day == "WE" || Day == "TH" || Day == "FR")
	{
		
		if((Time[0]=='0')&&(Time[1]>='0'&&Time[1]<='7')&&(Time[2]==':')&&(Time[3]>='0'&&Time[3]<='5')&&(Time[4]>='0'&&Time[4]<='9'))
		{
			cost = 0.25*Length;
			cout<<"Your total cost is: $"<<cost<<endl;
		}
		else if((Time[0]=='1')&&(Time[1]>='8'&&Time[1]<='9')&&(Time[2]==':')&&(Time[3]>='0'&&Time[3]<='5')&&(Time[4]>='0'&&Time[4]<='9'))
		{
			cost = 0.25*Length;
			cout<<"Your total cost is: $"<<cost<<endl;
		}
		else if((Time[0]=='2')&&(Time[1]>='0'&&Time[1]<='3')&&(Time[2]==':')&&(Time[3]>='0'&&Time[3]<='5')&&(Time[4]>='0'&&Time[4]<='9'))
		{
			cost = 0.25*Length;
			cout<<"Your total cost is: $"<<cost<<endl;
		}
		else if((Time[0]>='0')&&(Time[1]>='8'&&Time[1]<='9')&&(Time[2]==':')&&(Time[3]>='0'&&Time[3]<='5')&&(Time[4]>='0'&&Time[4]<='9'))
		{
			cost = 0.4*Length;
			cout<<"Your total cost is: $"<<cost<<endl;
		}
		else if((Time[0]=='1')&&(Time[1]>='0'&&Time[1]<='7')&&(Time[2]==':')&&(Time[3]>='0'&&Time[3]<='5')&&(Time[4]>='0'&&Time[4]<='9'))
		{
			cost = 0.4*Length;
			cout<<"Your total cost is: $"<<cost<<endl;
		}
		else if((Time[0]=='1')&&(Time[1]>='8')&&(Time[2]==':')&&(Time[3]>='0')&&(Time[4]>='0'))
		{
			cost = 0.4*Length;
			cout<<"Your total cost is: $"<<cost<<endl;
		}

		else
		{
			cout << "Your input starting time is wrong !" << endl;
		}


	}
	else if (Day == "Sa" || Day == "Su"||Day == "sa" || Day == "su"||Day == "sA" || Day == "sU"||Day == "SA" || Day == "SU")
	{
		if((Time[0]=='0')&&(Time[1]>='0'&&Time[1]<='9')&&(Time[2]==':')&&(Time[3]>='0'&&Time[3]<='5')&&(Time[4]>='0'&&Time[4]<='9'))
		{
			cost=0.15*Length;
			cout<<"Your total cost is: $"<<cost<<endl;
		}
		else if((Time[0]=='1')&&(Time[1]>='0'&&Time[1]<='9')&&(Time[2]==':')&&(Time[3]>='0'&&Time[3]<='5')&&(Time[4]>='0'&&Time[4]<='9'))
		{
			cost=0.15*Length;
			cout<<"Your total cost is: $"<<cost<<endl;
		}
		else if((Time[0]=='2')&&(Time[1]>='0'&&Time[1]<='3')&&(Time[2]==':')&&(Time[3]>='0'&&Time[3]<='5')&&(Time[4]>='0'&&Time[4]<='9'))
		{
			cost=0.15*Length;
			cout<<"Your total cost is: $"<<cost<<endl;
		}
		else
		{
			cout << "Your input starting time is wrong !" << endl;
		}
	}
		
	else
	{
		cout << "Your imput day is wrong !" << endl;
	}
}

