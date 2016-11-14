#include "Maze.h"
#include "ClearConsole.h" // Clears the console.
#include "WaitForInput.h" // Waits for the user input. "Press any key to continue..."

char userInput;	       // Gets the users input from the console.
bool mazeExit = false; // Used to check if the user is in the Exit room.

Maze::Maze()
{
	start = NULL;
	end = NULL;
};

Maze::~Maze()
{
	cout << "Deleting Object" << endl;
};

void Maze::Menu()
{
	do
	{
		cout << " Maze Game Main Menu " << endl;
		cout << "  ----------------- " << endl;
		cout << " [1] - A Pre-set Maze" << endl;
		cout << " [2] - Randomly Generated Maze" << endl;
		cout << " [Q] - Quit" << endl;
		cout << "  ----------------- " << endl;
		cout << "Please select an option: " << endl;
		cin >> userInput;

		switch (userInput)
		{
		case '1':
			difficultyMenu();
			ConsoleClear;
			break;
		case '2':
			generatedMaze();
			ConsoleClear;
			break;
		case 'Q':
			std::exit(0);
			break;
		case 'q':
			std::exit(0);
			break;
		default:
			cout << "Invalid Input" << endl;
			ConsoleClear;
			break;
		}
	} while (userInput != 'Q' || userInput != 'q');
}; // end Maze::Maze()

void Maze::difficultyMenu()
{
	do
	{
		ConsoleClear;
		cout << " Pre-set Maze Difficulty " << endl;
		cout << "  ----------------- " << endl;
		cout << " [E] - Easy Difficulty" << endl;
		cout << " [M] - Medium Difficulty" << endl;
		cout << " [H] - Hard Difficulty" << endl;
		cout << " [B] - Back" << endl;
		cout << " [Q] - Quit" << endl;
		cout << "  ----------------- " << endl;
		cout << "Please select an option: " << endl;
		cin >> userInput;

		switch (userInput)
		{
		case 'E':
			easyMaze();
			ConsoleClear;
			break;
		case 'e':
			easyMaze();
			ConsoleClear;
			break;
		case 'M':
			mediumMaze();
			ConsoleClear;
			break;
		case 'm':
			mediumMaze();
			ConsoleClear;
			break;
		case 'H':
			hardMaze();
			ConsoleClear;
			break;
		case 'h':
			hardMaze();
			ConsoleClear;
			break;
		case 'B':
			ConsoleClear;
			Menu();
			break;
		case 'b':
			ConsoleClear;
			Menu();
			break;
		case 'Q':
			std::exit(0);
			break;
		case 'q':
			std::exit(0);
			break;
		default:
			cout << "Invalid Input";
			ConsoleClear;
			break;
		}
	} while (userInput != 'Q' || userInput != 'q');
}; // end Maze::difficulty()

void Maze::roomNames()
{
	// Room Names - used to display the move room the user is in.
	A = new Room("Grand Foyer");
	B = new Room("Game Room");
	C = new Room("Kitchen");
	D = new Room("Study Room");
	E = new Room("Sitting Room");
	F = new Room("Music Room");
	G = new Room("Dining Room");
	H = new Room("Empty Room");
	I = new Room("Playroom");
	J = new Room("Library");
	K = new Room("Sun Room");
	L = new Room("Exit");
}; // end Maze::defaultMaze()

void Maze::easyMazeNavigation()
{
	// Gets Room Names.
	roomNames();

	// Maze Navigation - rooms the user can go in order to complete the maze.
	A->setEast(B);
	B->setEast(C);
	C->setEast(D);
	D->setSouth(H);
	H->setSouth(L);
}; // end Maze::easyMazeNavigation()

void Maze::mediumMazeNavigation()
{
	// Gets Room Names.
	roomNames();

	// Maze Navigation - rooms the user can go in order to complete the maze.
	A->setEast(B);
	A->setSouth(E);
	B->setSouth(F), B->setWest(A);
	C->setEast(D), C->setSouth(G);
	D->setWest(C);
	E->setNorth(A), E->setSouth(I);
	F->setNorth(A), F->setEast(G);
	G->setNorth(C), G->setEast(H), G->setSouth(K), G->setWest(F);
	H->setSouth(L), H->setWest(G);
	I->setNorth(E), I->setEast(J);
	J->setWest(I);
	K->setNorth(G);

	// Hidden Passages - moves around the maze quicker.
	A->setNorth(L);
	D->setEast(A);
	J->setSouth(B);
}; // end Maze::mediumMazeNavigation()

void Maze::hardMazeNavigation()
{
	// Gets Room Names.
   roomNames();

	// Maze Navigation - rooms the user can go in order to complete the maze.
	A->setNorth(I);
	B->setSouth(F), B->setEast(C);
	C->setNorth(K), C->setEast(D);
	D->setWest(C), D->setEast(A), D->setSouth(H);
	E->setEast(F), E->setSouth(I);
	F->setWest(E), F->setNorth(B);
	G->setSouth(K);
	H->setSouth(L), H->setEast(E);
	I->setNorth(E), I->setEast(J), I->setWest(A);
	J->setSouth(B), J->setWest(I);
	K->setSouth(C), K->setNorth(G);
}; // end Maze::hardMazeNavigation()

void Maze::easyMaze()
{
	easyMazeNavigation();
	Room* move = A;

	ConsoleClear;
	cout << "You quickly enter a small home to escape the thunderstorm" << endl;
	cout << "You must navigate your way through the house and find the exit!" << endl << endl;

	do
	{
		cout << "You stand in the " << move->getName() << " you look around: " << endl;

		// Gives direction based on the move room the player is in.
		if (move->getName() == "Grand Foyer" || move->getName() == "Game Room" || move->getName() == "Kitchen" || move->getName() == "Sitting Room")
		{
			cout << "[E]astern direction, or [Q]uit: " << endl;
		}

		else if (move->getName() == "Study Room" || move->getName() == "Empty Room")
		{
			cout << "[S]outhern direction, or [Q]uit: " << endl;
		}

		else if (move->getName() == "Exit")
		{
			ConsoleClear;
			cout << "You find the exit of the mansion and escape." << endl;
			SystemPause;
			ConsoleClear;
			Menu();
		}

		else
		{
			cout << "Invalid Input" << endl;
		}

		cin >> userInput;

		if (userInput == 'N' || userInput == 'n')
		{
			if (move->getNorth() != NULL)
			{
				cout << "You moved North in the maze.";
				move = move->getNorth();
				ConsoleClear;
			}
			else
			{
				ConsoleClear;
				cout << "You have hit a wall and cannot progress further." << endl;
			}
		}

		else if (userInput == 'E' || userInput == 'e')
		{
			if (move->getEast() != NULL)
			{
				cout << "You moved East in the maze.";
				move = move->getEast();
				ConsoleClear;
			}
			else
			{
				ConsoleClear;
				cout << "You have hit a wall and cannot progress further." << endl;
			}
		}

		else if (userInput == 'S' || userInput == 's')
		{
			if (move->getSouth() != NULL)
			{
				cout << "You moved South in the maze.";
				move = move->getSouth();
				ConsoleClear;
			}
			else
			{
				ConsoleClear;
				cout << "You have hit a wall and cannot progress further." << endl;
			}
		}

		else if (userInput == 'W' || userInput == 'w')
		{
			if (move->getWest() != NULL)
			{
				cout << "You moved West in the maze.";
				move = move->getWest();
				ConsoleClear;
			}
			else
			{
				ConsoleClear;
				cout << "You have hit a wall and cannot progress further." << endl;
			}
		}

		else if (userInput == 'Q' || userInput == 'q')
		{
			ConsoleClear;
			Menu();
		}

		else
		{
			cout << "Invalid Input" << endl;
		}

	} while (!mazeExit);

	delete move;
}; // end Maze::easyMaze()

void Maze::mediumMaze()
{
	mediumMazeNavigation();
	Room* move = A;

	ConsoleClear;
	cout << "You quickly enter a mansion escaping the thunderstorm" << endl;
	cout << "You must navigate your way through the maze and find the exit to survive!" << endl << endl;

	do
	{
		cout << "You stand in the " << move->getName() << " you look around and see that you can move in an " << endl;

		// Gives direction based on the move room the player is in.
		if (move->getName() == "Grand Foyer")
		{
			cout << "[E]astern, or [S]outhern direction, or [Q]uit: " << endl;
			cout << "It looks like you can go [N]orth too... hmm..." << endl;
		}
		else if  (move->getName() == "Kitchen")
		{
			cout << "[E]astern, or [S]outhern direction, or [Q]uit: ";
		}
		else if (move->getName() == "Game Room")
		{
			cout << "[S]outhern, or [W]estern direction, or [Q]uit: ";
		}
		else if (move->getName() == "Study Room")
		{
			cout << "[W]estern direction or [Q]uit: " << endl;
			cout << "You see a little door on the [N]orthern side of the room and wondere where it can go...";
		}
		else if (move->getName() == "Library")
		{
			cout << "[W]estern direction or [Q]uit: " << endl;
			cout << "You [S]pot a hidden lever on the bookshelf.. ";
		}
		else if (move->getName() == "Sitting Room")
		{
			cout << "[N]orthern, or [S]outhern direction, or [Q]uit: ";
		}
		else if (move->getName() == "Music Room" || move->getName() == "Playroom")
		{
			cout << "[N]orthern, or [E]astern direction or [Q]uit: ";
		}
		else if (move->getName() == "Dining Room")
		{
			cout << "[N]orthern, [E]astern, [S]outhern or [W]estern direction, or [Q]uit: ";
		}
		else if (move->getName() == "Empty Room")
		{
			cout << "[S]outhern, or [W]estern direction, or [Q]uit: ";
		}
		else if (move->getName() == "Sun Room")
		{
			cout << "[N]orth directionern or [Q]uit: ";
		}
		else if (move->getName() == "Exit")
		{
			ConsoleClear;
			cout << "You find the exit of the mansion and escape." << endl;
			SystemPause;
			ConsoleClear;
			Menu();
		}
		else
		{
			cout << "Invalid Input" << endl;
		}

		cin >> userInput;

		if (userInput == 'N' || userInput == 'n')
		{
			if (move->getNorth() != NULL)
			{
				cout << "You moved North in the maze.";
				move = move->getNorth();
				ConsoleClear;
			}
			else
			{
				ConsoleClear;
				cout << "You have hit a wall and cannot progress further." << endl;
			}
		}

		else if (userInput == 'E' || userInput == 'e')
		{
			if (move->getEast() != NULL)
			{
				cout << "You moved East in the maze.";
				move = move->getEast();
				ConsoleClear;
			}
			else
			{
				ConsoleClear;
				cout << "You have hit a wall and cannot progress further." << endl;
			}
		}

		else if (userInput == 'S' || userInput == 's')
		{
			if (move->getSouth() != NULL)
			{
				cout << "You moved South in the maze.";
				move = move->getSouth();
				ConsoleClear;
			}
			else
			{
				ConsoleClear;
				cout << "You have hit a wall and cannot progress further." << endl;
			}
		}

		else if (userInput == 'W' || userInput == 'w')
		{
			if (move->getWest() != NULL)
			{
				cout << "You moved West in the maze.";
				move = move->getWest();
				ConsoleClear;
			}
			else
			{
				ConsoleClear;
				cout << "You have hit a wall and cannot progress further." << endl;
			}
		}

		else if (userInput == 'Q' || userInput == 'q')
		{
			ConsoleClear;
			Menu();
		}

		else
		{
			cout << "Invalid Input" << endl;
		}

	} while (!mazeExit);

	delete move;
}; // end Maze::mediumMaze()

void Maze::hardMaze()
{
	hardMazeNavigation();
	Room* move = A;

	ConsoleClear;
	cout << "You fall down a trap door and enter a maze" << endl;
	cout << "You must navigate your way through said maze and find the exit to survive!" << endl << endl;

	do
	{
		cout << "You think you are in the " << move->getName() << " you look around and see nothing, however you can move in an " << endl;

		// Gives direction based on the move room the player is in.
		cout << "[N]orthern, [E]astern, [S]outhern, or [W]estern direction or [Q]uit: " << endl;
		cin >> userInput;

		if (move->getName() != "Exit")
		{

			if (userInput == 'N' || userInput == 'n')
			{
				if (move->getNorth() != NULL)
				{
					cout << "You moved North in the maze.";
					move = move->getNorth();
					ConsoleClear;
				}
				else
				{
					ConsoleClear;
					cout << "You have hit a wall and cannot progress further." << endl;
				}
			}

			else if (userInput == 'E' || userInput == 'e')
			{
				if (move->getEast() != NULL)
				{
					cout << "You moved East in the maze.";
					move = move->getEast();
					ConsoleClear;
				}
				else
				{
					ConsoleClear;
					cout << "You have hit a wall and cannot progress further." << endl;
				}
			}

			else if (userInput == 'S' || userInput == 's')
			{
				if (move->getSouth() != NULL)
				{
					cout << "You moved South in the maze.";
					move = move->getSouth();
					ConsoleClear;
				}
				else
				{
					ConsoleClear;
					cout << "You have hit a wall and cannot progress further." << endl;
				}
			}

			else if (userInput == 'W' || userInput == 'w')
			{
				if (move->getWest() != NULL)
				{
					cout << "You moved West in the maze.";
					move = move->getWest();
					ConsoleClear;
				}
				else
				{
					ConsoleClear;
					cout << "You have hit a wall and cannot progress further." << endl;
				}
			}

			else if (userInput == 'Q' || userInput == 'q')
			{
				ConsoleClear;
				Menu();
			}

			else
			{
				cout << "Invalid Input" << endl;
			}
		}
		else
		{
			ConsoleClear;
			cout << "You've found the exit door and escape safely." << endl;
			SystemPause;
			ConsoleClear;
			Menu();
		}
	} while (!mazeExit);

	delete move;
}; // end Maze::hardMaze()

void Maze::generatedMazeNavigation()
{
	Room* maze[12]; // Number of maze rooms

	for (int index = 0; index < 12; index++)
	{
		string text = "";
		ostringstream room;

		room << text << index; // Prints out where the user is in the maze

		string newroom = room.str();
		maze[index] = new Room(newroom);
	}

	for (int index = 0; index < 12; index++)
	{
		maze[index]->setNorth( maze[rand() % 12] ); // Randoms North
	}

	for (int index = 0; index < 12; index++)
	{
		maze[index]->setEast( maze[rand() % 12] ); // Randoms East
	}

	for (int index = 0; index < 12; index++)
	{
		maze[index]->setSouth( maze[rand() % 12] ); // Randoms South
	}

	for (int index = 0; index < 12; index++)
	{
		maze[index]->setWest( maze[rand() % 12] ); // Randoms West
	}

	start = maze[0]; // Start of Maze
	end = maze[11];  // End of Maze

}; // end Maze::generatedMazeNavigation()

void Maze::generatedMaze()
{
	generatedMazeNavigation();
	Room* move = start;
	Room* exit = end;

	ConsoleClear;
	cout << "You've been sucked into a weird land." << endl;
	cout << "You must navigate your way through this place and find the exit to survive!" << endl << endl;

	do
	{
		cout << "You are movely in Room: ";

		if (move->getName() == "11")
		{
			ConsoleClear;
			cout << "You've found the portal out of this weird land and escape safely." << endl;
			SystemPause;
			ConsoleClear;
			Menu();
		}

		else
		{

			cout << "You can move in an [N]orthern, [E]astern, [S]outhern, [W]estern direction, or [Q]uit" << endl;
			cout << "Which way: ";
			cin >> userInput;

			if (userInput == 'N' || userInput == 'n')
			{
				if (move->getNorth() != NULL)
				{
					cout << "You moved in a Northern direction." << endl;
					move = move->getNorth();
				}
				else
				{
					ConsoleClear;
					cout << "You have hit something and cannot progress further." << endl;
				}
			}

			else if (userInput == 'E' || userInput == 'e')
			{
				if (move->getEast() != NULL)
				{
					cout << "You moved in a Eastern direction." << endl;
					move = move->getEast();
				}
				else
				{
					ConsoleClear;
					cout << "You have hit something and cannot progress further." << endl;
				}
			}

			else if (userInput == 'S' || userInput == 's')
			{
				if (move->getSouth() != NULL)
				{
					cout << "You moved in a Southern direction." << endl;
					move = move->getSouth();
				}
				else
				{
					ConsoleClear;
					cout << "You have hit something and cannot progress further." << endl;
				}
			}

			else if (userInput == 'W' || userInput == 'w')
			{
				if (move->getWest() != NULL)
				{
					cout << "You moved in a Western direction." << endl;
					move = move->getWest();
				}
				else
				{
					ConsoleClear;
					cout << "You have hit something and cannot progress further." << endl;
				}
			}

			else if (userInput == 'Q' || userInput == 'q')
			{
				ConsoleClear;
				Menu();
			}

			else 
			{
				cout << "Invalid Input" << endl;
			}

		} // end else

	} while (exit);

	delete move;

}; // end Maze::generatedMaze()