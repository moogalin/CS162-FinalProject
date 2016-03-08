
#include "Room.hpp"
#include "CatLady.hpp"



char guide();

int main() {

	/* Create Main Character */
	CatLady catLady;
	CatLady * ptrToCatLady = &catLady;

	/* Create Rooms */

	/* Direction for Traveling */
	char direction;


	/* Start in EntryWay */


	do {
		direction = guide();

		ptrToCatLady->addItem("Meow");

	} while (ptrToCatLady->isHeartless() == false);




	return 0;
}

char guide(){

	char choice;
	bool flag = true;

	cout << "\n You choose To Travel Further:" << endl;
	cout << "1. Travel North" << endl;
	cout << "2. Travel East" << endl;
	cout << "3. Travel South" << endl;
	cout << "4. Travel West" << endl;

	cin >> choice;
	cin.ignore();


	while ((choice < '1') || (choice > '4')) {

		cout << "Please enter the integer 1 through 4, only." << endl;
		cout << "Choice: " << endl;
		cin >> choice;
		cin.ignore();
	}
	return choice;

}
