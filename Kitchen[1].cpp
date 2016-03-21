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
#include "Kitchen.hpp"

/******************************************************************************************
** Function: Constructor
** Description: This functions sets preliminary values when the object is created.
** Parameters: N/A
** Pre-Conditions: This room object must first be created.
** Post-Conditons: N/A
******************************************************************************************/
Kitchen::Kitchen() {
	forward = NULL;
	backward = NULL;
	left = NULL;
	right = NULL;
	numberOfVisits = 0;
	cat = "a cat named Trix";
	item1 = "a feather";
	item2 = "a key";
	name = "kitchen";
	hasKey = false;
}

string Kitchen::getInfo() {
	string info;

	info = " You've entered a kitchen. \n";
	info += " The fridge, though presumably once white, appears as a yellowed";
	info += " image of its former self. \n Although there is again no evidence that\n";
	info += " anyone lives here, the floor is littered with food crumbs.\n";
	info += " With hesitation, you pick a crump up and sniff.... This smells like salmon, you exclaim.\n";
	info += " You pause for a moment and realize, it's cat food!";

	return info;
}

string Kitchen::firstVisitItem() {

	numberOfVisits++;
	cout << " The pungent smell of cat food gets stronger as you get to the kitchen sink" << endl;
	cout << " You bend over and look in the sink only to find... " << endl;
	cout << " " << cat << endl;
	
	return cat;
}

string Kitchen::secondVisitItem() {
	numberOfVisits++;

	cout << " You find yourself in the kitchen again." << endl;
	cout << " This time, you notice what looks to be a large stick" << endl;
	cout << " protruding out from under the kitchen table." << endl;
	cout << " What is it? You wonder, as you grab at it. " << endl;
	cout << " Oh, it is " << item1;
	cout << " This may come in handy, you think," << endl;
	cout << " as you place it in your pocket." << endl;

	return item1;
}

string Kitchen::laterVisits() {

	numberOfVisits++;
	if (hasKey == false) {
		cout << " You find yourself in the kitchen again." << endl;
		cout << " You have got to find a way out of this house!" << endl;
		cout << " A glisten out of the corner of your eye alerts you to an object" << endl;
		cout << " on the ground next to the oven." << endl;
		cout << " My word, you've found " << item2 << endl;
		cout << " Maybe this will help you escape, you only hope," << endl;
		cout << " as you place it in your pocket." << endl;
		hasKey = true;

		return item2;
	}

	else {
		cout << " You are back in the kitchen AGAIN." << endl;
		cout << " But you find nothing of interest this time" << endl;
		return "";
	}

	

}