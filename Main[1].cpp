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
#include "Bedroom.hpp"
#include "BackYard.hpp"
#include "Bathroom.hpp"
#include "LivingRoom.hpp"
#include "HumaneSociety.hpp"
#include "Kitchen.hpp"
#include "CatLady.hpp"

Room * guide(Room * currentRoom);

void travel(CatLady * currentRoom);

string hintList();

void determineOutcome(CatLady *ptrToCatLady);

void visitBackyard(CatLady *ptrToCatLady);

void visitLivingRoom(CatLady *ptrToCatLady);

void visitBedroom(CatLady *ptrToCatLady);

void visitBathroom(CatLady *ptrToCatLady);

void visitKitchen(CatLady *ptrToCatLady);

/******************************************************************************************
** Function: main
** Description: This functions controls the execution of the text-based game. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
int main() {
	/* Begin Game */
	string charName;
	string itemFound; // Using throughout game to self-document
	char hints;
	bool hintVal = false;

	/* Create screen divider */
	string screenDiv = "************************************************************";

	/* Create Rooms */
	Kitchen kitchen;
	Bedroom bedroom;
	Bathroom bathroom;
	HumaneSociety humaneSociety;
	BackYard backyard;
	LivingRoom livingRoom;

	Room * ptrToKitchen = &kitchen;
	Room * ptrToBedroom = &bedroom;
	Room * ptrToBathroom = &bathroom;
	Room * ptrToHumaneSociety = &humaneSociety;
	Room * ptrToBackyard = &backyard;
	Room * ptrToLivingRoom = &livingRoom;

	/* Set up linked structure */
	ptrToKitchen->setDirections(ptrToHumaneSociety, ptrToBathroom, ptrToBedroom, ptrToLivingRoom);
	ptrToBedroom->setDirections(ptrToBedroom, ptrToBathroom, ptrToLivingRoom, ptrToKitchen);
	ptrToBathroom->setDirections(ptrToLivingRoom, ptrToBathroom, ptrToKitchen, ptrToBedroom);
	ptrToHumaneSociety->setDirections(ptrToHumaneSociety, ptrToKitchen, ptrToHumaneSociety, ptrToHumaneSociety);
	ptrToBackyard->setDirections(ptrToBackyard, ptrToBackyard, ptrToLivingRoom, ptrToBackyard);
	ptrToLivingRoom->setDirections(ptrToBackyard, ptrToBathroom, ptrToKitchen, ptrToBedroom);

	/* Start */
	cout << "	Welcome to Crazy Cat Lady!" << endl;
	cout << "An adventure game to unleash your inner cat lover" << endl;
	cout << "In this game, you will explore. Who know's what you will find..." << endl;
	cout << endl << "Please name your character." << endl;
	cout << "Name: ";
	getline(cin, charName);

	/* Create Main Character */
	CatLady catLady(charName);
	CatLady * ptrToCatLady = &catLady;

	cout << "To activate hints, please press \"H\" now." << endl;
	cout << "or press any key to continue without hints. "<< endl;
	cout << "Choice: ";
	cin >> hints;
	cin.ignore();

	if (hints == 'h' || hints == 'H') {
		hintVal = true;
		cout << screenDiv << endl;
		cout << " The following hints will allow you to complete the game, you cheater." << endl << endl;
		cout << hintList() << endl;
		cout << screenDiv << endl;
	}
	else {
		cout << "  You chose not to activate hints." << endl;
	}


	cout << endl << "Welcome " << charName << endl <<" Let's begin..." <<  endl;


	/* Start in Backyard */
	ptrToCatLady->setLocation(ptrToBackyard);


	/* Traverse the game until you are heartlesss, or until you reach the Humane Society */
	do {
	
		/* visiting backyard */
		if (ptrToCatLady->getLocation()->getName() == "backyard") {
			
			visitBackyard(ptrToCatLady);

			/* Travel to new Location */
			cout << screenDiv << endl;
			travel(ptrToCatLady);

		}
		/* Visiting kitchen */
		else if (ptrToCatLady->getLocation()->getName() == "kitchen") {
			
			visitKitchen(ptrToCatLady);

			/* Travel to new Location */
			cout << screenDiv << endl;
			travel(ptrToCatLady);

		}
		/* Visiting Bedroom */
		else if (ptrToCatLady->getLocation()->getName() == "bedroom") {
			
			visitBedroom(ptrToCatLady);

			/* Travel to new Location */
			cout << screenDiv << endl;
			travel(ptrToCatLady);

		}
		/* Visiting Bathroom */
		else if (ptrToCatLady->getLocation()->getName() == "bathroom") {
			
			visitBathroom(ptrToCatLady);

			/* Travel to new Location */
			cout << screenDiv << endl;
			travel(ptrToCatLady);

		}
		/* Visiting Living Room */
		else if (ptrToCatLady->getLocation()->getName() == "living room") {
			visitLivingRoom(ptrToCatLady);

			/* Travel to new Location */
			cout << screenDiv << endl;
			travel(ptrToCatLady);

		}
		/* Visiting Humane Society */
		else if (ptrToCatLady->getLocation()->getName() == "Humane Society") {

			/* You've reached the final location in the game, continue to end of game results. */

		}
		/* Check for errors */
		else {
			cout << "Something is wrong" << endl;
		}

		ptrToCatLady->decSizeOfHeart();
		cout << ptrToCatLady->getName() << "'s heart has decreased in size, oh no!" << endl;
	} while (ptrToCatLady->isHeartless() == false && ptrToCatLady->getLocation()->getName() != "Humane Society" );
	
	/* Cat Lady arrives in the Humane Society. Did she win or lose? */
	if (ptrToCatLady->getLocation()->getName() == "Humane Society") {
		cout << screenDiv << endl;
		determineOutcome(ptrToCatLady);	
	}

	/* Cat lady does not arrive in the Humane Society before she became heartless. */
	else if (ptrToCatLady->isHeartless() == true) {
		cout << screenDiv << endl;
		cout << ptrToCatLady->getName() << " is heartless." << endl;
		cout << "She did not save 5 cats, recover the key, and arrive at the Humane Society in time." << endl;
		cout << ptrToCatLady->getName() << " lost the game." << endl;
		cout << screenDiv << endl;

	}

	/* Check for error */
	else {
		cout << "do-while escape error" << endl;
	}
	return 0;
}



/******************************************************************************************
** Function: guide
** Description: This functions displays a menu allowing the user to select the next direction
**		in which they will travel. 
** Parameters: Pointer to current Room
** Pre-Conditions: N/A
** Post-Conditons: Returns a pointer to the new Room
******************************************************************************************/
Room * guide(Room * currentRoom){

	char choice;
	Room * roomID = NULL;
	bool flag = true;

	cout << "\nYou wish to continue exploring." << endl;
	cout << "Where will you travel:" << endl;
	cout << "1. North." << endl;
	cout << "2. South." << endl;
	cout << "3. West." << endl;
	cout << "4. East." << endl;

	cin >> choice;
	cin.ignore();


	while ((choice < '1') || (choice > '4')) {

		cout << "Please enter the integer 1 through 4, only." << endl;
		cout << "Choice: " << endl;
		cin >> choice;
		cin.ignore();
	}

	if (choice == '1') {
		cout << "You travel North" << endl;
		roomID = currentRoom->getForward();
	}

	else if (choice == '2') {
		cout << "You travel South" << endl;
		roomID = currentRoom->getBackward();
	}

	else if (choice == '3') {
		cout << "You travel West" << endl;
		roomID = currentRoom->getLeft();
	}

	else if (choice == '4') {
		cout << "You travel East" << endl;
		roomID = currentRoom->getRight();
	}

	return roomID;

}



/******************************************************************************************
** Function: travel
** Description: This function coordinates the traveling of the character in the game. 
** Parameters: Pointer to catlady 
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
void travel(CatLady * ptrToCatLady) {

	Room * newRoom = guide(ptrToCatLady->getLocation());
	ptrToCatLady->setLocation(newRoom);

}



/******************************************************************************************
** Function: hintList
** Description: This functions creates a string that can be displayed which provides a complete
**		guide to game play and how to win the game. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
string hintList() {

	string hint;

	hint = "The goal of this game is to find 5 cats, the key, arrive at the Humane Society,\n";
	hint += " and unlock the adoption room to find new homes for the felines\n";
	hint += " before you lose your heart. Each time you travel, your heart will lose one size.\n";
	hint += " Lose 20 sizes and you will be heartless, and automatically lose the game, regardless \n";
	hint += " of how many cats you have acquired and whether or not you've found the key. \n";
	hint += "\n";
	hint += " Where/how to obtain 5 cats: \n";
	hint += " Backyard: Climb the tree and find a cat\n";
	hint += "	(Do not visit 3 times, or you will lose all of your items / cats)\n";
	hint += " Living Room: Find a cat on your 2nd visit\n";
	hint += " Bedroom: On your 2nd visit, open the wardrobe and find a cat\n";
	hint += " Bathroom: Find a cat on your 1st visit\n";
	hint += " Kitchen: Find a cat on your 1st visit\n";
	hint += "\n";
	hint += " How to obtain the key:\n";
	hint += " Find the key on your 3rd visit to the kitchen";
	hint += "\n";
	hint += " You may travel North, South, East, and West\n";
	hint += " Which room you are currently in and which direction\n";
	hint += " Affects which room you travel to.\n";
	hint += " From the Backyard:\n";
	hint += "	North: Return to backyard\n";
	hint += "	South: Return to backyard\n";
	hint += "	East: Return to backyard\n";
	hint += "	West: Move to living Room\n";
	hint += " From the Living Room:\n";
	hint += "	North: Move to backyard\n";
	hint += "	South: Move to bathroom\n";
	hint += "	East: Move to bedroom\n";
	hint += "	West: Move to kitchen\n";
	hint += " From the Bedroom:\n";
	hint += "	North: Return to bedroom\n";
	hint += "	South: Move to bathroom\n";
	hint += "	East: Move to kitchen\n";
	hint += "	West: Move to living room\n";
	hint += " From the Bathroom:\n";
	hint += "	North: Move to living room\n";
	hint += "	South: Move to bathroom\n";
	hint += "	East: Move to bedroom\n";
	hint += "	West: Move to kitchen\n";
	hint += " From the Kitchen:\n";
	hint += "	North: Move to humane society\n";
	hint += "	South: Move to bathroom\n";
	hint += "	East: Move to living room\n";
	hint += "	West: Move to bedroom\n";
	hint += " From the Humane Society:\n";
	hint += "	Once you reach here, the game is over!\n";
	hint += "	You either win or lose.\n";
	hint += "\n";
	hint += " One way to beat the game (there are many):\n";
	hint += "1.  Climb the tree in the Backyard and find cat 1\n";
	hint += "2.  Travel West to Living Room.\n";
	hint += "3.  Travel East to Bedroom.\n";
	hint += "4.  Travel West to Living Room (2nd visit, cat 2)\n";
	hint += "5.  Travel South to Bathroom and find cat 3\n";
	hint += "6.  Travel East to Bedroom and open wardrobe (2nd visit, cat 4)\n";
	hint += "7.  Travel East to Kitchen and find cat 5.\n";
	hint += "8.  Travel East to Living Room\n";
	hint += "9.  Travel West to Kitchen (2nd visit)\n";
	hint += "10. Travel East to Living Room\n";
	hint += "11. Travel West to Kitchen (3rd visit, find key)\n";
	hint += "12. Travel North to Humane Society, and win!!\n";

	return hint;

}



/******************************************************************************************
** Function: determineOutcome
** Description: This functions determines whether or not the player has won the game, depending
**		on if they arrive at the Humane Society, collect 5 cats, and find the key. 
** Parameters: Pointer to cat lady 
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
void determineOutcome(CatLady *ptrToCatLady) {

	cout << ptrToCatLady->getLocation()->getInfo();

	int	numCats = 0;
	int key = 0;
	string cat1 = "a cat named KC";
	string cat2 = "a cat named Trix";
	string cat3 = "a cat named Oreo";
	string cat4 = "a cat named Blue";
	string cat5 = "a cat named Shadow";
	string keys = "a key";

	numCats = ptrToCatLady->hasItem(cat1);
	numCats += ptrToCatLady->hasItem(cat2);
	numCats += ptrToCatLady->hasItem(cat3);
	numCats += ptrToCatLady->hasItem(cat4);
	numCats += ptrToCatLady->hasItem(cat5);
	key = ptrToCatLady->hasItem(keys);

	cout << " You found " << numCats << " cats" << endl;

	if (key == 1) {
		cout << " You found the key!" << endl;
		cout << " We can put the cats on the adoption floor now!, exclaims the receptionist!" << endl;
	}

	else {
		cout << "You did not find the key!" << endl;
		cout << "How will we rescue the cats if we can't put them on the adoption floor?" << endl;
	}

	if (key == 1 && numCats == 5) {
		cout << endl << "You've won the game!" << endl;
		cout << "You saved all five cats " << endl;
		cout << "and successfully placed them up for adoption" << endl;
		cout << "Congratulations! You have a huge heart!" << endl;
	}

	else {
		cout << endl << "You needed to find the key and find all 5 cats" << endl;
		cout << "Since you didnt, you've lost the game." << endl;
		cout << "Better luck next time" << endl;
	}

}



/******************************************************************************************
** Function: visitRoom functions
** Description: These functions control the events that take place when each room is visited. 
**		These functions help declutter the main function (avoiding numerous if-else statements)
** Parameters: pointer to cat lady
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
void visitBackyard(CatLady *ptrToCatLady) {
	string screenDiv = "************************************************************";
	string itemFound;

	cout << screenDiv << endl;

	if (ptrToCatLady->getLocation()->getNumberOfVisits() == 0) {
		cout << ptrToCatLady->getLocation()->getInfo() << endl;
		itemFound = (ptrToCatLady->getLocation()->firstVisitItem());
		ptrToCatLady->addItem(itemFound);

	}

	else if (ptrToCatLady->getLocation()->getNumberOfVisits() == 1) {
		cout << ptrToCatLady->getName() << " is in a backyard" << endl;
		cout << ptrToCatLady->getName() << " previously visited this backyard " << ptrToCatLady->getLocation()->getNumberOfVisits();
		cout << " times." << endl << endl;

		itemFound = (ptrToCatLady->getLocation()->secondVisitItem());
		ptrToCatLady->addItem(itemFound);
	}

	else {
		cout << ptrToCatLady->getName() << " is in a backyard" << endl;
		cout << ptrToCatLady->getName() << " previously visited this backyard " << ptrToCatLady->getLocation()->getNumberOfVisits();
		cout << " times." << endl << endl;

		itemFound = (ptrToCatLady->getLocation()->laterVisits());
		ptrToCatLady->removeAllItems();
	}
}

void visitLivingRoom(CatLady *ptrToCatLady) {
	string screenDiv = "************************************************************";
	string itemFound;

	cout << ptrToCatLady->getName() << " is in a living Room" << endl;
	cout << screenDiv << endl;



	if (ptrToCatLady->getLocation()->getNumberOfVisits() == 0) {
		cout << ptrToCatLady->getLocation()->getInfo() << endl;

		itemFound = (ptrToCatLady->getLocation()->firstVisitItem());
		ptrToCatLady->addItem(itemFound);
	}

	else if (ptrToCatLady->getLocation()->getNumberOfVisits() == 1) {
		cout << ptrToCatLady->getName() << " is in a living Room" << endl;
		cout << ptrToCatLady->getName() << " previously visited this living room " << ptrToCatLady->getLocation()->getNumberOfVisits();
		cout << " times." << endl << endl;

		itemFound = (ptrToCatLady->getLocation()->secondVisitItem());
		ptrToCatLady->addItem(itemFound);
	}

	else {
		cout << ptrToCatLady->getName() << " is in a living Room" << endl;
		cout << ptrToCatLady->getName() << " previously visited this living room " << ptrToCatLady->getLocation()->getNumberOfVisits();
		cout << " times." << endl << endl;

		itemFound = (ptrToCatLady->getLocation()->laterVisits());
	}
}

void visitBedroom(CatLady *ptrToCatLady) {
	string screenDiv = "************************************************************";
	string itemFound;

	cout << ptrToCatLady->getName() << " is in a bedroom" << endl;
	cout << screenDiv << endl;

	if (ptrToCatLady->getLocation()->getNumberOfVisits() == 0) {
		cout << ptrToCatLady->getLocation()->getInfo() << endl;
		itemFound = (ptrToCatLady->getLocation()->firstVisitItem());
		ptrToCatLady->addItem(itemFound);
	}

	else if (ptrToCatLady->getLocation()->getNumberOfVisits() == 1) {
		cout << ptrToCatLady->getName() << " is in a bedroom" << endl;
		cout << ptrToCatLady->getName() << " previously visited this bedroom " << ptrToCatLady->getLocation()->getNumberOfVisits();
		cout << " times." << endl << endl;


		itemFound = (ptrToCatLady->getLocation()->secondVisitItem());
		ptrToCatLady->addItem(itemFound);
	}

	else {
		cout << ptrToCatLady->getName() << " is in a bedroom" << endl;
		cout << ptrToCatLady->getName() << " previously visited this bedroom " << ptrToCatLady->getLocation()->getNumberOfVisits();
		cout << " times." << endl << endl;

		itemFound = (ptrToCatLady->getLocation()->laterVisits());
		ptrToCatLady->addItem(itemFound);
	}
}

void visitBathroom(CatLady *ptrToCatLady) {
	string screenDiv = "************************************************************";
	string itemFound;

	cout << ptrToCatLady->getName() << " is in a bathroom" << endl;
	cout << screenDiv << endl;


	if (ptrToCatLady->getLocation()->getNumberOfVisits() == 0) {
		cout << ptrToCatLady->getLocation()->getInfo() << endl;

		itemFound = (ptrToCatLady->getLocation()->firstVisitItem());
		ptrToCatLady->addItem(itemFound);

	}

	else if (ptrToCatLady->getLocation()->getNumberOfVisits() == 1) {
		cout << ptrToCatLady->getName() << " is in a bathroom" << endl;
		cout << ptrToCatLady->getName() << " previously visited this bathroom " << ptrToCatLady->getLocation()->getNumberOfVisits();
		cout << " times." << endl << endl;

		itemFound = (ptrToCatLady->getLocation()->secondVisitItem());
		ptrToCatLady->addItem(itemFound);
	}

	else {
		cout << ptrToCatLady->getName() << " is in a bathroom" << endl;
		cout << ptrToCatLady->getName() << " previously visited this bathroom " << ptrToCatLady->getLocation()->getNumberOfVisits();
		cout << " times." << endl << endl;

		itemFound = (ptrToCatLady->getLocation()->laterVisits());
		ptrToCatLady->addItem(itemFound);
	}

}

void visitKitchen(CatLady *ptrToCatLady) {
	string screenDiv = "************************************************************";
	string itemFound;

	cout << screenDiv << endl;

	if (ptrToCatLady->getLocation()->getNumberOfVisits() == 0) {
		cout << ptrToCatLady->getLocation()->getInfo() << endl;

		itemFound = (ptrToCatLady->getLocation()->firstVisitItem());
		ptrToCatLady->addItem(itemFound);
	}

	else if (ptrToCatLady->getLocation()->getNumberOfVisits() == 1) {
		cout << ptrToCatLady->getName() << " is in a kitchen" << endl;
		cout << ptrToCatLady->getName() << " previously visited this kitchen " << ptrToCatLady->getLocation()->getNumberOfVisits();
		cout << " times." << endl << endl;

		itemFound = (ptrToCatLady->getLocation()->secondVisitItem());
		ptrToCatLady->addItem(itemFound);
	}

	else {
		cout << ptrToCatLady->getName() << " is in a kitchen" << endl;
		cout << ptrToCatLady->getName() << " previously visited this kitchen " << ptrToCatLady->getLocation()->getNumberOfVisits();
		cout << " times." << endl << endl;

		itemFound = (ptrToCatLady->getLocation()->laterVisits());
		ptrToCatLady->addItem(itemFound);

	}
}
