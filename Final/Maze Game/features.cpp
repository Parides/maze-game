#pragma once //To avoid double compilation of files
#include <iostream> //Standard Library
#include <vector> //Vector Library (for times)
#include <Windows.h> //For console modifications and Sleep
#include <stdlib.h> //This library is used for system("cls")
#include <chrono> //This is used for slow printing the characters
#include <conio.h> //_getch()
#include <fstream> //For file storage
#include "declarations.h" //Include header files
#include "entity.h" // Include header file

using namespace std;

void select(int x, int y, bool slct, int& pos, int min, int max)
{
	while (slct == true) //while in menu
	{
		cursor_on_xy(x, y); cout << "<--";
		//system("pause>nul"); // the >nul bit causes it the print no message

		char key = keypress();

		if (key == 'B' && y != max) //Down pressed and position is not the lowest
		{
			cursor_on_xy(x, y); cout << "     "; //Current position make blank
			y++;//move cursor y position +1
			cursor_on_xy(x, y); cout << "<--"; //print to new position the arrow
			pos++; //Increase the counter
			continue; //Continues so the arrow does not keep going down until reaching the end
		}
		if (key == 'U' && y != min) //down button pressed. The rest is the same
		{
			cursor_on_xy(x, y); cout << "     ";
			y--;
			cursor_on_xy(x, y); cout << "<--";
			pos--;
			continue;
		}
		if (key == 'E') //If the escape button is pressed
		{
			break; //break out of the loop (the menu)
		}
	}
}

char keypress()
{
	//This keypress function uses the _getch() command to get the character pressed
	//_getch() is used to avoid mistakes and make continuity flow better
	char press = _getch();

	//For each direction I looked up the ascii codes of the equivalent arrow key and w/a/s/d keys
	//Then set it to a character so it is easier to identify and use in the program
	if (press == 119 || press == 87 || press == 72)
	{
		press = 'U';
	}
	if (press == 115 || press == 80 || press == 83)
	{
		press = 'B';
	}
	if (press == 97 || press == 75 || press == 65)
	{
		press = 'L';
	}
	if (press == 100 || press == 77 || press == 68)
	{
		press = 'R';
	}
	if (press == 13) //return 'Enter'
	{
		press = 'E';
	}
	if (press == 27) //escape 'ESC'
	{
		press = 'Q';
	}
	return press;
}

//The next 3 are escape character functions for menu and game navigation
void space_char()
{
	while (1) //infinit loop unil space
	{
		char c; //set character
	//	bool isspace = false; //FOR TESTIN PURPOSES
		c = _getch(); //to user input
		if (c == 32) //if the keypress is space then
		{
			//		isspace = true; //FOR TESTING PURPOSES
			break; //break out of the loop
		}
	}
}

void esc_char()
{
	while (1)
	{
		char c;
		c = _getch();
		if (c == 27)
		{
			break;
		}
	}
}

void enter_char()
{
	while (1)
	{
		char c;
		c = _getch();
		if (c == 13)
		{
			break;
		}
	}
}

void getPos(int level, int& y, int& x)
{
	//This function defines the position of the player in each level
	//This fucntion also prints the levels, the character and changes the colors with the use of the functions
	if (level == 1)
	{
		blue(); //changes color
		print_lvl(level); //prints level depended on the lvl variable
		white(); //change color for character
		y = 1, x = 2; //set starting positions
		//y = 14, x = 32; // Finish coordinates for testing purposes
		cursor_on_xy(x, y); //Place the cursor on starting coordinates
		cout << "X"; //Print the character
		cursor_on_xy(0, 17); cout << "Press 'ESC' to go back to main menu";
	}
	else if (level == 2)
	{
		green();
		print_lvl(level);
		white();
		y = 2, x = 43;
		//y = 16, x = 46; //END COORDINATES
		cursor_on_xy(x, y);
		cout << "X";
		cursor_on_xy(0, 19); cout << "Press 'ESC' to go back to main menu";
	}
	else if (level == 3)
	{
		yellow();
		print_lvl(level);
		white();
		y = 1, x = 1;
		//y = 2, x = 59; // END COORDS
		cursor_on_xy(x, y);
		cout << "X";
		cursor_on_xy(0, 21); cout << "Press 'ESC' to go back to main menu";
	}
	else if (level == 4)
	{
		red();
		print_lvl(level);
		white();
		y = 11, x = 35;
		//y = 17, x = 69; //END COORDS
		cursor_on_xy(x, y);
		cout << "X";
		cursor_on_xy(0, 22); cout << "Press 'ESC' to go back to main menu";
	}
}

bool trap(int x, int y, int level)
{
	//This chechs for each level the positions of the trap with the positions of the player
	//if they match then return true or if not a false
	if (level == 1)
	{
		if (y == 9 && x == 11 || y == 6 && x == 14 || y == 8 && x == 28)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (level == 2)
	{
		if (y == 14 && x == 46 || y == 8 && x == 11 || y == 15 && x == 37)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (level == 3)
	{
		if (y == 8 && x == 22 || y == 4 && x == 22 || y == 5 && x == 40 || y == 13 && x == 55 || y == 14 && x == 52 || y == 5 && x == 52 || y == 5 && x == 37 || y == 12 && x == 21)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (level == 4)
	{
		if (y == 3 && x == 43 || y == 3 && x == 8 || y == 19 && x == 3 || y == 19 && x == 5 || y == 19 && x == 9 || y == 19 && x == 42 || y == 1 && x == 48 || y == 1 && x == 50 || y == 1 && x == 52 || y == 3 && x == 50 || y == 17 && x == 53 || y == 19 && x == 61 || y == 17 && x == 57 || y == 16 && x == 11 || y == 10 && x == 19 || y == 5 && x == 32)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void print_lvl(int level)
{
	//This function prints the level arrays depended on level variable
	if (level == 1)
	{
		cursor_on_xy(0, 0);

		for (int i = 0; i < 16; i++)
		{
			cout << lvl1[i] << endl;
		}
	}
	if (level == 2) //checks the level
	{
		cursor_on_xy(0, 0); //puts cursor on top left of screen

		int i = 0, j = 0; //counters
		for (i = 0; i < 18; i++) //for loop for rows
		{
			for (j = 0; j < 48; j++) //for columns
			{
				cout << lvl2[i][j]; //prints characters
			}
			cout << endl; //changes line
		}
	}
	if (level == 3)
	{
		cursor_on_xy(0, 0);

		int i = 0, j = 0;
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 61; j++)
			{
				cout << lvl3[i][j];
			}
			cout << endl;
		}
	}
	if (level == 4)
	{
		cursor_on_xy(0, 0);

		int i = 0, j = 0;
		for (i = 0; i < 21; i++)
		{
			for (j = 0; j < 71; j++)
			{
				cout << lvl4[i][j];
			}
			cout << endl;
		}
	}
}

//end.