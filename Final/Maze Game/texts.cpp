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

//vectors

vector<int> score_lvl1;
vector<int> score_lvl2;
vector<int> score_lvl3;
vector<int> score_lvl4;

//The following functions take use of the slow function defined in features.cpp to create a cinematic effect
void pre_text()
{
	//String definitions
	string pls = "For the optimal game experience:";
	string one = "Maximize your window";
	string space = "Press 'Space' to continue";

	//Uses the slow fucntions to create cinematic efect
	slow(pls); slow(one); Sleep(1000); slow(space); space_char();
}

void intro_text()
{
	string name = "Welcome to a-mazin";
	string hope = "Hope you enjoy the game!";
	string copy = "Copyrights owned by Andreas Paridis";

	system("cls");

	slow(name); slow(hope); cout << endl; slow(copy);  Sleep(3000);
}

void main_men()
{
	//Pre defined strings to be printed out
	string menu = "Main Menu:";
	string op1 = "  i. Play";
	string hs = " ii. Highscores";
	string op2 = "iii. Instructions";
	string op3 = " iv. Credits";
	string op4 = "  v. Exit";

	system("cls"); //clears console screen

	//Uses the slow function to print out each option
	slow(menu); slow(op1); slow(hs); slow(op2); slow(op3); slow(op4);

	cout << endl << endl << endl;
	//I didnt use the slow function here as it created a very big load time for the menu
	cout << "Navigate the menu using the up and down arrow keys" << endl;
	cout << "Use the 'ESC' key to go back" << endl;
	cout << "Use the 'ENTER' key to select" << endl;
}

//The following also incorporate the escape function used in features.cpp for the menu navigation
void instr(bool instr_menu)
{
	while (instr_menu)
	{
		string cntrls = "Controls:";
		string one = "   i. Use the arrow or w/a/s/d keys to move";
		string two = "  ii. During a level press the 'ESC' key to quit to the main menu";
		string instr = "Game Instrictions";
		string three = "   i. Check the chests($) layed out on the map to find keys";
		string four = "  ii. Use those keys to unlock the doors(#).";
		string five = " iii. Each key can only unlock a specific door";
		string six = "  iv. Use the keys and find your way through the maze";
		string seven = "   v.Watch out for traps! Not all chests contain a key!";
		string eight = "  vi. Find your way through the maze, to the exit";

		system("cls");

		slow(cntrls); slow(one); slow(two); slow(instr); slow(three); slow(four); slow(five); slow(six); slow(seven); slow(eight);

		esc_char(); //The escape function

		break;
	}
}

void credits(bool cred)
{
	while (cred)
	{
		//pre defined strings
		string madeby = "Made by Andreas Paridis";
		string user = "vj017877";
		string uni = "University of reading";
		string lang = "This program was made in C++";
		string mod = "This was the final project of the programming module";

		system("cls"); //clearns console screen

		//Uses slow function to print the strings
		slow(madeby); slow(user); slow(uni); slow(lang); slow(mod);

		esc_char(); //Escape character

		break; //Only proceeds to this piece of code if ESC is pressed
	}
}

void highscore(bool hscore)
{
	//This fucntion displays the highscores of each level
	while (hscore)
	{
		string lvl1 = "Level 1 Higschore: ";
		string lvl2 = "Level 2 Higschore: ";
		string lvl3 = "Level 3 Higschore: ";
		string lvl4 = "Level 4 Higschore: ";
		string no = "N/A";

		system("cls"); //clears the console screen

		if (score_lvl1.empty()) //Checks the vector having the time if its emty
		{
			slow_noln(lvl1); slow(no); //then it displays a N/A
		}
		else if (!score_lvl1.empty()) //If it is not empty
		{
			int h1 = score_lvl1[0]; //Take the time(seconds) from the vector to split it into
			int min = h1 / 60; //Minues
			int hour = min / 60; //hours
			int sec = h1 % 60; //Seconds
			slow_noln(lvl1); cout << hour << ":" << min << ":" << sec << endl; //displays is in hh:mm:ss format
		}
		if (score_lvl2.empty())
		{
			slow_noln(lvl2); slow(no);
		}
		else if (!score_lvl2.empty())
		{
			int h2 = score_lvl2[0];
			int min = h2 / 60;
			int hour = min / 60;
			int sec = h2 % 60;
			slow_noln(lvl2); cout << hour << ":" << min << ":" << sec << endl;
		}
		if (score_lvl3.empty())
		{
			slow_noln(lvl3); slow(no);
		}
		else if (!score_lvl3.empty())
		{
			int h3 = score_lvl3[0];
			int min = h3 / 60;
			int hour = min / 60;
			int sec = h3 % 60;
			slow_noln(lvl3); cout << hour << ":" << min << ":" << sec << endl;
		}
		if (score_lvl4.empty())
		{
			slow_noln(lvl4); slow(no);
		}
		else if (!score_lvl4.empty())
		{
			int h4 = score_lvl4[0];
			int min = h4 / 60;
			int hour = min / 60;
			int sec = h4 % 60;
			slow_noln(lvl4); cout << hour << ":" << min << ":" << sec << endl;
		}
		esc_char();
		break;
	}
}

void levels()
{
	string pls = "Please chose your level";
	string one = "Level 1";
	string two = "Level 2";
	string three = "Level 3";
	string four = "Level 4";
	string exit = "< Main Menu";

	slow(pls); slow(one); slow(two); slow(three); slow(four); slow(exit);
}

void diffs(int pos, int& level)
{
	//Uses the position of the cursor to determine the level chosen by the user
	if (pos == 0) //If the position is 0 (top)
	{
		level = 1; //Set level to 1
		cursor_on_xy(0, 7); //Put cursor below the menu text
		string one = "You chose level 1";
		slow(one);
	}
	else if (pos == 1)
	{
		level = 2;
		cursor_on_xy(0, 7);
		string two = "You chose level 2";
		slow(two);
	}
	else if (pos == 2)
	{
		level = 3;
		cursor_on_xy(0, 7);
		string three = "You chose level 3";
		slow(three);
	}
	else if (pos == 3)
	{
		level = 4;
		cursor_on_xy(0, 7);
		string four = "You chose level 4";
		slow(four);
	}

	string glhf = "Good luck Have Fun";
	slow(glhf);

	Sleep(2000);
}

void win(int seconds, int level)
{
	//This is winning screen
	string win = "Congratulations! You have completed the level!";
	string time = "Time Elapsed: ";
	string back = "Press 'Enter' to continue to the main menu";

	//Split the time into minutes, hours and seconds
	int min = seconds / 60;
	int hour = min / 60;
	int sec = seconds % 60;

	system("cls"); //clears screen
	green(); //changes text color
	slow(win); //prints string
	white(); //changes text color
	slow_noln(time); //same as slow but without a new line in the end
	cout << hour << ":" << min << ":" << sec << endl;
	check(seconds, level);

	slow(back);
	enter_char(); //escape character
}

void trap_hit()
{
	//This is the trap hit screen
	string ded = "YOU DIED";
	string cause = "It was a trap! Remember not all chests contain a key!";
	string back = "<-- Press enter to go to the main menu";

	system("cls"); //clear screen
	red(); //change font color
	slow(ded); //print string
	white(); //change font color
	slow(cause); //print string
	slow(back); //print string
	enter_char(); //escape character
}

void tutor_door()
{
	//This is the tutorial text for level 1
	cursor_on_xy(35, 0);
	cout << "You have oppened a chest($) and found a key.";

	cursor_on_xy(35, 1);
	cout << "Each key can unlock a specific door(#).";

	cursor_on_xy(35, 2);
	cout << "Not all chests contain keys.";

	cursor_on_xy(35, 3);
	cout << "Find the door it unlocks and watch out for traps!!!!";
}

void tutor_unlock()
{
	//Tutorail text for lvl 1
	cursor_on_xy(35, 5);
	cout << "You have unlocked the door using your key.";
}

//HIGHSCORE STORE HANDLING FUNCTION
void check(int time, int level)
{
	//Predefined strings

	//new score
	string newscore = "Your new best time is ";
	string minand = " minute and ";
	string minsand = " minutes and ";
	string snd = " second";
	string snds = " seconds";

	//new highscore
	string beat = "You beat your previous best score by ";

	//away from beating previous highscore
	string you = "You were ";
	string away = " away from passing your previous high score";

	//same score
	string same = "You tied your previous high score!";

	bool first = false;

	if (level == 1) //If level 1
	{
		//Split time into
		int min = time / 60; //minutes
		int hour = min / 60; //hours
		int sec = time % 60; //seconds

		if (score_lvl1.empty()) //if lvl1 vector containing the time is empty
		{
			if (time >= 60) //And the time achieved by the player is more than 60 seconds
			{
				if (min == 1 && sec == 1)
				{
					//if minutes and secodns are singular print second isteand of seconds and minutes instead of minutes
					slow_noln(newscore); cout << min; slow_noln(minand); cout << sec; slow(snd);
				}
				else if (min == 1 && sec != 1) //if minutes are singular and seconds are not print only minutes singlular
				{
					slow_noln(newscore); cout << min; slow_noln(minand); cout << sec; slow(snds);
				}
				else if (min != 1 && sec == 1) //if seconds are singular and minutes are not print only seconds singlular
				{
					slow_noln(newscore); cout << min; slow_noln(minsand); cout << sec; slow(snd);
				}
				else //if botch are not singlular
				{
					slow_noln(newscore); cout << min; slow_noln(minsand); cout << sec; slow(snds);
				}
			}
			else //if the time is less than 60
			{
				if (sec == 1) //if the second is 1 then
				{
					slow_noln(newscore); cout << sec; slow(snd);
				}
				else // if second isnt singular
				{
					slow_noln(newscore); cout << sec; slow(snds);
				}
			}
			score_lvl1.push_back(time); //Push the time into the vector
			savelvl1(time); //Store it into the external file
			first = true;
		}

		if (score_lvl1.size() != 0) //If is not empty
		{
			if (time != score_lvl1[0])
			{
				if (time < score_lvl1[0]) //and the new time achieved is bigger than the old saved
				{
					//Store difference between the new time and the old time
					int difference = score_lvl1[0] - time;

					//Split it into min hours seconds
					int diffmin = difference / 60;
					int diffhour = diffmin / 60;
					int diffsec = difference % 60;

					if (difference > 60) //if the difference is bigger than 60
					{
						//uses the same instances as before to differenciate minute form minutes etc
						if (diffmin == 1 && diffsec == 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minand); cout << diffsec; slow(snd);
						}
						else if (min == 1 && sec != 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minand); cout << diffsec; slow(snds);
						}
						else if (min != 1 && sec == 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minsand); cout << diffsec; slow(snd);
						}
						else
						{
							slow_noln(beat); cout << diffmin; slow_noln(minsand); cout << diffsec; slow(snds);
						}
					}
					else
					{
						if (diffsec == 1)
						{
							slow_noln(beat); cout << diffsec; slow(snd);
						}
						else
						{
							slow_noln(beat); cout << diffsec; slow(snds);
						}
					}
					score_lvl1.clear(); //clears the vector
					score_lvl1.push_back(time); //Store the new time
					savelvl1(time); //Save it into the file
				}
				if (time > score_lvl1[0]) //If the new time is more than the previous best
				{
					int difference = score_lvl1[0] - time; difference = difference * (-1); //store the difference (times by -1 to make it possitvie)

					//split it into min hour seconds
					int diffmin = difference / 60;
					int diffhour = diffmin / 60;
					int diffsec = difference % 60;

					if (difference > 60) //Uses the same instances as above
					{
						if (diffmin == 1 && diffsec == 1)
						{
							slow_noln(you); cout << diffmin; slow_noln(minand); cout << diffsec; slow_noln(snd); slow(away);
						}
						else if (diffmin == 1 && diffsec > 1)
						{
							slow_noln(you); cout << diffmin; slow_noln(minand); cout << diffsec; slow_noln(snd); slow(away);
						}
						else if (min != 1 && sec == 1)
						{
							slow_noln(you); cout << diffmin; slow_noln(minsand); cout << diffsec; slow_noln(snd); slow(away);
						}
						else
						{
							slow_noln(you); cout << diffmin; slow_noln(minsand); cout << diffsec; slow_noln(snds); slow(away);
						}
					}
					else
					{
						if (diffsec == 1)
						{
							slow_noln(you); cout << diffsec; slow_noln(snd); slow(away);
						}
						else
						{
							slow_noln(you); cout << diffsec; slow_noln(snds); slow(away);
						}
					}
				}
			}
			else if (time = score_lvl1[0] && first == false)
			{
				slow(same);
			}
		}
	}
	if (level == 2) //same for each level but the file and vector changes
	{
		int min = time / 60;
		int hour = min / 60;
		int sec = time % 60;

		first = false;
		if (score_lvl2.empty())
		{
			if (time >= 60)
			{
				if (min == 1 && sec == 1)
				{
					slow_noln(newscore); cout << min; slow_noln(minand); cout << sec; slow(snd);
				}
				else if (min == 1 && sec != 1)
				{
					slow_noln(newscore); cout << min; slow_noln(minand); cout << sec; slow(snds);
				}
				else if (min != 1 && sec == 1)
				{
					slow_noln(newscore); cout << min; slow_noln(minsand); cout << sec; slow(snd);
				}
				else
				{
					slow_noln(newscore); cout << min; slow_noln(minsand); cout << sec; slow(snds);
				}
			}
			else
			{
				if (sec == 1)
				{
					slow_noln(newscore); cout << sec; slow(snd);
				}
				else
				{
					slow_noln(newscore); cout << sec; slow(snds);
				}
			}
			score_lvl2.push_back(time);
			savelvl2(time);
			first = true;
		}

		if (score_lvl2.size() != 0)
		{
			if (time != score_lvl2[0])
			{
				if (time < score_lvl2[0])
				{
					int difference = score_lvl2[0] - time;

					int diffmin = difference / 60;
					int diffhour = diffmin / 60;
					int diffsec = difference % 60;

					if (difference > 60)
					{
						if (diffmin == 1 && diffsec == 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minand); cout << diffsec; slow(snd);
						}
						else if (min == 1 && sec != 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minand); cout << diffsec; slow(snds);
						}
						else if (min != 1 && sec == 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minsand); cout << diffsec; slow(snd);
						}
						else
						{
							slow_noln(beat); cout << diffmin; slow_noln(minsand); cout << diffsec; slow(snds);
						}
					}
					else
					{
						if (diffsec == 1)
						{
							slow_noln(beat); cout << diffsec; slow(snd);
						}
						else
						{
							slow_noln(beat); cout << diffsec; slow(snds);
						}
					}
					score_lvl2.clear();
					score_lvl2.push_back(time);
					savelvl2(time);
				}
				if (time > score_lvl2[0])
				{
					int difference = score_lvl2[0] - time; difference = difference * (-1);

					int diffmin = difference / 60;
					int diffhour = diffmin / 60;
					int diffsec = difference % 60;

					if (difference > 60) //if the difference is bigger than 60
					{
						//uses the same instances as before to differenciate minute form minutes etc
						if (diffmin == 1 && diffsec == 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minand); cout << diffsec; slow(snd);
						}
						else if (min == 1 && sec != 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minand); cout << diffsec; slow(snds);
						}
						else if (min != 1 && sec == 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minsand); cout << diffsec; slow(snd);
						}
						else
						{
							slow_noln(beat); cout << diffmin; slow_noln(minsand); cout << diffsec; slow(snds);
						}
					}
					else
					{
						if (diffsec == 1)
						{
							slow_noln(you); cout << diffsec; slow_noln(snd); slow(away);
						}
						else
						{
							slow_noln(you); cout << diffsec; slow_noln(snds); slow(away);
						}
					}
				}
			}
			else if (time = score_lvl1[0] && first == false)
			{
				slow(same);
			}
		}
	}
	if (level == 3)
	{
		int min = time / 60;
		int hour = min / 60;
		int sec = time % 60;

		first = false;
		if (score_lvl3.empty())
		{
			if (time >= 60)
			{
				if (min == 1 && sec == 1)
				{
					slow_noln(newscore); cout << min; slow_noln(minand); cout << sec; slow(snd);
				}
				else if (min == 1 && sec != 1)
				{
					slow_noln(newscore); cout << min; slow_noln(minand); cout << sec; slow(snds);
				}
				else if (min != 1 && sec == 1)
				{
					slow_noln(newscore); cout << min; slow_noln(minsand); cout << sec; slow(snd);
				}
				else
				{
					slow_noln(newscore); cout << min; slow_noln(minsand); cout << sec; slow(snds);
				}
			}
			else
			{
				if (sec == 1)
				{
					slow_noln(newscore); cout << sec; slow(snd);
				}
				else
				{
					slow_noln(newscore); cout << sec; slow(snds);
				}
			}
			score_lvl3.push_back(time);
			savelvl3(time);
			first = true;
		}

		if (score_lvl3.size() != 0)
		{
			if (time != score_lvl3[0])
			{
				if (time < score_lvl3[0])
				{
					int difference = score_lvl3[0] - time;

					int diffmin = difference / 60;
					int diffhour = diffmin / 60;
					int diffsec = difference % 60;

					if (difference > 60)
					{
						if (diffmin == 1 && diffsec == 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minand); cout << diffsec; slow(snd);
						}
						else if (min == 1 && sec != 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minand); cout << diffsec; slow(snds);
						}
						else if (min != 1 && sec == 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minsand); cout << diffsec; slow(snd);
						}
						else
						{
							slow_noln(beat); cout << diffmin; slow_noln(minsand); cout << diffsec; slow(snds);
						}
					}
					else
					{
						if (diffsec == 1)
						{
							slow_noln(beat); cout << diffsec; slow(snd);
						}
						else
						{
							slow_noln(beat); cout << diffsec; slow(snds);
						}
					}
					score_lvl3.clear();
					score_lvl3.push_back(time);
					savelvl3(time);
				}
				if (time > score_lvl3[0])
				{
					int difference = score_lvl3[0] - time; difference = difference * (-1);

					int diffmin = difference / 60;
					int diffhour = diffmin / 60;
					int diffsec = difference % 60;

					if (difference > 60) //if the difference is bigger than 60
					{
						//uses the same instances as before to differenciate minute form minutes etc
						if (diffmin == 1 && diffsec == 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minand); cout << diffsec; slow(snd);
						}
						else if (min == 1 && sec != 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minand); cout << diffsec; slow(snds);
						}
						else if (min != 1 && sec == 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minsand); cout << diffsec; slow(snd);
						}
						else
						{
							slow_noln(beat); cout << diffmin; slow_noln(minsand); cout << diffsec; slow(snds);
						}
					}
					else
					{
						if (diffsec == 1)
						{
							slow_noln(you); cout << diffsec; slow_noln(snd); slow(away);
						}
						else
						{
							slow_noln(you); cout << diffsec; slow_noln(snds); slow(away);
						}
					}
				}
			}
			else if (time = score_lvl1[0] && first == false)
			{
				slow(same);
			}
		}
	}
	if (level == 4)
	{
		int min = time / 60;
		int hour = min / 60;
		int sec = time % 60;

		first = false;
		if (score_lvl4.empty())
		{
			if (time >= 60)
			{
				if (min == 1 && sec == 1)
				{
					slow_noln(newscore); cout << min; slow_noln(minand); cout << sec; slow(snd);
				}
				else if (min == 1 && sec != 1)
				{
					slow_noln(newscore); cout << min; slow_noln(minand); cout << sec; slow(snds);
				}
				else if (min != 1 && sec == 1)
				{
					slow_noln(newscore); cout << min; slow_noln(minsand); cout << sec; slow(snd);
				}
				else
				{
					slow_noln(newscore); cout << min; slow_noln(minsand); cout << sec; slow(snds);
				}
			}
			else
			{
				if (sec == 1)
				{
					slow_noln(newscore); cout << sec; slow(snd);
				}
				else
				{
					slow_noln(newscore); cout << sec; slow(snds);
				}
			}
			score_lvl4.push_back(time);
			savelvl4(time);
			first = true;
		}

		if (score_lvl4.size() != 0)
		{
			if (time != score_lvl4[0])
			{
				if (time < score_lvl4[0])
				{
					int difference = score_lvl4[0] - time;

					int diffmin = difference / 60;
					int diffhour = diffmin / 60;
					int diffsec = difference % 60;

					if (difference > 60)
					{
						if (diffmin == 1 && diffsec == 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minand); cout << diffsec; slow(snd);
						}
						else if (min == 1 && sec != 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minand); cout << diffsec; slow(snds);
						}
						else if (min != 1 && sec == 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minsand); cout << diffsec; slow(snd);
						}
						else
						{
							slow_noln(beat); cout << diffmin; slow_noln(minsand); cout << diffsec; slow(snds);
						}
					}
					else
					{
						if (diffsec == 1)
						{
							slow_noln(beat); cout << diffsec; slow(snd);
						}
						else
						{
							slow_noln(beat); cout << diffsec; slow(snds);
						}
					}
					score_lvl4.clear();
					score_lvl4.push_back(time);
					savelvl4(time);
				}
				if (time > score_lvl4[0])
				{
					int difference = score_lvl4[0] - time; difference = difference * (-1);

					int diffmin = difference / 60;
					int diffhour = diffmin / 60;
					int diffsec = difference % 60;

					if (difference > 60) //if the difference is bigger than 60
					{
						//uses the same instances as before to differenciate minute form minutes etc
						if (diffmin == 1 && diffsec == 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minand); cout << diffsec; slow(snd);
						}
						else if (min == 1 && sec != 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minand); cout << diffsec; slow(snds);
						}
						else if (min != 1 && sec == 1)
						{
							slow_noln(beat); cout << diffmin; slow_noln(minsand); cout << diffsec; slow(snd);
						}
						else
						{
							slow_noln(beat); cout << diffmin; slow_noln(minsand); cout << diffsec; slow(snds);
						}
					}
					else
					{
						if (diffsec == 1)
						{
							slow_noln(you); cout << diffsec; slow_noln(snd); slow(away);
						}
						else
						{
							slow_noln(you); cout << diffsec; slow_noln(snds); slow(away);
						}
					}
				}
			}
			else if (time = score_lvl1[0] && first == false)
			{
				slow(same);
			}
		}
	}
}

//Load time from file to vector
void loadlvl1()
{
	ifstream file; //File for reading

	int score;
	file.open("lvl1.txt"); //Opens the file
	while (file >> score) //Stores the number into the score variable
	{
		score_lvl1.push_back(score); //Store it into the vector
	}
	file.close();
}

void loadlvl2()
{
	ifstream file;

	int score;
	file.open("lvl2.txt");
	while (file >> score)
	{
		score_lvl2.push_back(score);
	}
	file.close();
}

void loadlvl3()
{
	ifstream file;

	int score;
	file.open("lvl3.txt");
	while (file >> score)
	{
		score_lvl3.push_back(score);
	}
	file.close();
}

void loadlvl4()
{
	ifstream file;

	int score;
	file.open("lvl4.txt");
	while (file >> score)
	{
		score_lvl4.push_back(score);
	}
	file.close();
}

//Saves new best time into file overwriting the old
void savelvl1(int time)
{
	ofstream file("lvl1.txt"); //file for writing
	if (file.is_open()) //if the file is open
	{
		file << time; //store the time
		file.close(); //close the file
	}
	else cout << "Unable to open file";
}

void savelvl2(int time)
{
	ofstream file("lvl2.txt");
	if (file.is_open())
	{
		file << time;
		file.close();
	}
	else cout << "Unable to open file";
}

void savelvl3(int time)
{
	ofstream file("lvl3.txt");
	if (file.is_open())
	{
		file << time;
		file.close();
	}
	else cout << "Unable to open file";
}

void savelvl4(int time)
{
	ofstream file("lvl4.txt");
	if (file.is_open())
	{
		file << time;
		file.close();
	}
	else cout << "Unable to open file";
}
//end.