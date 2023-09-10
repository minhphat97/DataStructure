/**  
* @homework2Question1.cpp  
* @author Phat Minh Tran 
* @Date   June 18, 2018  
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
#include <vector>
using namespace std;

int main()
{
	int next;
	vector<int> v;                      //Create vector v
	cin >> next;    
	if(next == -1)                      // Check input is invalid or not
	{
		cout << "Your input is invalid ! " << endl;
		system("pause");
		exit(1);

	}
	else if(cin.fail())                // Check input is invalid or not
	{
		cout << "Your input is INVALID ! " << endl;
		system("pause");
		exit(1);
	}
	while(next >= 0)                    //Use loop while to add element into the vector
	{
		v.push_back(next);
		cin >> next;
		if(cin.fail())
		{
			cout << "Your input is INVALID ! " << endl;            // Check input is invalid or not
			system("pause");
			exit(1);
		}
	}

	int temp;                            //This step is to sort vector from small elements tp large elements
	for(int i = 0; i < v.size(); i++)
	{
		for (int j = i+1; j< v.size(); j++)
		{
			if(v[j] < v[i])
			{
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}

	int size = 1;                              
	for(int i = 0; i < v.size()-1; i++)   //This step is to determine the size of the histogram array
	{
		if(v[i] != v[i+1])
		{
			size = size + 1;
		}
		else
		{
			size = size;
		}
	}

	
	int counter = 1;
	int* Histogram = new int[size];
	int j = 0;
	for(int i = 0; i < v.size()-1; i++)   //This step is to store the histogram of elements in vector into the the dynamic array Histogram
	{
		if(v[i] == v[i+1])
		{
			counter = counter + 1;
		}
		else if(v[i] != v[i+1])
		{
			Histogram[j] = counter;
			j = j + 1;
			counter = 1;
		}
	}
	Histogram[size - 1] = counter;        //This step is to display the histogram of elements in vector on the black screen

	j = 0;                                    
	for(int i = 0; i < v.size()-1; i++)   
	{
		
		if(v[i] != v[i+1])
		{
			cout << "Number of " << v[i] <<"'s: " << Histogram[j] << endl;
			j = j+1;
		}
	}
	cout << "Number of " << v[v.size()-1] <<"'s: " << Histogram[j] << endl;
	system("pause");
	return 0;
}

