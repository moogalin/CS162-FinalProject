
#include "CatLady.hpp"


CatLady::CatLady() {
	location = NULL;
	sizeOfHeart = 20;
	heartless = false;
}

void CatLady::setLocation(Room *loc) {
	location = loc;

}

Room* CatLady::getLocation() {
	return location;
}

int CatLady::getSizeOfHeart() {
	return sizeOfHeart;
}

bool CatLady::isHeartless() {

	return heartless;
}
void CatLady::decSizeOfHeart() {
	sizeOfHeart--;

	if (sizeOfHeart = 0) {
		heartless = true;
	}
}

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