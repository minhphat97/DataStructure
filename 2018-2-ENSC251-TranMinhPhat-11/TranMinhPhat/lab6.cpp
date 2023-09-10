/**  
* @lab6.cpp  
* @author Phat Minh Tran 
* @Date   June 30, 2018  
* @version 1.0  
* @section LA01  
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the 
// work of others.  I acknowledged that I have read and followed the Academic Honesty and 
// Integrity related policies as outlined in the syllabus.
//
// _____ MINH PHAT TRAN ____      _____June 30, 2018______________ 
// 
// ____ 301297286 ______ 
// 

#include <iostream>
#include <string>
using namespace std;
class TimeFormatMistake  //Create class to process the time format mistake
{
private: //This class has one member variable Time
	string Time;   
public:  //This class has one member function and two constructors             
	TimeFormatMistake();
	TimeFormatMistake(string theTime);
	string getTime();
};
TimeFormatMistake::TimeFormatMistake() //Default constructor
{}
TimeFormatMistake::TimeFormatMistake(string theTime) //Constructor
{
	Time = theTime;
}
string TimeFormatMistake::getTime() //Accessor function has type string
{
	return Time;
}
int main()
{
	//---------------------------------Note: 24 Hour Time is from 00:00 to 23:59 and 12 Hour Time is from 12:00 AM to 11:59 PM------------------------------------------------------------------------
	      
	string Time;
	char Answer;
	while(true)
	{
		try
		{
			cout << "Enter time in 24-hour notation: " <<endl; 
			cin >> Time;
		
			if(Time[0] == '0' &&  Time[1] == '0' && Time[2] == ':' && (Time[3] >= '0' && Time[3] <= '5') && (Time[4] >= '0' && Time[4] <= '9'))//This condition is applied to the format input from 00:00
			{                                                                                                                                  // to 00:59 of 24hr notation
				Time[0] = '1';
				Time[1] = '2';
				cout << "That is same as" << endl;
				cout << Time << " " << "AM" << endl;
				cout << "Again? (y/n)" << endl;
				cin >> Answer;
				if (Answer == 'n')
				{
					cout << "End of program" <<endl;
					break;
				}
			}
			else if((Time[0] == '0') && (Time[1] >= '1' && Time[1] <= '9') &&(Time[2]==':') && (Time[3] >= '0' && Time[3] <= '5') && (Time[4] >= '0' && Time[4] <= '9'))//This condition is applied to the format input from 01:00
			{                                                                                                                                                           //to 09:59 of 24hr notation
				cout << "That is same as" << endl;
				cout << Time << " " << "AM" << endl;
				cout << "Again? (y/n)" << endl;
				cin >> Answer;
				if (Answer == 'n')
				{
					cout << "End of program" <<endl;
					break;
				}
			}
			else if((Time[0] == '1') && (Time[1] >='0' && Time[1] <= '1') && (Time[2]==':') && (Time[3] >= '0' && Time[3] <= '5') && (Time[4] >= '0' && Time[4] <= '9'))//This condition is applied to the format input from 10:00
			{                                                                                                                                                           //to 11:59 of 24hr notation
				cout << "That is same as" << endl;
				cout << Time << " " << "AM" << endl;
				cout << "Again? (y/n)" << endl;
				cin >> Answer;
				if (Answer == 'n')
				{
					cout << "End of program" <<endl;
					break;
				}
			}
			else if(Time[0] == '1' &&  Time[1] == '2' && Time[2] == ':' && (Time[3] >= '0' && Time[3] <= '5') && (Time[4] >= '0' && Time[4] <= '9'))//This condition is applied to the format input from 12:00
			{                                                                                                                                       //to 12:59 of 24hr notation 
				Time[0] = '1';
				Time[1] = '2';
				cout << "That is same as" << endl;
				cout << Time << " " << "PM" << endl;
				cout << "Again? (y/n)" << endl;
				cin >> Answer;
				if (Answer == 'n')
				{
					cout << "End of program" <<endl;
					break;
				}
			}
			else if((Time[0] == '1') && (Time[1] >='3' && Time[1] <= '9') && (Time[2]==':') && (Time[3] >= '0' && Time[3] <= '5') && (Time[4] >= '0' && Time[4] <= '9'))//This condition is applied to the format input from 13:00
			{                                                                                                                                                           //to 19:59 of 24hr notation 
				Time[0] = '0';
				Time[1] = Time[1] - 2 ;
				cout << "That is same as" << endl;
				cout << Time << " " << "PM" <<endl;
				cout << "Again? (y/n)" << endl;
				cin >> Answer;
				if (Answer == 'n')
				{
					cout << "End of program" <<endl;
					break;
				}
			}
			else if(Time[0] == '2' && Time[1] == '0' && Time[2] == ':' && (Time[3] >= '0' && Time[3] <= '5') && (Time[4] >= '0' && Time[4] <= '9'))//This condition is applied to format input from 20:00
			{                                                                                                                                      //to 20:59 of 24hr notation
				Time[0] = '0';
				Time[1] = '8';
				cout << "That is same as" << endl;
				cout << Time << " " << "PM" <<endl;
				cout << "Again? (y/n)" << endl;
				cin >> Answer;
				if (Answer == 'n')
				{
					cout << "End of program" <<endl;
					break;
				}
			}
			else if(Time[0] == '2' && Time[1] == '1' && Time[2] == ':' && (Time[3] >= '0' && Time[3] <= '5') && (Time[4] >= '0' && Time[4] <= '9'))//This condition is apllied to format input from 21:00
			{                                                                                                                                      //to 21:59 of 24hr notation
				Time[0] = '0';
				Time[1] = '9';
				cout << "That is same as" << endl;
				cout << Time << " " << "PM" <<endl;
				cout << "Again? (y/n)" << endl;
				cin >> Answer;
				if (Answer == 'n')
				{
					cout << "End of program" <<endl;
					break;
				}
			}
			else if((Time[0] == '2') && (Time[1] >='2' && Time[1] <= '3') && (Time[2]==':') && (Time[3] >= '0' && Time[3] <= '5') && (Time[4] >= '0' && Time[4] <= '9'))//This condition is applied to format input from 22:00
			{                                                                                                                                                           //to 23:59 of 24hr notation
				Time[0] = '1';
				Time[1] = Time[1] - 2;
				cout << "That is same as" << endl;
				cout << Time << " " << "PM" <<endl;
				cout << "Again? (y/n)" << endl;
				cin >> Answer;
				if (Answer == 'n')
				{
					cout << "End of program" <<endl;
					break;
				}
			}
			else //This conditon is applied to time mistakes
			{
				throw TimeFormatMistake(Time);
			}
		}
		catch(TimeFormatMistake e) //Use try-throw-catch to check mistakes
		{
			cout << "There is no such time as " << e.getTime() <<endl;
			cout << "Try again:" << endl;
		}
		
	}
	system("pause");
	return 0;
}

