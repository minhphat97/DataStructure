/**  
* @homework3Question1.cpp  
* @author Phat Minh Tran 
* @Date   July 5, 2018  
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



#include <iostream>
#include <string>
using namespace std;
class Person //Create class Person which has member variable name
{
private:
	string name;
public:
	Person();
	Person(string theName);
	Person(const Person& theObject);
	string getName() const;
	Person& operator = (const Person& rSide);
	friend istream& operator >> (istream& inStream, Person& personObject);
	friend ostream& operator << (ostream& outStream, const Person& personObject);
};
Person::Person() //Default constructor
{
	name = "";
}
Person::Person(string theName) //Constructor has one parameter theName
{
	name = theName;
}
Person::Person(const Person& theObject) //Copy constructor
{
	name = theObject.name;
};
string Person::getName()const //Accessor
{
	return name;
}
Person& Person::operator = (const Person& rSide) //Overload assignment operator
{
	if(this == &rSide)
		return *this;
	else
	{
		name = rSide.name;
		return *this;
	}
}
istream& operator >> (istream& inStream, Person& personObject) //Overload input operator
{
	string Name;
	cout << "Please enter the name of owner: ";
	inStream >> Name;
	personObject = Person(Name);
	return inStream;
}
ostream& operator << (ostream& outStream, const Person& personObject) //Overload output operator
{
	outStream << personObject.name << endl;
	return outStream;
}

class Vehicle //Create base class Vehicle
{
private:
	string manufacturerName;
	int Cylinders;
	Person Owner;
public:
	Vehicle();
	Vehicle(string themanufacturerName, int theCylinders, Person theOwner);
	Vehicle(const Vehicle& otherObject);
	Vehicle& operator=(const Vehicle& otherObject);
	string getmanufacturerName();
	int getCylinders();
	Person getOwner();
	void setmanufacturerName(string themanufacturerName);
	void setCylinders(int theCylinders);
	void setOwner(Person theOwner);
	void print();
};
Vehicle& Vehicle::operator=(const Vehicle& otherObject) //Overload assignment operator
{
	if(this == &otherObject)
		return *this;
	else
	{
		manufacturerName = otherObject.manufacturerName;
		Cylinders = otherObject.Cylinders;
		Owner = otherObject.Owner;
		return *this;
	}
}

Vehicle::Vehicle() //Default constructor
{
	manufacturerName = "";
	Cylinders = 0;
	Owner = Person();
}
Vehicle::Vehicle(string themanufacturerName, int theCylinders, Person theOwner) //Constructor
{
	manufacturerName = themanufacturerName;
	Cylinders = theCylinders;
	Owner = theOwner;
}
Vehicle::Vehicle(const Vehicle& otherObject) //Copy construcot
{
	manufacturerName = otherObject.manufacturerName;
	Cylinders = otherObject.Cylinders;
	Owner = otherObject.Owner;
}
string Vehicle::getmanufacturerName() //Accessor
{
	return manufacturerName;
}
int Vehicle::getCylinders() //Accessor
{
	return Cylinders;
}
Person Vehicle::getOwner() //Accessor
{
	return Owner;
}
void Vehicle::setmanufacturerName(string themanufacturerName) //Mutator
{
	manufacturerName = themanufacturerName;
}
void Vehicle::setCylinders(int theCylinders) //Mutator
{
	Cylinders = theCylinders;
}
void Vehicle::setOwner(Person theOwner) //Mutator
{
	Owner = theOwner;
}
void Vehicle::print() //this function is used to print
{
	cout << "Owner: " << Owner;
	cout << "Manufacturer's name: " << manufacturerName << endl;
	cout << "Number of cylinders in the engine: " << Cylinders << endl;
}
class Truck:public Vehicle //Create derived class Truck
{ 
 private:
	double loadCapacity;
	int towCapacity;
public:
	Truck();
	Truck(string themanufacturerName, int theCylinders, Person theOwner, double theloadCapacity, int thetowCapacity);
	Truck(const Truck& otherObject);
	Truck& operator = (const Truck& otherObject);
	double getloadCapacity();
	int gettowCapacity();
	void setloadCapacity(double theloadCapacity);
	void settowCapacity(int thetowCapacity);
	void print();
};

Truck::Truck():Vehicle(), loadCapacity(0), towCapacity(0) //Default constructor
{}
Truck::Truck(string themanufacturerName, int theCylinders, Person theOwner, double theloadCapacity, int thetowCapacity):Vehicle(themanufacturerName,theCylinders,theOwner),loadCapacity(theloadCapacity),towCapacity(thetowCapacity) //Constructor
{}
Truck::Truck(const Truck& otherObject):Vehicle(otherObject) //Copy constructor
{
	loadCapacity = otherObject.loadCapacity;
	towCapacity = otherObject.towCapacity;
}
Truck& Truck::operator = (const Truck& otherObject) //Overload assignment operator
{
	if(this == &otherObject)
		return *this;
	else
	{
		Vehicle::operator=(otherObject);
		loadCapacity = otherObject.loadCapacity;
		towCapacity = otherObject.towCapacity;
		return *this;
	}
}
double Truck::getloadCapacity() //Accessor
{
	return loadCapacity;
}
int Truck::gettowCapacity() //Accessor
{
	return towCapacity;
}
void Truck::setloadCapacity(double theloadCapacity) //Accessor
{
	loadCapacity = theloadCapacity;
}
void Truck::settowCapacity(int thetowCapacity) //Accessor
{
	towCapacity = thetowCapacity;
}
void Truck::print() //This function is used to print
{
	Vehicle::print();
	cout << "Load capacity in tons: " << loadCapacity << endl;
	cout << "Towing capacity in pounds: " << towCapacity << endl;
}

int main()
{
	Person p1("Lionel Messi"); //Constructor
	Truck t1("Barcelona FC",6,p1,25,4000); //Constructor
	Truck t2 = t1; //Copy constructor
	Truck t3; //Construcor 
	t3 = t2; //Asignment operator
	cout << "Details of Truck #1..." << endl;
	t1.print(); 
	cout << endl;
	cout << "Details of Truck #2..." << endl;
	t2.print();
	cout << endl;
	cout << "Details of Truck #3..." << endl;
	t3.print();
	cout << endl;
	Truck t4(t3); //Copy construcor
	cout << "Details of Truck #4..." << endl;
	t4.print();
	cout << endl << endl;
	system("pause");
	return 0;
}

