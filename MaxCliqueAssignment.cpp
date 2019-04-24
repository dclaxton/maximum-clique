#include <iostream>
#include <vector>
#include <algorithm>
#include "matrix.h"
#include "edge.hpp"
#include "Vertex.hpp"

std::vector<Vertex> maxClique(int vertices, int edge, std::vector<Edge> edges, matrix &graph, std::vector<Vertex> &clique)
{
	for (int i = 0; i < edges.size(); i++)
	{
		graph.set(edges[i].getStart(), edges[i].getDest(), 1);
	}
	//get all vertexes
	std::vector<Vertex> vertexes;
	bool isGood = false;
	for (int i = 0; i < vertices; i++)
	{
		Vertex v(i);
		for (int j = 0; j < vertices; j++)
		{
			if (graph.get(i, j) == 1)
			{
				v.adjacency.push_back(j);
			}
		}
		vertexes.push_back(v);
	}
	for (int i = 0; i < vertexes.size(); i++)
	{
		std::vector<Vertex> maxPossible;
		maxPossible.push_back(vertexes[i]);
		for (int j = 0; j < vertexes.size(); j++)
		{
			for (int k = 0; k < maxPossible.size(); k++)
			{
				//basically this is if the adjacency matrix contains any of the vertex start points.
				if (std::find(maxPossible[k].adjacency.begin(), maxPossible[k].adjacency.end(), vertexes[j].start) != maxPossible[k].adjacency.end())
				{
					isGood = true;
				}
				else
				{
					isGood = false;
					break;
				}
				if (maxPossible[k].start == j)
				{
					isGood = false;
				}
			}
			if (isGood)
			{
				maxPossible.push_back(vertexes[j]);
			}
		}
		if (maxPossible.size() >= clique.size())
		{
			clique = maxPossible;
		}
	}
	return clique;
}

void printClique(std::vector<Vertex> clique, int vertices, matrix graph)
{
	for (int i = 0; i < vertices; i++)
	{
		std::cout << "\n";
		for (int j = 0; j < vertices; j++)
		{
			std::cout << graph.get(i, j) << " ";
		}
	}
	std::cout << "\n";
	std::cout << "Vertices in Maximum Clique:\n";
	for (int i = 0; i < clique.size(); i++)
	{
		std::cout << clique[i].start << " ";
	}

}



int main() 
{
	std::vector<Vertex> clique;
	std::vector<Edge> edges;
	int vertices, edge, start, destination, weight;
	std::cin >> vertices;
	std::cin >> edge;
	matrix graph(vertices + 1, vertices + 1);
	//get edges
	for (int i = 0; i < edge; i++)
	{
		std::cin >> start >> destination >> weight;

		edges.push_back(Edge(start, destination, weight));
	}

	maxClique(vertices, edge, edges, graph, clique);
	printClique(clique, vertices, graph);

    std::cin.ignore();
    std::cin.get();
    return 0;
}