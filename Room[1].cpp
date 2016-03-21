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
#include "Room.hpp"

/******************************************************************************************
** Function: getter and setter Functions
** Description: These functions set and get private member variables
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
Room * Room::getForward() {
	return forward;
}

Room * Room::getBackward() {
	return backward;
}

Room * Room::getLeft() {
	return left;
}

Room * Room::getRight() {
	return right;
}

int Room::getNumberOfVisits() {

	return numberOfVisits;
}

string Room::getName() {

	return name;
}

void Room::setDirections(Room * f, Room * b, Room * l, Room * r) {

	forward = f;
	backward = b;
	left = l;
	right = r;

}



/******************************************************************************************
** Function: validateInput
** Description: This functions validates that a user selects either 1 or 2 when they are given
**		different choices of action in the game. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
char Room::validateInput() {
	char choice;
	
	cin >> choice;
	cin.ignore();

	while ((choice < '1') || (choice > '2')) {

		cout << "Please enter one character (the integer 1 or 2) only." << endl;
		cout << "Choice: " << endl;
		cin >> choice;
		cin.ignore();
	}

	return choice;
}


