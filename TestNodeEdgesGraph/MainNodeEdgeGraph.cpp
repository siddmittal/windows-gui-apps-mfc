#include <iostream>
#include <map>
#include "Node.h"
#include "Edge.h"

using namespace std;


Node::Node(int id)
{
	this->nodeID = id;
}

Edge::Edge(Node* fromNode, Node* toNode) :from(fromNode),to(toNode)
{

}

int main()
{
	vector<int> nodeIds{ 3, 4, 6, 5, 1, 2, 7 };
	vector<pair<int, int>> links{
		pair<int,int>(1,2),
		pair<int,int>(1,3),
		pair<int,int>(2,4),
		pair<int,int>(3,4),
		pair<int,int>(3,6),
		pair<int,int>(6,7),
		pair<int,int>(4,7)
	};

	//initialize Nodes and create MAP
	map<int, Node*> nodesMap;
	for (int i = 0; i < nodeIds.size(); i++)
	{
		Node* node = new Node(nodeIds[i]);
		nodesMap.insert(pair<int, Node*>(nodeIds[i], node));
	}

	//create and connect edges
	for (int i = 0; i < links.size(); i++)
	{
		Edge* edge = new Edge(nodesMap[ links[i].first], nodesMap[links[i].second]);
		nodesMap[links[i].first]->AddEdge(edge);
	}

	//check number of outward edges for each node
	map<int, Node*>::iterator itr;
	for (itr = nodesMap.begin(); itr != nodesMap.end(); itr++)
	{
		cout << "Node: "<< itr->first<<"->" << itr->second << ", Number of Outward Edges:" << itr->second->GetEdges().size()<<endl;
	}

	cout << "Program ended successfully!";
}