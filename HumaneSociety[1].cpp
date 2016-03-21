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
#include "HumaneSociety.hpp"

/******************************************************************************************
** Function: Constructor
** Description: This functions sets preliminary values when the object is created.
** Parameters: N/A
** Pre-Conditions: This room object must first be created.
** Post-Conditons: N/A
******************************************************************************************/
HumaneSociety::HumaneSociety() {
	forward = NULL;
	backward = NULL;
	left = NULL;
	right = NULL;
	numberOfVisits = 0;
	cat = "";
	item1 = "";
	item2 = "";
	name = "Humane Society";
}

string HumaneSociety::getInfo() {
	string info;

	info = "Somehow, you must have crossed through a secret tunnel. \n";
	info += "Looking around, you realize that somehow, strangely, \n";
	info += " you've escaped the Cat Lady house. But, this room appears\n";
	info += " to be even crazier. You notice a front desk and a series of hallways.\n";
	info += " At the front desk you see a large -- and oddly fluorescent -- sign:\n\n";
	info += " Welcome to the Humane Society!\n\n";
	info += " Well, this is odd. You decide to approach the front desk person.\n";
	info += " Hello, she says, and welcome!";
	info += " If you have a key, I'd like to invite you onto the adoption floor\n";

	return info;
}

string HumaneSociety::firstVisitItem() {

	return cat;
}

string HumaneSociety::secondVisitItem() {

	return item1;
}

string HumaneSociety::laterVisits() {

	return item2;
}

