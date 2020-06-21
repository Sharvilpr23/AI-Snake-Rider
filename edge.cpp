/***************************************************************************//**
 * @file edge.cpp
 *
 * @brief immplementation for edge class
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

#include "edge.h"

/*************************************************************************//**
 * @brief constructor for Edge class
 *
 * @par Description
 *   A constructor that creates an instance of class Edge 
 *
 * @param[in] s - Vertex 1
 * @param[in] e - Vertex 2
 * @param[in] w - Weight of the edge
 *
 * @returns Edge - an instance of class Edge 
 ****************************************************************************/

Edge::Edge(int s, int e, double w) : v(s), w(e), weight(w){}

/*************************************************************************//**
 * @brief gets either of the vertices of the edge
 *
 * @par Description
 *   The function fetches either of the vertices of the edge. 
 *
 * @param[in] none
 *
 * @returns one of the vertices of the edge
 ****************************************************************************/

int Edge::either() const
{
  return v;
}

/*************************************************************************//**
 * @brief gets the other vertex of the edge
 *
 * @par Description
 *   The function returns the other vertex of the edge 
 *
 * @param[in] vertex - one of the vertices of the edge
 *
 * @returns the other vertex of the edge
 ****************************************************************************/

int Edge::other(int vertex) const
{
  if(vertex == v)
    return w;
  else
    return v;
}

/*************************************************************************//**
 * @brief compares the edges based on their weights
 *
 * @par Description
 *   The function compares the weight of the first edge with the edge passed 
 *   as a paramater.
 *
 * @param[in, out] rhs - the second edge to be compared with
 *
 * @returns true - if the weight of the first edge is greater than the other
 * 	    false - if the weight of the other edge is greater or equal to
 * 	    	    the weight of the first one
 ****************************************************************************/

bool Edge::operator<(const Edge& rhs) const
{
    return weight > rhs.weight;
}

/*************************************************************************//**
 * @brief Reads in an edge
 *
 * @par Description
 *   The function reads in an edge using an ostream object. The function gets
 *   the vertices of the edge and return an associated ostream object
 *
 * @param[in,out] os - an ostream object 
 * @param[in,out] e - an Edge
 *
 * @returns an ostream object taking in an edge
 ****************************************************************************/

std::ostream &operator <<(std::ostream &os, const Edge &e)
{
  int v = e.either();
  int w = e.other(v);

  os << v << "-" << w << " " <<e.weight;

  return os;
}

/*************************************************************************//**
 * @brief gets the weight of the edge
 *
 * @par Description
 *   The function retrieves the weight of the edge fromm the private section
 *
 * @param[in] none
 *
 * @returns weight - the weight of the edge
 ****************************************************************************/

double Edge::Weight() const
{
  return weight;
}
