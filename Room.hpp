
#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;


class Room {

protected:
	Room * forward;
	Room * backward;
	Room * left;
	Room * right;

public:

	virtual string getInfo() = 0;
	void visit();
	virtual string firstVisitItem();
	virtual string secondVisitItem();


};

#endif