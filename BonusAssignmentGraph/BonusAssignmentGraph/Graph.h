#include <iostream>
#include <string>

using namespace std;
struct Node
{
	unsigned long weight;
	string label;
	Node* link;
};
typedef Node* NodePtr;
class Graph
{
public:
	Graph();
	~Graph();
	void addVertex(string label);
	void removeVertex(string label);
	void addEdge(string label1, string label2, unsigned long weight);
	void removeEdge(string label1, string label2);
	//unsigned long shortestPath(string startLabel, string endLabel, std::vector<std::string> &path);
	void display();
private:
	int position;
	int gSize;
	NodePtr* graph;//This pointer means dynamic array !
};
