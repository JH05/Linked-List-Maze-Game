#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Room.h"

using namespace std;

class Maze : public Room
{
private:
	Room* start; // Start of Maze.
	Room* end;  // End of Maze.
	Room *A, *B, *C, *D, *E, *F, *G, *H, *I, *J, *K, *L; // Preset Maze Rooms.

	char userInput;	       // Gets the users input from the console.
	bool mazeExit = false; // Used to check if the user is in the Exit room.

public:
	Maze(); // No argument constructor
	~Maze();
	
	void Menu(); // Menu

	void presetMazeNavigation(); // Preset Maze
	void presetMaze();

	void generatedMazeNavigation(); // Randomly Generated Maze
	void generatedMaze();
};

#endif // MAZE_H