/***************************************************************************//**
 * @file weightedGraph.cpp
 *
 * @brief implementation for weightegraph Class
 *
 * @author Sharvil Pai Raiker
 *
 * @par Class
 *    CSC315 Data Structures
 * @date Spring 2020
 *
 * Modifications:
 *    * Added doxygen style comments: SPR 05/01/2020
 ******************************************************************************/

#include "weightedGraph.h"

/*************************************************************************//**
 * @brief Default Constructor for class Weightedgraph
 *
 * @param[in] none
 *
 * @returns WeightedGraph - an instance of class WeightedGraph
 ****************************************************************************/
WeightedGraph::WeightedGraph() : numVertices(0), numEdges(0){}

/*************************************************************************//**
 * @brief Constructor for class WeightedGraph that converts an integer array 
 * 	  to a weighted graph.
 *
 * @par Description
 *	Converts a 1d integer array to a weighted graph
 *
 * @param[in] grid - the playfield
 * @param[in] width - the width of the playfield
 * @param[in] height - the height of the playfield
 *
 * @returns WeightedGraph - an instance of class WeightedGraph
 ****************************************************************************/
WeightedGraph::WeightedGraph(const int *grid, int width, int height)
{
	numEdges = 0;

	for(int i = 0; i < (width * height); i++)
	{
		int row = i / width;
		int col = i % width;
		//
		if(grid[i] != 1)
		{
			
			row -= 1;
			//Check up
			if(row >= 0 && col >= 0)
			{
				int up = row * width + col;
				if(grid[up]!=1)
					addEdge(Edge(i, up, weight[row][col]));
			}

			row += 2;
			//Check down
			if(row < height && col < width)
			{
				int down = row * width + col;
				if(grid[down]!=1)
					addEdge(Edge(i, down, weight[row][col]));
			}

			row -= 1;
			col -= 1;
			//Check left
			if(row >= 0 && col >= 0)
			{
				int left = row * width + col;
				if(grid[left]!=1)
					addEdge(Edge(i, left, weight[row][col]));
			}

			col += 2;
			//Check right
			if(row < height && col < width)
			{
				int right = row * width + col;
				if(grid[right]!=1)
					addEdge(Edge(i, right, weight[row][col]));
			}
		}
	}
}

/*************************************************************************//**
 * @brief adds an edge to the weighted graph 
 *
 * @par Description
 *   The function gets the vertices of the edge and inserts into a map to 
 *   store them
 *
 * @param[in] e - an edge
 *
 * @returns none
 ****************************************************************************/

void WeightedGraph::addEdge(Edge e)
{
  int v = e.either();
  int w = e.other(v);
	//Store the edge
  edges[v].insert(e);
  edges[w].insert(e);
	//Store the vertices
  vertices.insert(v);
  vertices.insert(w);

  return;
}

/*************************************************************************//**
 * @brief get all the edges of the graph
 *
 * @par Description
 *   The function retrives all the edges of the graph
 *
 * @param[in] none
 *
 * @returns returnVal - a multiset of edges
 ****************************************************************************/
multiset<Edge> WeightedGraph::Edges()
{
  multiset<Edge> returnVal;

  for (auto &kv : edges)
    for (Edge e : edges[kv.first])
      returnVal.insert(e);

  return returnVal;
}

/*************************************************************************//**
 * @brief gets the vertices of the graph
 *
 * @par Description
 *   The function retrieves a set of vertices of the graph
 *
 * @param[in] none
 *
 * @returns vertices - a set of vertices
 ****************************************************************************/
set<int> WeightedGraph::Vertices() const
{
  return vertices;
}

/*************************************************************************//**
 * @brief get the adjacent edges of a vertex
 *
 * @par Description
 *   The function retrieves a set of adjacent edges to a vertex
 *
 * @param[in] v - the vertex
 *
 * @returns edges - a multiset of edges
 ****************************************************************************/
multiset<Edge> WeightedGraph::adj(int v)
{
  return edges[v];
}

/*************************************************************************//**
 * @brief get the number of vertices
 *
 * @par Description
 *   The function returns the number of vertices in a graph
 *
 * @param[in] none
 *
 * @returns numVertices - number of vertices
 ****************************************************************************/
int WeightedGraph::V() const
{
  return numVertices;
}

/*************************************************************************//**
 * @brief get the number of edges
 *
 * @par Description
 *   The function returns the number of edges in a graph
 *
 * @param[in] none
 *
 * @returns numEdges - number of edges
 ****************************************************************************/
int WeightedGraph::E() const
{
  return numEdges;
}
