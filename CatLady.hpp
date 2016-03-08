
#include "Room.hpp"

#ifndef CATLADY_HPP
#define CATLADY_HPP


class CatLady {

private:
	Room * location;
	vector<string> fannyPack;
	vector<string> catsSaved;
	int sizeOfHeart;
	bool heartless;

public:
	CatLady();
	void setLocation(Room *);
	Room* getLocation();
	int getSizeOfHeart();
	bool isHeartless();
	void decSizeOfHeart();
	string addItem(string);

};

#endif