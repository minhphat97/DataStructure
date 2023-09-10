#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;

int main()
{
	Graph test;
	test.addVertex("A");
	test.addEdge("A", "G", 5);
	test.addVertex("B");
	test.addVertex("C");
	test.addEdge("A", "H", 1);
	test.addEdge("B", "F", 8);
	test.removeEdge("A", "H");
	test.removeVertex("A");
	test.display();
	system("pause");
	return 0;
}