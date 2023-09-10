#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

template <class T>
void quickSortRandom(T a[], int first, int last);
template <class T>
void quickSortMedian(T a[], int first, int last);
template <class T>
int pivotRandom(T a[], int first, int last);
template <class T>
int pivotMedian(T a[], int first, int last);
template <class T>
void print(T a[], const int& N);
template <class T>
void swap(T& a, T& b);

//==================================================The median as the pivot=================================================================================
template <class T>
void quickSortMedian(T a[], int first, int last)
{
	int pivotElement;
	if(first < last)
	{
		pivotElement = pivotMedian(a,first,last);
		quickSortMedian(a, first, pivotElement - 1);
		quickSortMedian(a, pivotElement + 1, last);
	}
}
//I used Bubble sort to sort and find Median, though I think this is not logic
template <class T>
int pivotMedian(T a[], int first, int last)
{
	T* b = new T[last+1];
	for (int i = 0; i <= last; i++)
	{
		b[i] = a[i];
	}
	int size = last + 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-1-i; j++)
		{
			if(b[j] > b[j+1])
			{
				swap(b[j], b[j+1]);
			}
		}
	}
	int postionMedian = int (size/2);
	T Median = b[postionMedian];

	for(int i = 0; i <= last; i++)
	{
		if (a[i] == Median)
		{
			swap(a[i], a[first]);
		}
		break;
	}
	T pivotElement = a[first];
	int p = first;
	for (int  i = first+1; i <= last; i++)
	{
		if(a[i] <= pivotElement)
		{
			p++;
			swap(a[i], a[p]);
		}
	}
	swap(a[p], a[first]);
	return p;
}
//=================================================================================================================================================

//=================================================Pivot randomly==================================================================================
template <class T>
void quickSortRandom(T a[], int first, int last)
{
	int pivotElement;
	if(first < last)
	{
		pivotElement = pivotRandom(a,first,last);
		quickSortRandom(a, first, pivotElement - 1);
		quickSortRandom(a, pivotElement + 1, last);
	}
}
template <class T>
int pivotRandom(T a[], int first, int last)
{
	srand((unsigned)time(0));
	int random = first + (rand() % (last + 1 - first));
	//random = 2;
	swap(a[first], a[random]);
	T pivotElement = a[first];
	int p = first;
	for (int  i = first+1; i <= last; i++)
	{
		if(a[i] <= pivotElement)
		{
			p++;
			swap(a[i], a[p]);
		}
	}
	swap(a[p], a[first]);
	return p;
}
//================================================================================================================================
//This function s to swap two element
template <class T>
void swap(T& a, T& b)
{
	T temp = a; 
	a = b;
	b = temp;
}
//This function is to print all elements in array
template <class T>
void print(T a[], const int& N)
{
    for(int i = 0 ; i < N ; i++)
	{
        cout << "array[" << i << "] = " << a[i] << endl;
	}
}

int main()
{
	int test[] = {23,45,11,5,88,5,45,10,99};
	int N = sizeof(test)/sizeof(int);
	cout << "Size of test array :"  << N << endl;
    cout << "Before sorting : " << endl;
    print(test, N);
    quickSortMedian(test, 0, N-1);
    cout << endl << endl << "After sorting (median pivot) : " << endl;
    print(test, N);

	cout << endl << endl;

	int temp[] = {9,1,2,6,3,10,18,4};
	N = sizeof(temp)/sizeof(int);
	cout << "Size of temp array :"  << N << endl;
    cout << "Before sorting : " << endl;
    print(temp, N);
    quickSortRandom(temp, 0, N-1);
    cout << endl << endl << "After sorting (random pivot) : " << endl;
    print(temp, N);

	cout << endl << endl;

	char test1[] = {'f','q','e','r','a'};
	N = sizeof(test1)/sizeof(char);
	cout << "Size of test1 array :"  << N << endl;
    cout << "Before sorting : " << endl;
    print(test1, N);
    quickSortMedian(test1, 0, N-1);
    cout << endl << endl << "After sorting (median pivot) : " << endl;
    print(test1, N);

	cout << endl << endl;

	char test2[] = {'f','q','e','r','b'};
	N = sizeof(test2)/sizeof(char);
	cout << "Size of test1 array :"  << N << endl;
    cout << "Before sorting : " << endl;
    print(test2, N);
    quickSortRandom(test2, 0, N-1);
    cout << endl << endl << "After sorting (random pivot) : " << endl;
    print(test2, N);


	system("pause");
	return 0;
}