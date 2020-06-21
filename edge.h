/***************************************************************************//**
 * @file edge.h
 *
 * @brief
 *      Contains a class for Edge
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

#ifndef EDGE_H
#define EDGE_H
#include <ostream>

/*!
* @brief contains data for an edge in a weighted graph such as the vertices and 
* 	 weight
*/

class Edge
{
   int v;
   int w;
   double weight;
public:
   Edge(int, int, double);

   int either() const;
   int other(int) const;
   bool operator<(const Edge &) const;
   friend std::ostream &operator <<(std::ostream &, const Edge&);
   double Weight() const;
};

#endif
