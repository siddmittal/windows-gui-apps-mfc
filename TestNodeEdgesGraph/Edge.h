#pragma once

class Node;
class Edge
{
private:
	Node* from;
	Node* to;
public:
	Edge(Node* fromNode, Node* toNode);
};