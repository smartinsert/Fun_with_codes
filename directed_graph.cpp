/*
 * directed_graph.cpp
 * Given a directed graph, write an algo to determine a route between two nodes.
 *  Created on: Apr 21, 2015
 *      Author: Athakur
 */

#include <iostream>
#include <list>

using namespace std;

class Graph
{
	int V; // Number of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists

public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	bool isReachable(int src, int dst); // return true if there is a path from src to dst
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int> [V];
}


void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v's list
}

// BFS search to find dst from src
bool Graph::isReachable(int src, int dst)
{
	// Base case
	if (src == dst)
		return true;

	// Mark all the vertices as not visited
	bool *visited = new bool[V];

	for (int i = 0; i<V; ++i)
		visited[i] = false;

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[src] = true;
	queue.push_back(src);

	// it will be used to get all adjacent vertices of a vertex
	list<int>::iterator i;

	while(!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		src = queue.front();
		queue.pop_front();

		// Get all adjacent vertices of the dequeued vertex src
		// If an adjacent has not been visited, then mark it visited and enqueue it
		for (i = adj[src].begin(); i != adj[src].end(); ++i)
		{
			// If this adjacent node is the destination node, then return true
			if (*i == dst)
				return true;

			// Else continue the BFS
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}

	}
		return false;
}


int main()
{
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);

	int u=1, v=3;
	if (g.isReachable(u,v))
		cout << "\n There is a path from " << u << " to " << v;
	else
		cout << "\n There is no path from " << u << " to " << v;

	u=3, v=1;
	if (g.isReachable(u,v))
		cout << "\n There is a path from " << u << " to " << v;
	else
		cout << "\n There is no path from " << u << " to " << v;
	u=0, v=3;
	if (g.isReachable(u,v))
		cout << "\n There is a path from " << u << " to " << v;
	else
		cout << "\n There is no path from " << u << " to " << v;

	u=3, v=0;
	if (g.isReachable(u,v))
		cout << "\n There is a path from " << u << " to " << v;
	else
		cout << "\n There is no path from " << u << " to " << v;
	return 0;
}
