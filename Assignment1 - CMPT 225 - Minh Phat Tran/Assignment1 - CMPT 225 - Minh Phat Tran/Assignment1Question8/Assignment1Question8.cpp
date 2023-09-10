#include <iostream>
#include <string>
#include <stack>
using namespace std;
//I used recursive to delete the middle element by popping all elements until middle element, then delete it and push back all elements again
void deleteMid(stack<char>&st, int n, int curr = 0)
{
	if(curr == n)
	{
		return;
	}
	if(st.empty() == true)
	{
		cout << "Stack is empty. " << endl;
		return;
	}
	int temp = st.top();
	st.pop();

	deleteMid(st, n, curr + 1);
	
	if(curr != (n/2))
	{
		st.push(temp);
	}
}
int main()
{
	stack<char>s;
	s.push('a');
	s.push('b');
	s.push('c');	
	int curr = 0;
	int size = s.size();
	deleteMid(s, size, curr);
	char temp;
	while (s.empty() != true) 
    { 
        temp = s.top(); 
        s.pop(); 
        cout << temp << endl; 
    } 
	system("pause");
	return 0;
}