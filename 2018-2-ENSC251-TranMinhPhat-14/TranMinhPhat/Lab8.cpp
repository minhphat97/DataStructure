/**  
* @Lab8.cpp  
* @author Phat Minh Tran 
* @Date   July 20, 2018  
* @version 1.0  
* @section LA01  
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the 
// work of others.  I acknowledged that I have read and followed the Academic Honesty and 
// Integrity related policies as outlined in the syllabus.
//
// _____ MINH PHAT TRAN ____      _____July 20, 2018______________ 
// 
// ____ 301297286 ______ 
// 

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int counter = 0;
	string Date;
	string Open, High, Low, Close, AdjClose, Volume;
	string Day, Month, Year;
	//Create input file stream
	ifstream fin ("StockPrices.csv");
	if(fin.fail())
	{
		cout << "Input file stream failed. " << endl;
		system("pause");
		return 0;
	}
	//Since we do not need the first line in csv file, I use Dummy variable within getline to skip the first line.
	string Dummy;
	getline(fin,Dummy,'\n');
	//This loop is used to dtermine the number of lines in the csv file
	while(!fin.eof())
	{
		getline(fin, Date, ',');
		getline(fin, Open, ',');
		getline(fin, High, ',');
		getline(fin, Low, ',');
		getline(fin, Close, ',');
		getline(fin, AdjClose, ',');
		getline(fin, Volume, '\n');
		counter = counter + 1;
	}
	fin.close(); //Close input stream file
	
	//Create input stream file again
	ifstream fin1("StockPrices.csv");
	if(fin1.fail())
	{
		cout << "Input file stream failed. " << endl;
		return 0;
	}
	//Since we do not need the first line in csv file, I use Dummy variable within getline to skip the first line.
	getline(fin1,Dummy,'\n');
	//Create Array which is to store first column elements
	string*First = new string[counter];
	for(int i = 0; i < counter; i++)
	{
		getline(fin1, Date, ',');
		getline(fin1, Open, ',');
		getline(fin1, High, ',');
		getline(fin1, Low, ',');
		getline(fin1, Close, ',');
		getline(fin1, AdjClose, ',');
		getline(fin1, Volume, '\n');
		First[i] = Date;
	}
	
	fin1.close();//Close input stream file again
	//Create input stream file again
	ifstream fin2("StockPrices.csv");
	if(fin2.fail())
	{
		cout << "Input file stream failed. " << endl;
		return 0;
	}
	
	getline(fin2,Dummy);
	//Create Array which is to store third column elements and then convert all the elements from string to double type
	double*Third = new double[counter];
	for(int i = 0; i < counter; i++)
	{
		getline(fin2, Date, ',');
		getline(fin2, Open, ',');
		getline(fin2, High, ',');
		getline(fin2, Low, ',');
		getline(fin2, Close, ',');
		getline(fin2, AdjClose, ',');
		getline(fin2, Volume, '\n');
		double HighElement = stod(High);
		Third[i] = HighElement;
	}
	fin2.close();//Close input stream file again
	//Create input stream file again
	ifstream fin3("StockPrices.csv");
	if(fin3.fail())
	{
		cout << "Input file stream failed. " << endl;
		return 0;
	}
	getline(fin3,Dummy);//Skipping the first line of csv file
	string*theMonth = new string[counter];
	string*theYear = new string[counter];
	for(int i = 0; i < counter; i++)
	{
		getline(fin3, Month, '/');
		getline(fin3, Day, '/');
		getline(fin3, Year, ',');
		getline(fin3, Open, ',');
		getline(fin3, High, ',');
		getline(fin3, Low, ',');
		getline(fin3, Close, ',');
		getline(fin3, AdjClose, ',');
		getline(fin3, Volume, '\n');
		theMonth[i] = Month;
		theYear[i] = Year;
	}
	fin2.close();//Close input stream file again

	//Calculate Average Price Per Year
	cout << "THE AVERAGE PRICE PER YEAR: " << endl;

	int i = 0;
	double sum = 0;
	double count = 0;
	double Average;
	while(i < counter-1)
	{
		if(theYear[i] == theYear[i + 1])
		{
			sum = sum + Third[i];
			count = count + 1;
		}
		else
		{
			Average = sum/count;
			cout << "Average Price Per Year Of " << theYear[i] <<" is: " << Average <<endl;
			sum = 0;
			count = 0;
		}
		i = i + 1;
	}
	cout << "Average Price Per Year Of " << theYear[i] <<" is: " << sum/count << endl << endl; 

	//Calculate Average Price Per Month
	cout << "THE AVERAGE PRICE PER MONTH IN FILE: " << endl;
	double sum1 = 0;
	double count1 = 0;
	for (int i = 0; i < counter; i++)
	{
		if (theMonth[i] == "1")
		{
			count1 = count1 + 1;
			sum1 = sum1 + Third[i];
		}
		else 
		{
			count1 = count1;
			sum1 = sum1;
		}
	}
	cout << "The Average Price Of January: " << sum1/count1 << endl;
	sum1 = 0;
	count1 = 0;

	for (int i = 0; i < counter; i++)
	{
		if (theMonth[i] == "2")
		{
			count1 = count1 + 1;
			sum1 = sum1 + Third[i];
		}
		else 
		{
			count1 = count1;
			sum1 = sum1;
		}
	}
	cout << "The Average Price Of February: " << sum1/count1 << endl;
	sum1 = 0;
	count1 = 0;

	for (int i = 0; i < counter; i++)
	{
		if (theMonth[i] == "3")
		{
			count1 = count1 + 1;
			sum1 = sum1 + Third[i];
		}
		else 
		{
			count1 = count1;
			sum1 = sum1;
		}
	}
	cout << "The Average Price Of March: " << sum1/count1 << endl;
	sum1 = 0;
	count1 = 0;

	for (int i = 0; i < counter; i++)
	{
		if (theMonth[i] == "4")
		{
			count1 = count1 + 1;
			sum1 = sum1 + Third[i];
		}
		else 
		{
			count1 = count1;
			sum1 = sum1;
		}
	}
	cout << "The Average Price Of April: " << sum1/count1 << endl;
	sum1 = 0;
	count1 = 0;

	for (int i = 0; i < counter; i++)
	{
		if (theMonth[i] == "5")
		{
			count1 = count1 + 1;
			sum1 = sum1 + Third[i];
		}
		else 
		{
			count1 = count1;
			sum1 = sum1;
		}
	}
	cout << "The Average Price Of May: " << sum1/count1 << endl;
	sum1 = 0;
	count1 = 0;

	for (int i = 0; i < counter; i++)
	{
		if (theMonth[i] == "6")
		{
			count1 = count1 + 1;
			sum1 = sum1 + Third[i];
		}
		else 
		{
			count1 = count1;
			sum1 = sum1;
		}
	}
	cout << "The Average Price Of June: " << sum1/count1 << endl;
	sum1 = 0;
	count1 = 0;
	for (int i = 0; i < counter; i++)
	{
		if (theMonth[i] == "7")
		{
			count1 = count1 + 1;
			sum1 = sum1 + Third[i];
		}
		else 
		{
			count1 = count1;
			sum1 = sum1;
		}
	}
	cout << "The Average Price Of July : " << sum1/count1 << endl;
	sum1 = 0;
	count1 = 0;

	for (int i = 0; i < counter; i++)
	{
		if (theMonth[i] == "8")
		{
			count1 = count1 + 1;
			sum1 = sum1 + Third[i];
		}
		else 
		{
			count1 = count1;
			sum1 = sum1;
		}
	}
	cout << "The Average Price Of August: " << sum1/count1 << endl;
	sum1 = 0;
	count1 = 0;

	for (int i = 0; i < counter; i++)
	{
		if (theMonth[i] == "9")
		{
			count1 = count1 + 1;
			sum1 = sum1 + Third[i];
		}
		else 
		{
			count1 = count1;
			sum1 = sum1;
		}
	}
	cout << "The Average Price Of September: " << sum1/count1 << endl;
	sum1 = 0;
	count1 = 0;
	for (int i = 0; i < counter; i++)
	{
		if (theMonth[i] == "10")
		{
			count1 = count1 + 1;
			sum1 = sum1 + Third[i];
		}
		else 
		{
			count1 = count1;
			sum1 = sum1;
		}
	}
	cout << "The Average Price Of October: " << sum1/count1 << endl;
	sum1 = 0;
	count1 = 0;
	for (int i = 0; i < counter; i++)
	{
		if (theMonth[i] == "11")
		{
			count1 = count1 + 1;
			sum1 = sum1 + Third[i];
		}
		else 
		{
			count1 = count1;
			sum1 = sum1;
		}
	}
	cout << "The Average Price Of November: " << sum1/count1 << endl;
	sum1 = 0;
	count1 = 0;
	for (int i = 0; i < counter; i++)
	{
		if (theMonth[i] == "12")
		{
			count1 = count1 + 1;
			sum1 = sum1 + Third[i];
		}
		else 
		{
			count1 = count1;
			sum1 = sum1;
		}
	}
	cout << "The Average Price Of December: " << sum1/count1 << endl <<endl;
	sum1 = 0;
	count1 = 0;

	//Determine Highest and Lowest Prices Per Year
	cout << "THE HIGHEST AND LOWEST PRICES PER YEAR: " << endl;
	int k = 0;
	double highest = Third[0];
	double smallest = Third[0];
	 
	while(k < counter - 1) //This loop is used to determine the Highest Price
	{
		if(theYear[k] == theYear[k + 1])
		{
			if(highest < Third[k + 1])
			{
				highest = Third[k + 1];
			}
			else 
			{
				highest = highest;
			}
		}
		else if(theYear[k] != theYear[k + 1])
		{
			cout << "The Highest Price Per Year Of " << theYear[k] <<" is: " << highest <<"  " << endl;
			highest = Third[k + 1];
		}
		k = k + 1;
	}
	cout << "The Highest Price Per Year Of " << theYear[k] <<" is: " << highest <<"  " << endl;
	cout << endl;
	k = 0;
	while(k < counter - 1) //This loop is used to determine the Lowest Price
	{
		if(theYear[k] == theYear[k + 1])
		{
			if(smallest > Third[k + 1])
			{
				smallest = Third[k + 1];
			}
			else 
			{
				smallest = smallest;
			}
		}
		else if(theYear[k] != theYear[k + 1])
		{
			cout << "The Lowest Price Per Year Of " << theYear[k] <<" is: " << smallest <<"  "<< endl;
			smallest = Third[k + 1];
		}
		k = k + 1;
	}
	cout << "The Lowest Price Per Year Of " << theYear[k] <<" is: " << smallest <<"  "<< endl;
	fin3.close();//Close open stream file again

	// Generate a text file that lists the dates and prices, sorted from the lowest price to the highest
	for (int h = 0; h < counter; h++)
	{
		for (int l = 0; l < counter - 1; l++)
		{
			if (Third[l] >= Third[l + 1])
			{
				double temp = Third[l+1];
				Third[l+1] = Third[l];
				Third[l] = temp;

				string temp1 = First[l+1];
				First[l+1] = First[l];
				First[l]= temp1;
			}
		}
	}
	//Create output file stream
	ofstream fout("LowestToHighest.txt");
	if(fout.fail())
	{
		cout << "Output file stream failed. " << endl;
		return 0;
	}

	for (int k = 0; k < counter; k++)
	{
		fout << First[k] << "   " << Third[k] <<endl;
	}
	fout.close(); //Close output file stream
	//Create output file stream again
	ofstream fout1("HighestToLowest.txt");
	if(fout1.fail())
	{
		cout << "Output file stream failed. " << endl;
		return 0;
	}
	for (int k = counter - 1; k >= 0; k--)
	{
		fout1 << First[k] << "   " << Third[k] <<endl;
	} 

	fout.close();//Close output file stream again
	cout << endl;
	system("pause");
	return 0;
}

