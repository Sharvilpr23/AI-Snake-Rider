/***************************************************************************//**
 * @file dijkstra.cpp
 *
 * @brief functions for DijkstraSP implementation
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

#include "dijkstra.h"


/*************************************************************************//**
 * @brief Constructor for class DijkstraSP
 *
 * @param[in] G - a weighted graph
 * @param[in] s - the starting point of the graph
 *
 * @returns an instance of class DijkstraSP
 ****************************************************************************/
DijkstraSP::DijkstraSP(WeightedGraph *G, int s) : S(s)
{
	//gets the set of vertices 
  set<int> vertexList = G->Vertices();

  //set all distances to infinity
  for(int vertex : vertexList)
    dist[vertex] = std::numeric_limits<double>::max();

  //check for no negative weights
  for(Edge e : G->Edges())
  {
    if(e.Weight() < 0)
    {
      cout << "Negative Weight detected" << endl;
      return;
    }
  }

  dist[S] = 0.0;
  heap.push(make_pair(0, S));

  while (!heap.empty())
  {
    hPair v = heap.top();
    heap.pop();

    for (Edge e : G->adj(v.second))
      relax(v.second, e);
  }
}


/*************************************************************************//**
 * @brief relaxes the distance between two nodes
 *
 * @par Description
 *   The function relaxes the distance between two nodes by finding the 
 *   shortest distance between nodes
 *
 * @param[in] v - the vertex
 * @param[in] e - the edge between the starting node and the vertex
 *
 * @returns none
 ****************************************************************************/
void DijkstraSP::relax(int v, Edge e)
{
  int w = e.other(v);

  //relax if the distance is shorter
  if (dist[w] > dist[v] + e.Weight())
  {
	  //set the new distance
    dist[w] = dist[v] + e.Weight();
    //set the previous vertex to the vurrent
    prev[w] = v;
    //push the pair on the heap
    heap.push(make_pair(dist[w], w));
  }
}


/*************************************************************************//**
 * @brief checks if there is a path from the starting node to the vertex
 *
 * @par Description
 *   The function checks if the distance hasn't been changed which indicates 
 *   if there is a path between the nodes
 *
 * @param[in] v - the vertex
 *
 * @returns true - if there is a path
 * 	    false - if there is no path
 ****************************************************************************/
bool DijkstraSP::hasPathTo(int v)
{
  if(dist.count(v)!=0)
    return dist[v] != std::numeric_limits<double>::max();
  else
    return false;
}


/*************************************************************************//**
 * @brief the path between the two nodes
 *
 * @par Description
 *   The function stats of from the destination node and adds the previous
 *   vertices of each vertex to a stack till it reaches the start node
 *
 * @param[in] v - the destination vertex
 *
 * @returns path - the path from the starting node to the destination
 ****************************************************************************/
stack<int> DijkstraSP::pathTo(int v)
{
  stack<int> path;

  if (!hasPathTo(v)) return path;
    for (int x = v ; x != S ; x = prev[x])
      path.push(x);

  return path;
}


/*************************************************************************//**
 * @brief gets the distance of the vertex from the starting vertex
 *
 * @par Description
 *   The function gets the distance of the vertex from the starting vertex by
 *   simple map look up
 *
 * @param[in] v - the destination vertex
 *
 * @returns dist - the distance between the nodes
 ****************************************************************************/
double DijkstraSP::distance(int v) { return dist[v] ; }
