/***************************************************************************//**
 * @file dijkstra.h
 *
 * @brief header file for dijkstra class
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

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <map>
#include <limits>
#include <stack>
#include <queue>
#include "weightedGraph.h"

//typedefing a pair of int and int to hPair
typedef pair<int, int> hPair;

/*!
* @brief contains data for performing dijkstra's algorithm on a graph
*/
class DijkstraSP
{
   map<int, int> prev;
   map<int, double> dist;
   priority_queue<hPair, std::vector<hPair>, greater<hPair>> heap;
   int S;
public:
   DijkstraSP(WeightedGraph *, int);

   void relax(int, Edge);
   double distance(int);
   bool hasPathTo(int);
   stack<int> pathTo(int);
};

#endif
