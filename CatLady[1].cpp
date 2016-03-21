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
#include "CatLady.hpp"


/******************************************************************************************
** Function: Default Constructor
** Description: This functions sets preliminary values when the object is created.
** Parameters: N/A
** Pre-Conditions: This room object must first be created.
** Post-Conditons: N/A
******************************************************************************************/
CatLady::CatLady() {
	location = NULL;
	sizeOfHeart = 20;
	heartless = false;
	name = "";
}



/******************************************************************************************
** Function: Constructor
** Description: This functions sets preliminary values when the object is created.
** Parameters: N/A
** Pre-Conditions: This rom object must first be created with a string name passed to it. 
** Post-Conditons: N/A
******************************************************************************************/
CatLady::CatLady(string n) {
	location = NULL;
	sizeOfHeart = 20;
	heartless = false;
	name = n;
}



/******************************************************************************************
** Function: setter/getter Functions
** Description: These functions set and get the value of private member variables. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
void CatLady::setLocation(Room *loc) {
	location = loc;

}

string CatLady::getName() {

	return name;
}

Room* CatLady::getLocation() {
	return location;
}

int CatLady::getSizeOfHeart() {
	return sizeOfHeart;
}

int CatLady::getSizeFannyPack() {

	return fannyPack.size();
}



/******************************************************************************************
** Function: isHeartless
** Description: This functions acts as a getter function and returns the current bool value of 
**		isHeartless.
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
bool CatLady::isHeartless() {

	return heartless;
}



/******************************************************************************************
** Function: decSizeOfHeart
** Description: This functions decrements the size of the private int variable sizeOfHeart
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
void CatLady::decSizeOfHeart() {
	sizeOfHeart--;

	if (sizeOfHeart == 0) {
		heartless = true;
	}
}



/******************************************************************************************
** Function: addItem
** Description: This functions adds a string to the Fanny Pack vector of string objects. 
** Parameters: One string
** Pre-Conditions: The string will only be added if the Fanny Pack is not full. 
** Post-Conditons: N/A
******************************************************************************************/
string CatLady::addItem(string str) {

	if (fannyPack.size() < 10) {
		fannyPack.push_back(str);

		return str;
	}
	else if (fannyPack.size() >= 10) {
		cout << "Error: your fanny pack has "<< fannyPack.size() << " items and is full! " << endl;

		return "";
	}
	
	else {
		return "Error.";
	}

}



/******************************************************************************************
** Function: removeAllItems
** Description: This functions removes all string items from the vector Fanny Pack. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
void CatLady::removeAllItems() {

	fannyPack.clear();

	if (fannyPack.size() == 0) {
		cout << "Successfully removed all items" << endl;
	}

	else {
		cout << "Unsuccessful removal of all items in fanny pack?" << endl;
	}
}


/******************************************************************************************
** Function: hasItem
** Description: This functions returns a value of 1 if an item is contained in the fanny pack
**		and returns a value of 0 if an item is not contained in the fanny pack. 
** Parameters: One string is passed into the hasItem function to determine if that string is 
**		contained in the fanny pack. 
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
int CatLady::hasItem(string str) {

	for (size_t i = 0; i < fannyPack.size(); i++) {
		if (fannyPack.at(i) == str) {
			return 1;
		}
	}

	return 0;

}