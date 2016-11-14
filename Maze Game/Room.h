#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>

using namespace std;

class Room
{
private:
	string roomName; // Room Name

	Room* north; // Directions
	Room* east;
	Room* south; 
	Room* west; 

public:
	Room(); // No argument constructor
	~Room(); // Destructor
	Room(string name);

	void setNorth(Room* next);
	void setEast(Room* next);
	void setWest(Room* next);
	void setSouth(Room* next);

	Room* getNorth();
	Room* getEast();
	Room* getSouth();
	Room* getWest();

	string getName();
};

#endif // ROOM_H