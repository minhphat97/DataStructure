//Application File for Sequence
#include <iostream>
#include "ClassExercise1.h"
using namespace std;
int main()
{
    Sequence sq;
    sq.insert(2.1);
	sq.insert(7);
	sq.insert(8);
    cout << "size = " << sq.size() << endl; 
    cout << "standard deviation = " << sq.stdDeviation() << endl; 
    sq.clear();
	system("pause");
	return 0;
}