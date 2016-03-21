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
#include "Bedroom.hpp"

/******************************************************************************************
** Function: Constructor
** Description: This functions sets preliminary values when the object is created.
** Parameters: N/A
** Pre-Conditions: This room object must first be created.
** Post-Conditons: N/A
******************************************************************************************/
Bedroom::Bedroom() {
	forward = NULL;
	backward = NULL;
	left = NULL;
	right = NULL;
	numberOfVisits = 0;
	cat = "a cat named Blue";
	item1 = "a moldy paper cup";
	item2 = "a half eaten bowl of cat food";
	name = "bedroom";
	hasCat = false;
}



string Bedroom::getInfo() {
	string info;

	info = "It appears you have traveled back in time to the early 1970s.\n";
	info += " This bedroom smells of moth-balls and dying things. \n";
	info += " The retro shag carpet is enveloping your feet, like tall grass.\n";
	info += " You shudder as you think about all of the stains, and the fact that\n ";
	info += " this carpet has likely *never* been washed. \n";
	info += " Across from you, you notice an old wardrobe. You approach the muddy \n";
	info += " brown object to investigate. \n";

	return info;
}



string Bedroom::firstVisitItem() {

	numberOfVisits++;
	cout << " The wardrobe creaks as you open it" << endl;
	cout << " You see several dusty jackets hanging in the otherwise empty wardrobe." << endl;
	cout << " On the ground in the back of the wardrobe you see a..." << endl;
	cout << " ... a... " << item1 << " ?" << endl;
	cout << " You place it in your pocket, just in case" << endl;
	cout << " And close the wardrobe door before you leave." << endl;

	return item1;
}



string Bedroom::secondVisitItem() {

	char choice;
	numberOfVisits++;
	cout << " Perhaps it was a wrong turn, but you suddenly find yourself in the bedroom again" << endl;
	cout << " You hear a scratching noise coming from somewhere in the bedroom" << endl;
	cout << " What could it bed?" << endl;
	cout << " You look under the bed and in the closet to no avail. " << endl;
	cout << " Then you notice the door of the wardrobe shudder. " << endl;
	cout << " Something must be in there, you think. " << endl;
	cout << " Do you open the wardrobe again?" << endl;
	cout << " 1. Yes, open it" << endl;
	cout << " 2. No way, get out of there" << endl;

	choice = validateInput();

	if (choice == '1') {
		hasCat = true;
		cout << " You open the wardrobe and find " << cat << endl;
		cout << " You take the furry fella with you." << endl;
		return cat;
	}

	else {
		cout << " You quickly head out of the room but notice "; 
		cout << item2 << " and put it in your pocket." << endl;
		cout << " You never know..." << endl;
		return item2;
	}
}



string Bedroom::laterVisits() {

	numberOfVisits++;
	cout << " Yet again you find yourself in the bedroom." << endl;
	cout << " This time, there is nothing left to see." << endl;
	cout << " You decide to turn around and head out of here before anything weird happens" << endl;
	cout << " On your way out you notice";

	if (hasCat == false) {
		hasCat = true;
		cout << cat << endl;
		cout << " and decide to take it with you." << endl;
	}

	else {
		cout << item1 << endl;
		cout << " Weird.. haven't I already found one of these?" << endl;
		cout << " You ask yourself, as you proceed to put it in your pocket." << endl;
		return item1;
	}
}