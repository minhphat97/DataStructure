#include <iostream>
#include <string>
using namespace std;
//This function will use recursive method and convert string to integer
int atoiRecursive(char* String, int n)
{
	if(n == 1)
		return int(*String) - 48;
	else
	{
		int temp = int(String[n-1]) - 48;
		int result = 10*atoiRecursive(String, n-1) + temp;
		return result;
	}
}
int main()
{
	char str[] = "112";
	int n = strlen(str);
	cout << atoiRecursive(str, n) << endl;
	system("pause");
	return 0;
}