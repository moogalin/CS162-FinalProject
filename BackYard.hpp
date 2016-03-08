
#ifndef BACKYARD_HPP
#define BACKYARD_HPP

#include "Room.hpp"

class BackYard : public Room {

private:

public:
	string getInfo();
	string firstVisitItem();
	string secondVisitItem();

};


#endif
