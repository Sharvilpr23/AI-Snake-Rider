/***************************************************************************//**
 * @file weightedGraph.h
 *
 * @brief header file weighted graph class
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

#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include <iostream>
#include <map>
#include <set>
#include "edge.h"
#include "playfield.h"

using namespace std;

//typedefing map<int, multiset<int>> as map_t
typedef map<int, multiset<Edge>> map_t;

/********************************************************************//**
 * @class WeightedGraph
 **********************************************************************/
class WeightedGraph
{
   int numVertices,numEdges;
   map_t edges;
   set<int> vertices;
   int  weight[PLAYFIELD_WIDTH][PLAYFIELD_HEIGHT] = 
   { 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,64, 64, 64, 64, 64, 64, 64,
64, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49 ,49, 49, 64,
64, 49, 49, 36, 36, 36, 36, 36, 36, 36, 36 ,36, 36, 36, 49, 49, 64,
64, 49, 49, 36, 25, 25, 25, 25, 25, 25, 25, 25, 25, 36, 49, 49, 64,
64, 49, 49, 36, 25, 16, 16, 16 ,16, 16, 16, 16, 25, 36, 49, 49, 64,
64, 49, 49, 36, 25, 16, 4, 4, 4, 4, 4, 16, 25, 36 ,49, 49, 64,
64, 49, 49, 36, 25, 16, 4, 2, 2, 2, 4 ,16, 25, 36, 49, 49, 64,
64, 49, 49, 36, 25, 16, 4, 2, 1, 2, 4, 16, 25, 36, 49, 49, 64,
64, 49, 49, 36, 25, 16, 4, 2 ,2, 2, 4, 16, 25, 36, 49, 49, 64,
64, 49, 49, 36, 25, 16, 4, 4, 4, 4, 4, 16, 25, 36, 49, 49, 64,
64, 49, 49, 36, 25, 16, 16, 16, 16, 16, 16, 16, 25, 36, 49, 49, 64,
64, 49, 49, 36, 25, 25, 25, 25, 25, 25, 25, 25, 25, 36, 49, 49, 64,
64, 49, 49, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 49, 49, 64,
64, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49 ,49, 49, 64,
64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64
};

public:
   WeightedGraph();
   WeightedGraph(const int *, int, int);

   void addEdge(Edge);
   multiset<Edge> adj(int);
   multiset<Edge> Edges();
   set<int> Vertices() const;
   int V() const;
   int E() const;
};
#endif
