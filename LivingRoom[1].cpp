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
#include "LivingRoom.hpp"

/******************************************************************************************
** Function: Constructor
** Description: This functions sets preliminary values when the object is created.
** Parameters: N/A
** Pre-Conditions: This room object must first be created.
** Post-Conditons: N/A
******************************************************************************************/
LivingRoom::LivingRoom() {
	forward = NULL;
	backward = NULL;
	left = NULL;
	right = NULL;
	numberOfVisits = 0;
	cat = "a cat named Oreo";
	item1 = "a small cat toy";
	name = "living room";
}

string LivingRoom::getInfo() {
	string info;

	info = "You look around, you've entered a dilapidated living room.\n";
	info += " Broken glass, ripped up books, and old clothes litter the floor around you.\n ";
	info += " The room smells vacant, but you can't shake the feeling that someone\n";
	info += " -- or something -- may live here. \n";
	info += " You gaze silently around the room, unable to determine what to do next. \n";
	info += " From somewhere next to you, you hear a tiny meow. ";

	return info;
}

string LivingRoom::firstVisitItem() {

	cout << " You can't find the source of the meow, " << endl;
	cout << " but next to a pile of dirty laundry you find " << item1 << endl;
	cout << " You put it in your pocket for later, just in case. " << endl;
	numberOfVisits++;

	return item1;
}


string LivingRoom::secondVisitItem() {

	cout << " On your last visit to the living room you heard incessant meowing" << endl;
	cout << " This time you've found its source!" << endl;
	cout << " Near a broken TV, you find " << cat << endl;
	cout << " You bring the cat with you" << endl;

	numberOfVisits++;
	return cat;
}

string LivingRoom::laterVisits() {

	cout << " You find yourself in the living room again, " << endl;
	cout << " but there appears to be nothing interesting." << endl;
	numberOfVisits++;
	return "";
}
