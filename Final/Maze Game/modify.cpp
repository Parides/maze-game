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

//Takes advantage of the windows.h library and all its functions
//Defines the console
HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
//Defines the cursor
HANDLE curs = GetStdHandle(STD_OUTPUT_HANDLE);

//The next functions change the color of the console to their according ascii color
void red()
{
	SetConsoleTextAttribute(myconsole, 12);
}

void green()
{
	SetConsoleTextAttribute(myconsole, 10);
}

void yellow()
{
	SetConsoleTextAttribute(myconsole, 14);
}

void white()
{
	SetConsoleTextAttribute(myconsole, 15);
}

void blue()
{
	SetConsoleTextAttribute(myconsole, 9);
}

//Changes the width and height of the console window
void SetWindow(int Width, int Height)
{
	//Using stucts for Weight and height for buffer
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	//Using strcut for border sizes (window size)
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	SetConsoleScreenBufferSize(myconsole, coord); // Set Buffer Size
	SetConsoleWindowInfo(myconsole, TRUE, &Rect); // Set Window Size
}

//Changes console font
void SetFont()
{
	CONSOLE_FONT_INFOEX console_font;
	console_font.cbSize = sizeof(console_font);
	console_font.nFont = 0;
	console_font.dwFontSize.X = 0; // Width of character in the font
	console_font.dwFontSize.Y = 32; // Height of character in the font
	console_font.FontFamily = FF_DONTCARE;
	console_font.FontWeight = FW_NORMAL;
	std::wcscpy(console_font.FaceName, L"MS Gothic"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &console_font);
}

void cursor_on_xy(int x, int y)
{
	//This function places the console "cursor" where the set coordinates are.
	//This is used so we can acess easier asingle position of the array and use it to print the entity.
	COORD pos = { x, y }; //declares pos (x,y) for the curor so it can be used by the SetConsoleCursorPosition
	SetConsoleCursorPosition(curs, pos); //Changes position of the cursor
}

void slow(string example)
{
	//This makes it so each character of a string is printed out one by one with a small delay to create a cinematic effect
	//Going though each letter with a for loop and usage of Sleep (windows.h) function to create artificial cinematic effect
	for (auto ch : example)
	{
		cout << ch;
		Sleep(15);
	} cout << endl;
}

void slow_noln(string example)
{
	//The same as above but without adding a line in the end
	for (auto ch : example)
	{
		cout << ch;
		Sleep(15);
	}
}

//end