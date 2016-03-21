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
#include "Bathroom.hpp"

/******************************************************************************************
** Function: Constructor
** Description: This functions sets preliminary values when the object is created.
** Parameters: N/A
** Pre-Conditions: This rom object must first be created.
** Post-Conditons: N/A
******************************************************************************************/
Bathroom::Bathroom() {
	forward = NULL;
	backward = NULL;
	left = NULL;
	right = NULL;
	numberOfVisits = 0;
	cat = "a cat named Shadow";
	item1 = "a small coin";
	item2 = "a beef jerky stick";
	name = "bathroom";
	hasJerky = false;
}



string Bathroom::getInfo() {
	string info;

	info = "You hear the slow drip, drip, drip of the sink.\n";
	info += " The bathroom that you have entered is too... pink\n";
	info += " Pink flamingo wall paper, a pink ceramic toilet and sink.\n";
	info += " You shudder as you enter it, asking yourself, why am I in here?\n";

	return info;
}



string Bathroom::firstVisitItem() {
	numberOfVisits++;
	cout << " You hear meowing coming from behind inside the bathtub" << endl;
	cout << " Jumping out of the bath tub is " << cat << endl;
	cout << " You decide to take the furry creature with you as you leave the bathroom" << endl;

	return cat;
}



string Bathroom::secondVisitItem() {
	numberOfVisits++;
	cout << " Is it just me, you think, or is this bathroom ten times more smelly" << endl;
	cout << " Than it was the last time I was here?" << endl;
	cout << " You notice a litterbox behind the toilet, with a scooper hanging out of it." << endl;
	cout << " Do you clean the litterbox?" << endl;
	cout << " 1. Yes" << endl;
	cout << " 2. No" << endl;

	char choice = validateInput();

	if (choice == '1') {
		cout << " You clean the litterbox and find " << item2 << endl;
		hasJerky = true;
		return item2;
	}

	else  {
		cout << " You decide not to clean the litterbox." << endl;
		cout << " As you leave the bathroom you find " << item1 << endl;
		return item1;
	}

}



string Bathroom::laterVisits() {

	numberOfVisits++;
	cout << " Yet again, the bathroom is super smelly" << endl;
	cout << " Do you clean the litterbox?" << endl;
	cout << " 1. Yes" << endl;
	cout << " 2. No" << endl;

	char choice = validateInput();

	if (choice == '1') {
		cout << " You clean the litterbox and find ";
		if (hasJerky == false) {
			cout << item2 << endl;
			return item2;
		}
		else {
			cout << item1 << endl;
			return item1;
		}
	}

	else {
		cout << " You decide not to clean the litterbox." << endl;
		cout << " As you leave the bathroom you find " << item1 << endl;
		return item1;
	}

}