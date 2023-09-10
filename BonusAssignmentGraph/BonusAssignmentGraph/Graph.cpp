#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;

Graph::Graph()
{
	position = 0;
	gSize = 10;
	graph = new NodePtr[gSize];
	for(int i = 0; i < gSize; i++)
	{
		graph[i] = nullptr;
	}

}
Graph::~Graph()
{
	delete[]graph;
}
void Graph::addVertex(string label)
{
	if(graph[position] == nullptr)
	{
		NodePtr temp = new Node;
		temp->weight = 0;
		temp->label = label;
		temp->link = nullptr;
		graph[position] = temp;
		position = position + 1;
	}
}
void Graph::removeVertex(string label)
{
	for(int i = 0; i < position; i++)
	{
		if(graph[i]->label == label)
		{
			while(graph[i] != nullptr)
			{
				NodePtr temp = graph[i];
				graph[i] = graph[i]->link;
				delete temp;
			}
		}
	}
	for(int i = 0; i < position; i++)
	{
		if(graph[i] != nullptr)
		{
			if(graph[i]->label == label)
			{
				NodePtr temp = graph[i];
				graph[i] = graph[i]->link;
				delete temp;
			}
			else
			{
				NodePtr after_me = graph[i];
				while(after_me->link != nullptr)
				{
					if(after_me->link->label == label)
						break;
					else
						after_me = after_me->link;
				}
				if(after_me->link != nullptr)
				{
					NodePtr temp = after_me->link;
					after_me->link = after_me->link->link;
					delete temp;
				}
			}
		}
	}
}
void Graph::addEdge(string label1, string label2, unsigned long weight)
{
	for(int i = 0; i < position; i++)
	{
		if(graph[i]->label == label1)
		{
			NodePtr after_me = graph[i];
			while(after_me->link != nullptr)
			{
				after_me = after_me->link;
			}
			NodePtr temp = new Node;
			temp->label = label2;
			temp->weight = weight;
			temp->link = nullptr;
			after_me->link = temp;
		}
	}
}
void Graph::removeEdge(string label1, string label2)
{
	for(int i = 0; i < position; i++)
	{
		if(graph[i]->label == label1)
		{
			NodePtr after_me = graph[i];

			while(after_me->link != nullptr)
			{
				if(after_me->link->label == label2)
					break;
				else
					after_me = after_me->link;
			}
			if(after_me->link != nullptr)
			{
				NodePtr temp = after_me->link;
				after_me->link = after_me->link->link;
				delete temp;
			}
		}
	}
}

void Graph::display()
{
	for (int i = 0; i < position; i++)
	{
		if(graph[i] != nullptr)
		{
			NodePtr temp = graph[i];
			while (temp != nullptr)
			{
				cout << temp->label << " " << temp->weight << " ";
				temp = temp->link;
			}
		}
		cout << endl;
	}
}
