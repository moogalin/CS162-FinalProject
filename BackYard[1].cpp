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
#include "BackYard.hpp"



/******************************************************************************************
** Function: Constructor
** Description: This functions sets preliminary values when the object is created. 
** Parameters: N/A
** Pre-Conditions: This rom object must first be created. 
** Post-Conditons: N/A
******************************************************************************************/
BackYard::BackYard() {
	forward = NULL;
	backward = NULL;
	left = NULL;
	right = NULL;
	numberOfVisits = 0;
	hasCat = false;
	cat = "a cat named KC";
	item1 = "a set of yellow dentures";
	item2 = "a rusty coin";
	name = "backyard";
}



string BackYard::getInfo() {
	string info;

	info = "You've woken up in someone elses body you are sure of it.\n";
	info += " You are drowning in a bright pink mumu speckled with glittery daffodil \n"; 
	info += " vomit. How odd. You don't remember purchasing a mumu, let alone";
	info += " putting one on. You must be dreaming, you decide.\n"; 
	info += " You suddenly have a strange desire to acquire cats.\n";
	info += " You've never owned a cat before but between waking up in a backyard \n";
	info += " and finding yourself in a large mumu, the desire for pet cats is all consuming.\n";
	info += " Small cats, large cats, black, white, and grey cats. You want to own \n";
	info += " all of the cats. In fact, your heart is filled with joy at the prospect \n";
	info += " of multiple pet cats. Now, if only you could get out of this backyard. \n";
	info += " but where will you go and will you find any cats?\n"; 
	info += " You decide to look around. \n"; 

	return info;
}



string BackYard::firstVisitItem() {

	char choice;

	cout << "You notice a large tree in front of you and are suddenly compelled to climb it." << endl;
	cout << " After all, the wooden tree house above could be promising..." << endl;
	cout << " There is also a fresh pile of dirt to the right of the tree with a shovel next to it." << endl;
	cout << " 1. Climb tree" << endl;
	cout << " 2. Dig up hole" << endl;

	choice = validateInput();

	if (choice == '1') {

		cout << "You found " << cat << endl;

		hasCat = true;
		numberOfVisits++;
		return cat;
	}

	else {

		cout << "You found " << item1 << endl;
		numberOfVisits++;
		return item1;
	}
}



string BackYard::secondVisitItem() {

	char choice;

	cout << "You've arrived in the backyard again." << endl;
	cout << "Actions: " << endl;
	cout << "1. Climb tree" << endl;
	cout << "2. Dig up hole" << endl;

	choice = validateInput();

	if (hasCat == false && choice == '1') {

		cout << "You found " << cat << " in the tree" << endl;
		hasCat = true;
		numberOfVisits++;
		return cat;
	}

	else if (hasCat == false && choice == '2') {

		cout << "You found " << cat << " in the hole" << endl;
		numberOfVisits++;
		return cat;
	}

	else if (hasCat == true && choice == '1') {

		cout << "You found " << item2 << " in the tree" << endl;
		numberOfVisits++;
		return item2;
	}

	else {

		cout << "You found " << item1 << " in the tree" << endl;
		numberOfVisits++;
		return item1;
	}
}




string BackYard::laterVisits() {

	cout << "You're in the backyard again. " << endl;
	cout << " Unfortunately, it appears that some clumsy oaf broke a branch so you are unable to climb the tree. " << endl;
	cout << " Also, the hole appears to be dug up and you see nothing in it" << endl;
	cout << " You look around for a moment and then down at your pockets and realize... " << endl;
	cout << " Someone must have stolen from you. There's a hole in your pocket and all of your items and cats are gone!" << endl;
	cout << " You also fall out of the tree, suffer from temporary amnesia," << endl;
	cout << " and forget that you've ever been in the backyard." << endl;

	numberOfVisits = 0;
	return "";
}