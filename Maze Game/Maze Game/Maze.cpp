#include "Maze.h"
#include "ClearConsole.h" // Clears the console.
#include "WaitForInput.h" // Waits for the user input. "Press any key to continue..."

Maze::Maze()
{
	start = NULL;
	end = NULL;
}

Maze::~Maze() 
{ 
	// Destructor
}

void Maze::Menu()
{
	do 
	{
		cout << "[ Maze Game Main Menu ]" << endl;
		cout << "[1] - A Pre-set Maze" << endl;
		cout << "[2] - Randomly Generated Maze" << endl;
		cout << "[Q] - Quit the Maze Game" << endl;
		cout << "Please select and option: ";
		cout << "\n";
		cin >> userInput;

		switch (userInput)
		{
		case '1':
			presetMaze();
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
			cout << "Invalid Input";
			break;
		}
	} while (userInput != 'Q' || userInput != 'q');
}

void Maze::presetMazeNavigation()
{
	// Room Names - used to display the current room the user is in.
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
}

void Maze::presetMaze()
{
	// Room Detection - used to give directions based on the room the user is in.
	string _A = "Grand Foyer", _B = "Game Room", _C = "Kitchen", _D = "Study Room", _E = "Sitting Room",
		   _F = "Music Room", _G = "Dining Room", _H = "Empty Room", _I = "Playroom", _J = "Library", _K = "Sun Room";

	presetMazeNavigation();
	Room* current = A;

	ConsoleClear;
	cout << "You quickly enter a mansion escaping the thunderstorm" << endl;
	cout << "You must navigate your way through the maze and find the exit to survive!" << endl << endl;

	do 
	{
		cout << "You stand in the " << current->getName() << " you look around and see that you can move in an " << endl;

		// Gives direction based on the current room the player is in.
		if (current->getName() == _A)
		{
			cout << "[E]astern, or [S]outhern direction, or [Q]uit: " << endl;
			cout << "It looks like you can go [N]orth too... hmm...";
		}
		else if  (current->getName() == _C)
			cout << "[E]astern, or [S]outhern direction, or [Q]uit: ";
		else if (current->getName() == _B)
			cout << "[S]outhern, or [W]estern direction, or [Q]uit: ";
		else if (current->getName() == _D)
		{
			cout << "[W]estern direction or [Q]uit: " << endl;
			cout << "You see a little door on the [N]orthern side of the room and wondere where it can go...";
		}
		else if (current->getName() == _J)
		{
			cout << "[W]estern direction or [Q]uit: " << endl;
			cout << "You [S]pot a hidden lever on the bookshelf.. ";
		}
		else if (current->getName() == _E)
			cout << "[N]orthern, or [S]outhern direction, or [Q]uit: ";
		else if (current->getName() == _F || current->getName() == _I)
			cout << "[N]orthern, or [E]astern direction or [Q]uit: ";
		else if (current->getName() == _G)
			cout << "[N]orthern, [E]astern, [S]outhern or [W]estern direction, or [Q]uit: ";
		else if (current->getName() == _H)
			cout << "[S]outhern, or [W]estern direction, or [Q]uit: ";
		else if (current->getName() == _K)
			cout << "[N]orth directionern or [Q]uit: ";
		else
		{
			ConsoleClear;
			cout << "You find the exit of the mansion and escape." << endl;
			SystemPause;
			std::exit(0);
		}

		cout << "\n";
		cin >> userInput;

		if (userInput == 'N' || userInput == 'n')
		{ 
			if (current->getNorth() != NULL)
			{
				cout << "You moved North in the maze.";
				current = current->getNorth();
				ConsoleClear;
			}
			else
			{
				ConsoleClear; 
				cout << "You have hit a wall and cannot progress further.\n";
			}
		}

		if (userInput == 'E' || userInput == 'e')
		{
			if (current->getEast() != NULL)
			{
				cout << "You moved East in the maze.";
				current = current->getEast();
				ConsoleClear;
			}
			else
			{
				ConsoleClear;
				cout << "You have hit a wall and cannot progress further.\n";
			}
		}

		if (userInput == 'S' || userInput == 's')
		{
			if (current->getSouth() != NULL)
			{
				cout << "You moved South in the maze.";
				current = current->getSouth();
				ConsoleClear;
			}
			else
			{
				ConsoleClear;
				cout << "You have hit a wall and cannot progress further.\n";
			}
		}
		
		if (userInput == 'W' || userInput == 'w')
		{
			if (current->getWest() != NULL)
			{
				cout << "You moved West in the maze.";
				current = current->getWest();
				ConsoleClear;
			}
			else
			{
				ConsoleClear;
				cout << "You have hit a wall and cannot progress further.\n";
			}
		}

		if (userInput == 'Q' || userInput == 'q')
		{
			ConsoleClear;
			Menu();
		}

	} while (!mazeExit);

	delete current;
}

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
		maze[index]->setNorth( maze[rand() % 12] ); // Randoms North

	for (int index = 0; index < 12; index++)
		maze[index]->setEast( maze[rand() % 12] ); // Randoms East

	for (int index = 0; index < 12; index++)
		maze[index]->setSouth( maze[rand() % 12] ); // Randoms South

	for (int index = 0; index < 12; index++)
		maze[index]->setWest( maze[rand() % 12] ); // Randoms West

	start = maze[0]; // Start of Maze
	end = maze[11];  // End of Maze

}

void Maze::generatedMaze()
{
	string _A = "0", _B = "1", _C = "2", _D = "3", _E = "4", _F = "5", _G = "6", _H = "7", 
		   _I = "8", _J = "9", _K = "10", _MazeExit = "11"; // Exit Room

	generatedMazeNavigation();
	Room* current = start;
	Room* exit = end;

	ConsoleClear;
	cout << "You've been sucked into a weird land." << endl;
	cout << "You must navigate your way through this place and find the exit to survive!" << endl << endl;

	do
	{
		cout << "You are currently in Room: " ;

		if (current->getName() == _MazeExit)
		{
			ConsoleClear;
			cout << "You've found the portal out of this weird land and escape safely." << endl;
			SystemPause;
			std::exit(0);
		}
		else
		{
			// Converts room number to character.
			if (current->getName() == _A)
				cout << "A" << endl;
			if (current->getName() == _B)
				cout << "B" << endl;
			if (current->getName() == _C)
				cout << "C" << endl;
			if (current->getName() == _D)
				cout << "D" << endl;
			if (current->getName() == _E)
				cout << "E" << endl;
			if (current->getName() == _F)
				cout << "F" << endl;
			if (current->getName() == _G)
				cout << "G" << endl;
			if (current->getName() == _H)
				cout << "H" << endl;
			if (current->getName() == _I)
				cout << "I" << endl;
			if (current->getName() == _J)
				cout << "J" << endl;
			if (current->getName() == _K)
				cout << "K" << endl;

			cout << "You can move in an [N]orthern, [E]astern, [S]outhern, [W]estern direction, or [Q]uit" << endl;
			cout << "Which way: ";
			cin >> userInput;

			if (userInput == 'N' || userInput == 'n')
			{
				if (current->getNorth() != NULL)
				{
					cout << "You moved in a Northern direction." << endl;
					current = current->getNorth();
				}
				else
				{
					ConsoleClear;
					cout << "You have hit something and cannot progress further.\n";
				}
			}

			if (userInput == 'E' || userInput == 'e')
			{
				if (current->getEast() != NULL)
				{
					cout << "You moved in a Eastern direction." << endl;
					current = current->getEast();
				}
				else
				{
					ConsoleClear;
					cout << "You have hit something and cannot progress further.\n";
				}
			}

			if (userInput == 'S' || userInput == 's')
			{
				if (current->getSouth() != NULL)
				{
					cout << "You moved in a Southern direction." << endl;
					current = current->getSouth();
				}
				else
				{
					ConsoleClear;
					cout << "You have hit something and cannot progress further.\n";
				}
			}

			if (userInput == 'W' || userInput == 'w')
			{
				if (current->getWest() != NULL)
				{
					cout << "You moved in a Western direction." << endl;
					current = current->getWest();
				}
				else
				{
					ConsoleClear;
					cout << "You have hit something and cannot progress further.\n";
				}
			}

			if (userInput == 'Q' || userInput == 'q')
			{
				ConsoleClear;
				Menu();
			}

		}
	} while (exit);

	delete current;

}