/**  
* @lab3question1.cpp  
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
class Patient  //Create class Patient
{
private: //Create member variables
	string firstName;
	string middleName;
	string lastName;
	string Address;
	string City;
	string State;
	string Zip;
	string Phone;
	string emergencyName;
	string emergencyPhone;
public: //Create constructor, mutator, accessor and member function
	Patient(const string& thefirstName, const string& themiddleName, const string& thelastName, const string& theAddress, const string& theCity, const string& theState, const string& theZip, const string& thePhone, const string& theemergencyName, const string& theemergencyPhone);  
	void setfirstName(const string& thefirstName);
	void setmiddleName(const string& themiddleName);
	void setlastName(const string& thelastName);
	void setAddress(const string& theAddress);
	void setCity(const string& theCity);
	void setState(const string& theState);
	void setZip(const string& theZip);
	void setPhone(const string&thePhone);
	void setemergencyName(const string& theemergencyName);
	void setemergencyPhone(const string& theemergencyPhone);
	string getfirstName()const;
	string getmiddleName()const;
	string getlastName()const;
	string getAddress()const;
	string getCity()const;
	string getState()const;
	string getZip()const;
	string getPhone()const;
	string getemergencyName()const;
	string getemergencyPhone()const;
};
Patient::Patient(const string& thefirstName, const string& themiddleName, const string& thelastName, const string& theAddress, const string& theCity, const string& theState, const string& theZip, const string& thePhone, const string& theemergencyName, const string& theemergencyPhone)
{
	this->setfirstName(thefirstName);
	this->setmiddleName(themiddleName);
	this->setlastName(thelastName);
	this->setAddress(theAddress);
	this->setCity(theCity);
	this->setState(theState);
	this->setZip(theZip);
	this->setPhone(thePhone);
	this->setemergencyName(theemergencyName);
	this->setemergencyPhone(theemergencyPhone);
}

void Patient::setfirstName(const string&thefirstName)
{
	this->firstName = thefirstName;
}
void Patient::setmiddleName(const string& themiddleName)
{
	this->middleName = themiddleName;
}
void Patient::setlastName(const string& thelastName)
{
	this->lastName = thelastName;
}
void Patient::setAddress(const string& theAddress)
{
	this->Address = theAddress;
}
void Patient::setCity(const string& theCity)
{ 
	this->City = theCity;
}
void Patient::setState(const string& theState)
{
	this->State = theState;
}
void Patient::setZip(const string& theZip)
{
	this->Zip = theZip;
}
void Patient::setPhone(const string& thePhone)
{
	this->Phone = thePhone;
}
void Patient::setemergencyName(const string& theemergencyName)
{
	this->emergencyName = theemergencyName;
}
void Patient::setemergencyPhone(const string& theemergencyPhone)
{
	this->emergencyPhone = theemergencyPhone;
}
string Patient::getfirstName()const
{
	return this->firstName;
}
string Patient::getmiddleName()const
{
	return this->middleName;
}
string Patient::getlastName()const
{
	return this->lastName;
}
string Patient::getAddress()const
{
	return this->Address;
}
string Patient::getCity()const
{
	return this->City;
}
string Patient::getState()const
{
	return this->State;
}
string Patient::getZip()const
{
	return this->Zip;
}
string Patient::getPhone()const
{
	return this->Phone;
}
string Patient::getemergencyName()const
{
	return this->emergencyName;
}
string Patient::getemergencyPhone()const
{
	return this->emergencyPhone;
}
class Procedure //Create class Procedure
{
private: //Create member variables
	string procedureName;
	string Date;
	string Practitioner;
	double Charge;
public: //Create constructor, member functions, mutator and accessor
	Procedure(const string& theName, const string& theDate, const string& thePractitioner, const double& theCharge);
	void setprocedureName(const string& theName);
	void setPractitioner(const string& thePractitioner);
	void setDate(const string& theDate);
	void setCharge(const double& theCharge);
    string getprocedureName()const;
	string getPractitioner()const;
	string getDate()const;
	double getCharge()const;
};
Procedure::Procedure(const string& theName, const string& theDate, const string& thePractitioner, const double& theCharge)
{
	this->setprocedureName(theName);
	this->setDate(theDate);
	this->setPractitioner(thePractitioner);
	this->setCharge(theCharge);
}
void Procedure::setprocedureName(const string& theName)
{
	this->procedureName = theName;
}
void Procedure::setPractitioner(const string& thePractitioner)
{
	this->Practitioner = thePractitioner;
}
void Procedure::setDate(const string& theDate)
{
	this->Date = theDate;
}
void Procedure::setCharge(const double& theCharge)
{
	this->Charge = theCharge;
}
string Procedure::getprocedureName()const
{
	return this->procedureName;
}
string Procedure::getPractitioner()const
{
	return this->Practitioner;
}
string Procedure::getDate()const
{
	return this->Date;
}
double Procedure::getCharge()const
{
	return this->Charge;
}


int main()
{
	Patient First("Phat","Minh","Tran","7366 Union Street","Burnaby","British Columbia","V5A 1J2","778-869-7849","Lionel Messi","778-869-7848");
	Procedure firstProcedure("Physical Exam","May 28, 2018","Dr. Ivrine",250.00);
	Procedure secondProcedure("X-ray","May 28, 2018","Dr. Jaminson",500.00);
	Procedure thirdProcedure("Blood test","May 28, 2018","Dr. Smith",200.00);

	cout<<"The first name of patient is: "<<First.getfirstName()<<endl;
	cout<<"The middle name of patient is: "<<First.getmiddleName()<<endl;
	cout<<"The last name of patient is: "<<First.getlastName()<<endl;
	cout<<"The address of patient is: "<<First.getAddress()<<endl;
	cout<<"The city of patient is: "<<First.getCity()<<endl;
	cout<<"The state of patient is: "<<First.getState()<<endl;
	cout<<"The ZIP code of patient is: "<<First.getZip()<<endl;
	cout<<"The phone number of patient: "<<First.getPhone()<<endl;
	cout<<"The name of emergency: "<<First.getemergencyName()<<endl;
	cout<<"The phone of emergency: "<<First.getemergencyPhone()<<endl;
	cout<<endl;
	
	cout<<"The first procedure is: "<<firstProcedure.getprocedureName()<<endl;
	cout<<"The date of first procedure: "<<firstProcedure.getDate()<<endl;
	cout<<"The practitioner of first procedure: "<<firstProcedure.getPractitioner()<<endl;
	cout<<"The charge fee of first procedure: "<<"$"<<firstProcedure.getCharge()<<endl;
	cout<<endl;
	cout<<"The second procedure is: "<<secondProcedure.getprocedureName()<<endl;
	cout<<"The date of second procedure: "<<secondProcedure.getDate()<<endl;
	cout<<"The practitioner of second procedure: "<<secondProcedure.getPractitioner()<<endl;
	cout<<"The charge fee of second procedure: "<<"$"<<secondProcedure.getCharge()<<endl;
	cout<<endl;
	cout<<"The third procedure is: "<<thirdProcedure.getprocedureName()<<endl;
	cout<<"The date of third procedure: "<<thirdProcedure.getDate()<<endl;
	cout<<"The practitioner of third procedure: "<<thirdProcedure.getPractitioner()<<endl;
	cout<<"The charge fee of third procedure: "<<"$"<<thirdProcedure.getCharge()<<endl;
	cout<<endl;
	cout<<"The total charges of the three procedures: "<<"$"<<firstProcedure.getCharge()+secondProcedure.getCharge()+thirdProcedure.getCharge()<<endl;
	cout<<endl;
	system("pause");
	return 0;
}

