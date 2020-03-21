#pragma once

#include<vector>

class Edge;

class Node
{
private:
	int nodeID;
	std::vector<Edge*> outwardsEdges;

public:
	Node(int id);
	std::vector<Edge*> GetEdges() { return outwardsEdges; }
	void AddEdge(Edge* edge) { outwardsEdges.push_back(edge); }
};

