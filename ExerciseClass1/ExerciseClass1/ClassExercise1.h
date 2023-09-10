//Interface File for Sequence
#include <iostream>
using namespace std;
struct Node
{
	double data;
	Node* link;
};
typedef Node* NodePtr;
// This class is to represent whole the Sequence
class Sequence
{
private:
	NodePtr head;
public:
	Sequence();
	NodePtr getHead();
	void setHead(NodePtr head);
	void insert(double newData);
	void clear();
	int size();
	double stdDeviation();
	void printSequence();
};