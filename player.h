/***************************************************************************//**
 * @file player.h
 *
 * @brief header file for snake player
 *
 * @author Sharvil Pai Raiker
           Paul Hinker
 *
 * @par Class
 *    CSC315 Data Structures
 * @date Spring 2020
 *
 * Modifications:
 *    * Added doxygen style comments: SPR 05/01/2020
 ******************************************************************************/

#ifndef __PLAYER_H
#define __PLAYER_H
#include <list>
#include <queue>
#include <vector>
#include "playfield.h"

/*!
* @brief contains data necessary to describe the snake player
*/

class Player
{
public:
   Player ();
   ValidMove makeMove(const Playfield *);
   ~Player();
private:
	vector<vector<int>> weights;
};


#endif
