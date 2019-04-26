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

using namespace std; //to avoid usint std::

int main()
{
	SetFont(); //changes font of console
	SetWindow(240, 120); //changes size of console

	//load the scores
	loadlvl1();
	loadlvl2();
	loadlvl3();
	loadlvl4();

	white(); //change color of text
	pre_text();
	intro_text();

begin:
	reset();

	entity player; //creates a player variable of class type enitity
	int time = 0; //Initialise time
	cursor_on_xy(0, 0); //Set cursor on beginning of window

	bool men = true;
	while (men == true) //while in menu
	{
		bool slct = true;
		int m_y = 1, m_x = 18, max = 5, min = 1, menu_pos = 0; //set the positions of the menu
		//m_y and m_x are the coordinates of the arrow for the menu
		//max and min are to restrict the arrow from going further than the top and bottom option
		main_men(); //print the menu
		select(m_x, m_y, slct, menu_pos, min, max); //go into "menu mode"
		if (menu_pos == 0) //if player clicks the first option ("play")
		{
			break;
		}
		if (menu_pos == 1)
		{
			bool hscore = true;
			highscore(hscore); //print the highscores
			continue;
		}
		if (menu_pos == 2)
		{
			bool instrm = true;
			instr(instrm); //print the instuctions
			continue;
		}
		if (menu_pos == 3)
		{
			bool crdts = true;
			credits(crdts); //print credits
			continue;
		}
		else
		{
			exit(0); //if player selects exit then exit the code completely
		}
	}

	system("cls"); //clear console
	levels();
	bool lvlslct = true;
	int m_y = 1, m_x = 18, max = 5, min = 1, menu_pos = 0, lvl = 0;
	//go into "menu" mode
	while (lvlslct)
	{
		bool slct = true;
		select(m_x, m_y, slct, menu_pos, min, max);
		break;
	}

	if (menu_pos == 4) //if player chose to go back to menu
	{
		goto begin; //Go all the way up to the beginning
	}

	diffs(menu_pos, lvl);
	system("cls");

	getPos(lvl, player.y, player.x);

	auto start = chrono::steady_clock::now(); //start the background timer for the game

	if (lvl == 1) //If the user selected level 1
	{
		while (player.x != 33) //while the player is not to the exit position
		{
			char key = keypress(); //define the keypress

			coin(player.y, player.x, lvl); //check for coins
			bool istrap = trap(player.x, player.y, lvl); //check for trap
			if (istrap == true) //if player is on trap then break loop
			{
				break;
			}

			if (key == 'B' && lvl1[player.y + 1][player.x] != '#' && lvl1[player.y + 1][player.x] != '@')
			{
				//if the player presses down key and the according position of the player in level 1 is not a wall (# or @)
				player.px = player.x; player.py = player.y; //set the (before movement) positions to these variables
				player.y++; //change position
				cursor_on_xy(player.x, player.y); cout << "X"; //print the character to the new position
				cursor_on_xy(player.px, player.py); cout << " "; //clear the preivous position
			}
			else if (key == 'U' && lvl1[player.y - 1][player.x] != '#' && lvl1[player.y - 1][player.x] != '@')
			{
				player.px = player.x; player.py = player.y;
				player.y--;
				cursor_on_xy(player.x, player.y); cout << "X";
				cursor_on_xy(player.px, player.py); cout << " ";
			}
			else if (key == 'L' && lvl1[player.y][player.x - 1] != '#' && lvl1[player.y][player.x - 1] != '@')
			{
				player.px = player.x; player.py = player.y;
				player.x--;
				cursor_on_xy(player.x, player.y); cout << "X";
				cursor_on_xy(player.px, player.py); cout << " ";
			}
			else if (key == 'R' && lvl1[player.y][player.x + 1] != '#' && lvl1[player.y][player.x + 1] != '@')
			{
				player.px = player.x; player.py = player.y;
				player.x++;
				cursor_on_xy(player.x, player.y); cout << "X";
				cursor_on_xy(player.px, player.py); cout << " ";
			}
			else if (key == 'Q') //if player presses escape
			{
				break;
			}
			else //do nothing
			{
				player.x = player.x; player.y = player.y;
				player.px = player.px; player.py = player.py;
			}
		}

		auto end = chrono::steady_clock::now(); //stop clock
		bool istrap = trap(player.x, player.y, lvl);
		if (player.x == 33) //if player is on exit
		{
			time = int(chrono::duration_cast <chrono::seconds> (end - start).count()); //store timer time into the variable and make it seconds
			//time = 60; //for testin purposes
			win(time, lvl); //win screen
			goto begin;
		}
		else if (istrap == true) //if player hit a trap
		{
			trap_hit(); //trap hit screen
			goto begin;
		}
		else
		{
			goto begin;
		}
	}
	if (lvl == 2)
	{
		while (player.x != 47)
		{
			char key = keypress();

			coin(player.y, player.x, lvl);;
			bool istrap = trap(player.x, player.y, lvl);
			if (istrap == true)
			{
				break;
			}

			if (key == 'B' && lvl2[player.y + 1][player.x] != '#' && lvl2[player.y + 1][player.x] != '@')
			{
				player.px = player.x; player.py = player.y;
				player.y++;
				cursor_on_xy(player.x, player.y); cout << "X";
				cursor_on_xy(player.px, player.py); cout << " ";
			}
			else if (key == 'U' && lvl2[player.y - 1][player.x] != '#' && lvl2[player.y - 1][player.x] != '@')
			{
				player.px = player.x; player.py = player.y;
				player.y--;
				cursor_on_xy(player.x, player.y); cout << "X";
				cursor_on_xy(player.px, player.py); cout << " ";
			}
			else if (key == 'L' && lvl2[player.y][player.x - 1] != '#' && lvl2[player.y][player.x - 1] != '@')
			{
				player.px = player.x; player.py = player.y;
				player.x--;
				cursor_on_xy(player.x, player.y); cout << "X";
				cursor_on_xy(player.px, player.py); cout << " ";
			}
			else if (key == 'R' && lvl2[player.y][player.x + 1] != '#' && lvl2[player.y][player.x + 1] != '@')
			{
				player.px = player.x; player.py = player.y;
				player.x++;
				cursor_on_xy(player.x, player.y); cout << "X";
				cursor_on_xy(player.px, player.py); cout << " ";
			}
			else if (key == 'Q')
			{
				break;
			}
			else
			{
				player.x = player.x; player.y = player.y;
				player.px = player.px; player.py = player.py;
			}
		}

		auto end = chrono::steady_clock::now();
		bool istrap = trap(player.x, player.y, lvl);
		if (player.x == 47)
		{
			time = int(chrono::duration_cast <chrono::seconds> (end - start).count());
			win(time, lvl);
			goto begin;
		}
		else if (istrap == true)
		{
			trap_hit();
			goto begin;
		}
		else
		{
			goto begin;
		}
	}
	if (lvl == 3)
	{
		while (player.x != 60)
		{
			char key = keypress();

			coin(player.y, player.x, lvl);
			bool istrap = trap(player.x, player.y, lvl);
			if (istrap == true)
			{
				break;
			}

			if (key == 'B' && lvl3[player.y + 1][player.x] != '#' && lvl3[player.y + 1][player.x] != '@')
			{
				player.px = player.x; player.py = player.y;
				player.y++;
				cursor_on_xy(player.x, player.y); cout << "X";
				cursor_on_xy(player.px, player.py); cout << " ";
			}
			else if (key == 'U' && lvl3[player.y - 1][player.x] != '#' && lvl3[player.y - 1][player.x] != '@')
			{
				player.px = player.x; player.py = player.y;
				player.y--;
				cursor_on_xy(player.x, player.y); cout << "X";
				cursor_on_xy(player.px, player.py); cout << " ";
			}
			else if (key == 'L' && lvl3[player.y][player.x - 1] != '#' && lvl3[player.y][player.x - 1] != '@')
			{
				player.px = player.x; player.py = player.y;
				player.x--;
				cursor_on_xy(player.x, player.y); cout << "X";
				cursor_on_xy(player.px, player.py); cout << " ";
			}
			else if (key == 'R' && lvl3[player.y][player.x + 1] != '#' && lvl3[player.y][player.x + 1] != '@')
			{
				player.px = player.x; player.py = player.y;
				player.x++;
				cursor_on_xy(player.x, player.y); cout << "X";
				cursor_on_xy(player.px, player.py); cout << " ";
			}
			else if (key == 'Q')
			{
				break;
			}
			else
			{
				player.x = player.x; player.y = player.y;
				player.px = player.px; player.py = player.py;
			}
		}

		auto end = chrono::steady_clock::now();
		bool istrap = trap(player.x, player.y, lvl);
		if (player.x == 60)
		{
			time = int(chrono::duration_cast <chrono::seconds> (end - start).count());
			win(time, lvl);
			goto begin;
		}
		else if (istrap == true)
		{
			trap_hit();
			goto begin;
		}
		else
		{
			goto begin;
		}
	}
	if (lvl == 4)
	{
		while (player.x != 70)
		{
			char key = keypress();

			coin(player.y, player.x, lvl);
			bool istrap = trap(player.x, player.y, lvl);
			if (istrap == true)
			{
				break;
			}

			if (key == 'B' && lvl4[player.y + 1][player.x] != '#' && lvl4[player.y + 1][player.x] != '@')
			{
				player.px = player.x; player.py = player.y;
				player.y++;
				cursor_on_xy(player.x, player.y); cout << "X";
				cursor_on_xy(player.px, player.py); cout << " ";
			}
			else if (key == 'U' && lvl4[player.y - 1][player.x] != '#' && lvl4[player.y - 1][player.x] != '@')
			{
				player.px = player.x; player.py = player.y;
				player.y--;
				cursor_on_xy(player.x, player.y); cout << "X";
				cursor_on_xy(player.px, player.py); cout << " ";
			}
			else if (key == 'L' && lvl4[player.y][player.x - 1] != '#' && lvl4[player.y][player.x - 1] != '@')
			{
				player.px = player.x; player.py = player.y;
				player.x--;
				cursor_on_xy(player.x, player.y); cout << "X";
				cursor_on_xy(player.px, player.py); cout << " ";
			}
			else if (key == 'R' && lvl4[player.y][player.x + 1] != '#' && lvl4[player.y][player.x + 1] != '@')
			{
				player.px = player.x; player.py = player.y;
				player.x++;
				cursor_on_xy(player.x, player.y); cout << "X";
				cursor_on_xy(player.px, player.py); cout << " ";
			}
			else if (key == 'Q')
			{
				break;
			}
			else
			{
				player.x = player.x; player.y = player.y;
				player.px = player.px; player.py = player.py;
			}
		}

		auto end = chrono::steady_clock::now();
		bool istrap = trap(player.x, player.y, lvl);
		if (player.x == 70)
		{
			time = int(chrono::duration_cast <chrono::seconds> (end - start).count());
			win(time, lvl);
			goto begin;
		}
		else if (istrap == true)
		{
			trap_hit();
			goto begin;
		}
		else
		{
			goto begin;
		}
	}

	return 0;
}

void coin(int y, int x, int level)
{
	//This fucntion checks the position of the character to see if they have collected the coin
	if (level == 1)
	{
		if (y == 5 && x == 6) //if the position of the player is (5,6)
		{
			lvl1[10][6] = ' '; //Make the door "not solid" so the player can go through. Oppening door illusion
			tutor_door(); //Tutorial text
		}
		else if (y == 14 && x == 6)
		{
			lvl1[2][14] = ' ';
		}
		else if (y == 8 && x == 14)
		{
			lvl1[3][20] = ' ';
		}
		else if (y == 3 && x == 18)
		{
			lvl1[13][14] = ' ';
		}
		else if (y == 7 && x == 24)
		{
			lvl1[11][21] = ' ';
		}
		else if (y == 10 && x == 6)
		{
			tutor_unlock();
		}
	}
	else if (level == 2)
	{
		if (y == 3 && x == 33)
		{
			lvl2[8][43] = ' ';
		}
		else if (y == 11 && x == 21)
		{
			lvl2[2][21] = ' ';
		}
		else if (y == 7 && x == 23)
		{
			lvl2[4][11] = ' ';
		}
		else if (y == 9 && x == 46)
		{
			lvl2[4][29] = ' ';
		}
		else if (y == 9 && x == 22)
		{
			lvl2[12][2] = ' ';
		}
		else if (y == 13 && x == 19)
		{
			lvl2[2][11] = ' ';
		}
		else if (y == 13 && x == 7)
		{
			lvl2[12][10] = ' ';
		}
		else if (y == 13 && x == 26)
		{
			lvl2[15][2] = ' ';
		}
		else if (y == 16 && x == 7)
		{
			lvl2[16][45] = ' ';
		}
	}
	else if (level == 3)
	{
		if (y == 18 && x == 14)
		{
			lvl3[16][4] = ' ';
		}
		if (y == 16 && x == 9)
		{
			lvl3[4][10] = ' ';
		}
		if (y == 12 && x == 10)
		{
			lvl3[13][12] = ' ';
		}
		if (y == 3 && x == 27)
		{
			lvl3[17][16] = ' ';
		}
		if (y == 5 && x == 29)
		{
			lvl3[11][18] = ' ';
		}
		if (y == 17 && x == 25)
		{
			lvl3[11][26] = ' ';
		}
		if (y == 12 && x == 29)
		{
			lvl3[17][32] = ' ';
		}
		if (y == 14 && x == 54)
		{
			lvl3[11][24] = ' ';
		}
		if (y == 1 && x == 40)
		{
			lvl3[2][52] = ' ';
		}
		if (y == 13 && x == 45)
		{
			lvl3[16][49] = ' ';
		}
		if (y == 5 && x == 48)
		{
			lvl3[3][59] = ' ';
		}
	}
	else if (level == 4)
	{
		if (y == 13 && x == 25)
		{
			lvl4[8][25] = ' ';
		}
		if (y == 9 && x == 31)
		{
			lvl4[8][18] = ' ';
		}
		if (y == 7 && x == 21)
		{
			lvl4[7][35] = ' ';
		}
		if (y == 14 && x == 38)
		{
			lvl4[4][30] = ' ';
		}
		if (y == 6 && x == 41)
		{
			lvl4[7][45] = ' ';
		}
		if (y == 1 && x == 16)
		{
			lvl4[4][5] = ' ';
		}
		if (y == 19 && x == 7)
		{
			lvl4[4][7] = ' ';
		}
		if (y == 6 && x == 5)
		{
			lvl4[11][8] = ' ';
		}
		if (y == 14 && x == 9)
		{
			lvl4[17][17] = ' ';
		}
		if (y == 16 && x == 29)
		{
			lvl4[9][38] = ' ';
		}
		if (y == 11 && x == 48)
		{
			lvl4[16][31] = ' ';
		}
		if (y == 18 && x == 39)
		{
			lvl4[4][48] = ' ';
		}
		if (y == 3 && x == 52)
		{
			lvl4[17][43] = ' ';
		}
		if (y == 19 && x == 46)
		{
			lvl4[13][53] = ' ';
		}
		if (y == 13 && x == 49)
		{
			lvl4[16][66] = ' ';
		}
		if (y == 17 && x == 61)
		{
			lvl4[4][63] = ' ';
		}
		if (y == 13 && x == 59)
		{
			lvl4[17][69] = ' ';
		}
	}
}

void reset()
{
	//This function resets all the doors back to solid

	lvl1[10][6] = '#';
	lvl1[2][14] = '#';
	lvl1[3][20] = '#';
	lvl1[13][14] = '#';
	lvl1[11][21] = '#';

	lvl2[8][43] = '#';
	lvl2[2][21] = '#';
	lvl2[4][11] = '#';
	lvl2[4][29] = '#';
	lvl2[12][2] = '#';
	lvl2[2][11] = '#';
	lvl2[12][10] = '#';
	lvl2[15][2] = '#';
	lvl2[16][45] = '#';

	lvl3[16][4] = '#';
	lvl3[4][10] = '#';
	lvl3[13][12] = '#';
	lvl3[17][16] = '#';
	lvl3[11][18] = '#';
	lvl3[11][26] = '#';
	lvl3[17][32] = '#';
	lvl3[11][24] = '#';
	lvl3[2][52] = '#';
	lvl3[16][49] = '#';
	lvl3[3][59] = '#';

	lvl4[8][25] = '#';
	lvl4[8][18] = '#';
	lvl4[7][35] = '#';
	lvl4[4][30] = '#';
	lvl4[7][45] = '#';
	lvl4[4][5] = '#';
	lvl4[4][7] = '#';
	lvl4[11][8] = '#';
	lvl4[17][17] = '#';
	lvl4[9][38] = '#';
	lvl4[16][31] = '#';
	lvl4[4][48] = '#';
	lvl4[17][43] = '#';
	lvl4[13][53] = '#';
	lvl4[16][66] = '#';
	lvl4[4][63] = '#';
	lvl4[17][69] = '#';
}

//End