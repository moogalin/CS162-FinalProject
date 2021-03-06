/******************************************************************************************
** Program Filename: Final Project
** Author: Megan Aldridge
** Date: March 15, 2016
** Description: This program allows to play a text base game. The user visits different rooms, 
**		collects items, and wins the game if they arrive in the correct room with the 
**		correct items. 
** Input: User will follow menu prompts that strictly involve character input. 
** Output: The output displays information regarding the room that the character is in, the
**		the items that the character found in that room, and other information about the
**		character and outcome of the game. 
******************************************************************************************/
#ifndef BACKYARD_HPP
#define BACKYARD_HPP

#include "Room.hpp"

class BackYard : public Room {

private:

public:
	BackYard();

	string getInfo();
	string firstVisitItem();
	string secondVisitItem();
	string laterVisits();


};


#endif
