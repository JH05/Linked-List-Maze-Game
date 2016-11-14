#include "Room.h"

Room::Room()
{
	//north, east, south, west = NULL;
}

Room::~Room() 
{
	cout << "Deleting Object" << endl;
}

Room::Room(string name)
{
	roomName = name;
	//north, east, south, west = NULL;
}

void Room::setNorth(Room* next)
{
	north = next;
}

void Room::setEast(Room* next)
{
	east = next;
}

void Room::setSouth(Room* next)
{
	south = next;
}

void Room::setWest(Room* next)
{
	west = next;
}

Room* Room::getNorth()
{
	return north;
}

Room* Room::getEast()
{
	return east;
}

Room* Room::getSouth()
{
	return south;
}

Room* Room::getWest()
{
	return west;
}

string Room::getName()
{
	return roomName;
}