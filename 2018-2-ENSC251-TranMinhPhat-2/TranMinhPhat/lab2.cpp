// lab2.cpp : Defines the entry point for the console application.
//

#include<string>
#include<iostream>
using namespace std;

int main()
{
	//In this assignment, I only use one library function length () to calculate the length of variables string.
	//Step 1: Enter first and last name of user

	string First,Last;
	string firstTemp, lastTemp;

	cout<<"Please enter your first name: ";

	cin>>First;
	cout<<"Please enter your last name: ";

	cin>>Last;
	cout<<"Your full name is: "<<First<<" "<<Last<<endl;

	//Step 2: Check the full name is valid or not

	for(int i = 0; i < First.length(); i++)
	{
		if(First[i]<'A'||(First[i]>'Z'&&First[i]<'a')||First[i]>'z')
		{
			cout<<"Your first name is invalid !"<<endl;
			system("pause");
		}
	}

	for(int i = 0; i < Last.length(); i++)
	{
		if(Last[i]<'A'||(Last[i]>'Z'&&Last[i]<'a')||Last[i]>'z')
		{
			cout<<"Your last name is invalid !"<<endl;
			system("pause");
		}
	}

	//Step 3: Covert full name to all lower case

	for(int i = 0; i < First.length(); i++)
	{
		if(First[i]>='A' && First[i]<='Z')
		{
			First[i] = First[i] + 32;
		}
	}
	
	for(int i = 0; i < Last.length(); i++)
	{
		if(Last[i]>='A' && Last[i]<='Z')
		{
			Last[i] = Last[i] + 32;
		}
	}

	cout<<"After converting to lower case, your full name is: "<<First<<" "<<Last<<endl;

	//Step 4: Convert first name to PigLatin
	
	char temp1;

	if(First[0]=='a'||First[0]=='e'||First[0]=='i'||First[0]=='o'||First[0]=='u'||First[0]=='A'||First[0]=='E'||First[0]=='I'||First[0]=='O'||First[0]=='U')
	{
		firstTemp = First+"way";
	}

	else 
	{
		temp1 = First[0]; 

		for(int i=0;i<(First.length()-1);i++)
		{
			First[i] = First[i+1];
		}
		
		First[First.length()-1] = temp1; 

		firstTemp = First+"ay";
	}
	
	if (firstTemp[0]>='a'&&firstTemp[0]<='z')
	{
		firstTemp[0] = firstTemp[0]-32;
	}

	cout<<"After converting to PigLatin, your first name is: "<<firstTemp<<endl;
	
	//Step 5: Convert last name to PigLatin

	char temp2;

	if(Last[0]=='a'||Last[0]=='e'||Last[0]=='i'||Last[0]=='o'||Last[0]=='u'||Last[0]=='A'||Last[0]=='E'||Last[0]=='I'||Last[0]=='O'||Last[0]=='U')
	{
		lastTemp = Last+"way";
	}

	
	else 
	{
		temp2 = Last[0]; 

		for(int i=0;i<(Last.length()-1);i++)
		{
			Last[i] = Last[i+1];
		}
		
		Last[Last.length()-1] = temp2; 

		lastTemp = Last+"ay";
	}
	
	if (lastTemp[0]>='a'&&lastTemp[0]<='z')
	{
		lastTemp[0] = lastTemp[0]-32;
	}

	cout<<"After converting to PigLatin, your last name is: "<<lastTemp<<endl;
	cout<<"After converting to PigLatin, your full name is: "<<firstTemp+" "+lastTemp<<endl;
	cout<<endl;
	system("pause");
	return 0;
}

