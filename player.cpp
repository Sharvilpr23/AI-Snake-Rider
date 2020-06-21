/***************************************************************************//**
 * @file player.cpp
 *
 * @brief functions for snake player implementations
 *
 * @author Sharvil Pai Raiker
           Paul Hinker
 * @par Class
 *    CSC315 Data Structures
 * @date Spring 2020
 *
 * Modifications:
 *    * Added doxygen style comments: SPR 05/01/2020
 ******************************************************************************/

#include "player.h"
#include "weightedGraph.h"
#include <stack>
#include <vector>
#include "dijkstra.h"
#include <iostream>

stack<int> findPathToFood(const int *, int, int);
std::pair<int, int>getNextMove(stack<int> &);
ValidMove makeRandomMove(const int *, std::pair<int, int>);

/***************************************************************************//**
 * @brief A constructor for class Player
 *
 * @param none
 *
 * @returns Player - instance of class Player
 ******************************************************************************/

Player::Player() {}

/*************************************************************************//**
 * @brief gets the location of the value in the grid
 *
 * @par Description
 *   The function traverses through all the elements of the array and returns 
 *   the coordinates of the value in the grid in the form of a pair. If the 
 *   position is not found, it returns a default (0, 0)
 *
 * @param[in] grid - stores the playfield
 * @param[in] value - value to be found in the grid
 *
 * @returns coordinates of the value in the grid
 ****************************************************************************/
std::pair<int, int> getLocation(const int *grid, int value)
{
	//For every row
   for (int y = 0 ; y < PLAYFIELD_HEIGHT ; y++)
	   //For every column
      for (int x = 0 ; x < PLAYFIELD_WIDTH ; x++)
		//if the value is found
         if (grid[y * PLAYFIELD_WIDTH + x] == value)
            return std::pair<int, int>(x, y);

   return std::pair<int, int>(0,0);
}

/*************************************************************************//**
 * @brief Returns the direction in which the snake should move inorder to get
 * 	  to the food
 *
 * @par Description
 *   The function has a static stack of type integer that stores the path. It
 *   gets the location of the head of the snake and food from the playfield. If
 *   the stack is empty, a new graph is generated and the shortest path to the 
 *   food is found using dijkstra's algorithm. If no paths are found, a flag is
 *   set. if no flag is set, the snake follow the path till the stack empties.
 *   If flag is set, a random move is made and then the function tries to find
 *   a path again.
 *
 * @param[in] pf - the playfield
 *
 * @returns the direction in which the snake should move
 ****************************************************************************/
ValidMove Player::makeMove(const Playfield *pf)
{
	bool flag = false; 
	static stack<int> path; //Stores the path the snake should follow

	const int *grid = pf->getGrid();

   	std::pair<int, int> head = getLocation(grid, HEAD_VALUE);
   	std::pair<int, int> food = getLocation(grid, FOOD_VALUE);

	int head_index = head.second * PLAYFIELD_WIDTH + head.first;
	int food_index = food.second * PLAYFIELD_WIDTH + food.first;
	
	//Find path to the food
	if(path.empty())
	{
		path = findPathToFood(grid, head_index, food_index);

		//Could not find a path as the path is blocked by its own body
		if(path.empty())
		{
			flag = true;
		}
	}
	

	if(flag)
	{
		flag = false;
		ValidMove move = makeRandomMove(grid, head);
		return move;
	}
	
	//Follow the path
	if(!path.empty())
	{
		std::pair<int, int> next_move = getNextMove(path);
		
		//If in the same column
		if(next_move.first == head.first)
		{
			//If the food is in the upper section
			if(next_move.second > head.second)
			{
				return UP;
			}
			else
			{
				return DOWN;
			}
		}
		//If in the same row
		else if(next_move.second == head.second)
		{
			//if the food is in the right section
			if(next_move.first > head.first)
			{
				return RIGHT;
			}
			else
			{
				return LEFT;
			}
		}
	}
	//No move found
   	return NONE;
}

/*************************************************************************//**
 * @brief Finds the path to the food
 *
 * @par Description
 *   The function creates a weighted graph from the grid and then uses
 *   Dijkstra's algorithm to find the shortest paths to all the nodes from the
 *   head index. If a path is found to the food, it is stored in a stack.
 *
 * @param[in] grid - stores the playfield
 * @param[in] head_index - position of the snake's head
 * @param[in] food-index - position of the food
 *
 * @returns the path to the food stored in a stack
 ****************************************************************************/
stack<int> findPathToFood(const int *grid, int head_index, int food_index)
{
	stack<int> path;
	
	//create a weighted graph
	WeightedGraph *G = new WeightedGraph(grid, PLAYFIELD_WIDTH, PLAYFIELD_HEIGHT);
	//find the shortest paths using dijkstra's algorithm
	DijkstraSP dijk(G, head_index);
	
	//If a path to the food is found 
	if(dijk.hasPathTo(food_index))
		path = dijk.pathTo(food_index); //retrieve the path

	return path;
}

/*************************************************************************//**
 * @brief Gets the index to which the snake head should move next
 *
 * @par Description
 *   The function takes the topmost element from the path stack and generates
 *   the coordinates of the index.
 *
 * @param[in, out] path - a stack storing the path to the food
 *
 * @returns the col and row of the next position
 ****************************************************************************/

std::pair<int, int> getNextMove(stack<int> &path)
{
	int next_move = path.top();
	path.pop();

	return std::pair<int, int>(next_move % PLAYFIELD_WIDTH, next_move / PLAYFIELD_WIDTH);
}

/*************************************************************************//**
 * @brief makes the snake move in a random direction
 *
 * @par Description
 *   The function starts off by checking if the snake can move down, up, left 
 *   or right respectively. It checks if the positiopn is within bounds and 
 *   whether it is an open space.
 *
 * @param[in] grid - stores the playfield
 * @param[in] head - the col and row of the head index
 *
 * @returns the direction in which the snake should move
 ****************************************************************************/

ValidMove makeRandomMove(const int *grid, std::pair<int, int> head)
{
	if(head.second - 1 >= 0 &&
		grid[(head.second - 1) * PLAYFIELD_WIDTH + head.first] == 0)
	{
		return DOWN;
	}

	if(head.second + 1 < PLAYFIELD_HEIGHT &&
		grid[(head.second + 1) * PLAYFIELD_WIDTH + head.first] == 0)
	{
		return UP;
	}

	if(head.first - 1 >= 0 &&
		grid[head.second * PLAYFIELD_WIDTH + (head.first - 1)] == 0)
	{
		return LEFT;
	}

	if(head.first + 1 < PLAYFIELD_WIDTH &&
		grid[head.second * PLAYFIELD_WIDTH + (head.first + 1)] == 0)
	{
		return RIGHT;
	}

	return NONE;
}

/*************************************************************************//**
 * @brief Destructor
 *
 * @par Description
 *   The function destroys the instance of class Player
 *
 * @param[in] none
 *
 * @returns none
 ****************************************************************************/

Player::~Player()
{}
