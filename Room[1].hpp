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
#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;


class Room {

protected:
	Room * forward;
	Room * backward;
	Room * left;
	Room * right;
	int	numberOfVisits;
	string cat;
	string item1;
	string item2;
	string item3;
	string name;
	bool hasCat;

public:
	void setDirections(Room*, Room*, Room*, Room*);

	virtual string getInfo() = 0;
	string getName();
	Room * getForward();
	Room * getBackward();
	Room * getLeft();
	Room * getRight();

	int getNumberOfVisits();
	char validateInput();

	virtual string firstVisitItem() = 0;
	virtual string secondVisitItem() = 0;
	virtual string laterVisits() = 0;


};

#endif