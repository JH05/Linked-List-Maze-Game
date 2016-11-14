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

public:
	Maze(); // No argument constructor
	~Maze(); // Destructor

	void Menu(); // Main Menu
	void difficultyMenu(); // Difficulty Menu
	
	void roomNames(); // Sets the Room Names

	void easyMazeNavigation(); // Easy Maze Navigation
	void mediumMazeNavigation(); // Medium Maze Navigation
	void hardMazeNavigation(); // Hard Maze Navigation

	void easyMaze(); // Easy Maze
	void mediumMaze(); // Medium Maze
	void hardMaze(); // Hard Maze

	void generatedMazeNavigation(); // Randomly Generated Maze
	void generatedMaze();
};

#endif // MAZE_H